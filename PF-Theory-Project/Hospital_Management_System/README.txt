HOSPITAL PATIENT MANAGEMENT SYSTEM
====================================

FOLDER STRUCTURE:
  hospital_project/
    hospital.c          <- C backend (compile this)
    app.py              <- Flask bridge server
    templates/
      index.html        <- Web dashboard (served by Flask)

HOW TO RUN:
  1. Compile the C program:
       gcc -std=c99 hospital.c -o hospital
     (On Windows: gcc -std=c99 hospital.c -o hospital.exe
      and change C_PROGRAM in app.py if needed)

  2. Install Flask (only once):
       pip install flask

  3. Start the server:
       python app.py

  4. Open your browser to:
       http://127.0.0.1:5000

NOTES:
  - patients.txt is created automatically in the same folder
    once you add your first patient. It stores all records
    in plain text, one patient per line.
  - Names, diseases, and doctor names should not contain
    spaces (the dashboard automatically converts spaces to
    underscores, e.g. "John Doe" becomes "John_Doe").
  - You can also run hospital.c directly from the terminal
    without the web dashboard:
       ./hospital add 101 John_Doe 03001234567 25 Fever Dr_Ali 12 2025-01-15
       ./hospital search 101
       ./hospital update 101 room 20
       ./hospital delete 101
       ./hospital list

UPDATE FIELDS SUPPORTED:
  room, doctor, status, phone, disease
  Example: ./hospital update 101 status Discharged

FOR YOUR PROJECT REPORT:
  - Flowchart: Start -> Load patients.txt into arrays -> Show menu
    (Add/Search/Update/Delete/List) -> Perform array operation ->
    Save arrays back to patients.txt -> End
  - Take screenshots of the dashboard for each of the 4 CRUD
    operations (Add, Search, Update, Delete) plus the Ward
    Overview table.
  - Mention the array-shifting logic used for delete as your
    "advanced" technique (no library functions needed).
