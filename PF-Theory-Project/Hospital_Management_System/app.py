"""
Flask Bridge Server
--------------------
This small Python script sits between the HTML/CSS frontend and the
compiled C program (./hospital).

What it does:
1. Receives form data from the web dashboard (Add / Search / Update / Delete / List).
2. Builds a list of command-line arguments matching what hospital.c expects.
3. Runs the compiled C program using subprocess and captures its text output.
4. Sends that output back to the frontend as JSON, so JavaScript can show it nicely.

Before running this file:
    gcc -std=c99 hospital.c -o hospital
    pip install flask
    python app.py
Then open: http://127.0.0.1:5000
"""

from flask import Flask, request, jsonify, render_template
import subprocess
import os

app = Flask(__name__)

# Path to the compiled C program.
# On Windows this would be "hospital.exe", on Mac/Linux it is "./hospital"
C_PROGRAM = "./hospital" if os.name != "nt" else "hospital.exe"


def run_c_program(args_list):
    """
    Runs the compiled C program with the given list of arguments
    and returns whatever it printed to the console as a string.
    """
    try:
        result = subprocess.run(
            [C_PROGRAM] + args_list,
            capture_output=True,
            text=True,
            timeout=5
        )
        # Combine normal output and error output (if any)
        output = result.stdout.strip()
        if result.stderr.strip():
            output += "\n" + result.stderr.strip()
        return output
    except FileNotFoundError:
        return "Error: Compiled program 'hospital' not found. Run: gcc -std=c99 hospital.c -o hospital"
    except Exception as e:
        return "Error: " + str(e)


@app.route("/")
def home():
    """Serves the main dashboard page."""
    return render_template("index.html")


@app.route("/add", methods=["POST"])
def add_patient():
    """
    Expects form fields: id, name, phone, age, disease, doctor, room, date
    Calls: ./hospital add <id> <name> <phone> <age> <disease> <doctor> <room> <date>
    """
    data = request.form

    # Spaces are not allowed by our simple C parser, so we replace
    # them with underscores (e.g. "John Doe" -> "John_Doe")
    args = [
        "add",
        data.get("id", "0"),
        data.get("name", "Unknown").replace(" ", "_"),
        data.get("phone", "0"),
        data.get("age", "0"),
        data.get("disease", "Unknown").replace(" ", "_"),
        data.get("doctor", "Unknown").replace(" ", "_"),
        data.get("room", "0"),
        data.get("date", "0000-00-00"),
    ]

    output = run_c_program(args)
    return jsonify({"output": output})


@app.route("/search", methods=["POST"])
def search_patient():
    """
    Expects form field: id
    Calls: ./hospital search <id>
    """
    data = request.form
    args = ["search", data.get("id", "0")]
    output = run_c_program(args)
    return jsonify({"output": output})


@app.route("/update", methods=["POST"])
def update_patient():
    """
    Expects form fields: id, field, value
    field must be one of: room, doctor, status, phone, disease
    Calls: ./hospital update <id> <field> <value>
    """
    data = request.form
    args = [
        "update",
        data.get("id", "0"),
        data.get("field", "status"),
        data.get("value", "").replace(" ", "_"),
    ]
    output = run_c_program(args)
    return jsonify({"output": output})


@app.route("/delete", methods=["POST"])
def delete_patient():
    """
    Expects form field: id
    Calls: ./hospital delete <id>
    """
    data = request.form
    args = ["delete", data.get("id", "0")]
    output = run_c_program(args)
    return jsonify({"output": output})


@app.route("/list", methods=["GET"])
def list_patients():
    """
    Calls: ./hospital list
    Returns the raw pipe-separated lines; the frontend JS turns
    these into a nice table.
    """
    output = run_c_program(["list"])
    return jsonify({"output": output})


if __name__ == "__main__":
    app.run(debug=True, port=5000)
