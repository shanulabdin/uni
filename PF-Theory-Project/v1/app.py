"""
=====================================================================
 Flask Bridge for the C Inventory Engine
=====================================================================
 This tiny server does ONE job: take input from the web page,
 run the compiled C program ("./inventory") with the right
 command-line arguments, and send the C program's text output
 straight back to the web page.

 The C program itself still does all the real work (CRUD logic,
 reading/writing database.txt). This file is just the "bridge".

 Run with:   python3 app.py
 Then open:  http://127.0.0.1:5000
=====================================================================
"""

from flask import Flask, request, jsonify, send_from_directory
import subprocess
import os

app = Flask(__name__)

# Path to the compiled C binary (must be compiled first: gcc -o inventory inventory.c)
BINARY_PATH = os.path.join(os.path.dirname(os.path.abspath(__file__)), "inventory")


def run_inventory(args):
    """
    Runs the C binary with the given list of arguments, e.g.
        run_inventory(["add", "101", "Laptop", "DellInc", "15"])
    and returns whatever the C program printed to stdout as a string.
    """
    command = [BINARY_PATH] + args

    try:
        result = subprocess.run(
            command,
            capture_output=True,
            text=True,
            timeout=5
        )
        output = result.stdout.strip()

        if output == "":
            output = result.stderr.strip() or "ERROR: No output from program."

        return output

    except FileNotFoundError:
        return "ERROR: Compiled 'inventory' binary not found. Run: gcc -std=c99 -o inventory inventory.c"
    except Exception as e:
        return "ERROR: " + str(e)


# ---------------------------------------------------------------
# Serve the frontend (index.html, style.css) from the same folder
# ---------------------------------------------------------------
@app.route("/")
def home():
    return send_from_directory(".", "index.html")


@app.route("/<path:filename>")
def static_files(filename):
    return send_from_directory(".", filename)


# ---------------------------------------------------------------
# CREATE  ->  add <id> <name> <manufacturer> <quantity>
# ---------------------------------------------------------------
@app.route("/add", methods=["POST"])
def add_item():
    data = request.form

    item_id = data.get("item_id", "")
    name = data.get("item_name", "")
    manufacturer = data.get("manufacturer", "")
    quantity = data.get("quantity", "")

    output = run_inventory(["add", item_id, name, manufacturer, quantity])
    return jsonify({"output": output})


# ---------------------------------------------------------------
# READ / SEARCH  ->  search <id>
# ---------------------------------------------------------------
@app.route("/search", methods=["POST"])
def search_item():
    data = request.form
    item_id = data.get("item_id", "")

    output = run_inventory(["search", item_id])
    return jsonify({"output": output})


# ---------------------------------------------------------------
# UPDATE  ->  update <id> <name> <manufacturer> <quantity>
# ---------------------------------------------------------------
@app.route("/update", methods=["POST"])
def update_item():
    data = request.form

    item_id = data.get("item_id", "")
    name = data.get("item_name", "")
    manufacturer = data.get("manufacturer", "")
    quantity = data.get("quantity", "")

    output = run_inventory(["update", item_id, name, manufacturer, quantity])
    return jsonify({"output": output})


# ---------------------------------------------------------------
# DELETE  ->  delete <id>
# ---------------------------------------------------------------
@app.route("/delete", methods=["POST"])
def delete_item():
    data = request.form
    item_id = data.get("item_id", "")

    output = run_inventory(["delete", item_id])
    return jsonify({"output": output})


if __name__ == "__main__":
    app.run(debug=True, port=5000)
