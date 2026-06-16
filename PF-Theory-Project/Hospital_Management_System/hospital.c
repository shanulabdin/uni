/*
    Hospital Patient Database Engine
    ---------------------------------
    A beginner-level C program using ONLY parallel arrays (no structs).
    Data is stored in patients.txt and reloaded every time the program runs.

    How it talks to the web frontend:
    The Flask script calls this compiled program from the command line,
    like:  ./hospital add 101 John 03001234567 25 Fever DrAli 12 2025-01-15
    argv[1] tells us WHICH action to perform (add/search/update/delete/list).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

/* ---------- The 9 Parallel Arrays ---------- */
int  patient_ids[MAX];
char names[MAX][50];
char phones[MAX][20];
int  ages[MAX];
char diseases[MAX][50];
char doctors[MAX][50];
int  room_numbers[MAX];
char admission_dates[MAX][20];
char statuses[MAX][20];
int  total_records = 0;

/* ---------- Function Declarations ---------- */
void loadData();
void saveData();
void addPatient(int argc, char *argv[]);
void searchPatient(char *idStr);
void updatePatient(int argc, char *argv[]);
void deletePatient(char *idStr);
void listPatients();

/* ============================================================
   LOAD DATA FROM FILE
   Every time the program starts, we open patients.txt and read
   each line into our arrays. Since we DON'T use structs, every
   single field gets its own array, and we fill them one row at
   a time using a basic loop and fscanf.
   ============================================================ */
void loadData() {
    FILE *fp = fopen("patients.txt", "r");

    /* If the file doesn't exist yet (first run), there is
       nothing to load. total_records stays 0. */
    if (fp == NULL) {
        return;
    }

    int i = 0;
    while (feof(fp) == 0) {
        int id, age, room;
        char name[50], phone[20], disease[50], doctor[50], date[20], status[20];

        /* fscanf reads 9 space-separated values from one line.
           %s automatically stops at whitespace, so names/dates
           should NOT contain spaces (use underscores instead,
           e.g. John_Doe). This keeps things simple for beginners. */
        int result = fscanf(fp, "%d %s %s %d %s %s %d %s %s",
                             &id, name, phone, &age, disease, doctor,
                             &room, date, status);

        /* If fscanf could not read all 9 values, we have probably
           hit a blank line or the end of the file, so we stop. */
        if (result != 9) {
            break;
        }

        patient_ids[i]      = id;
        strcpy(names[i], name);
        strcpy(phones[i], phone);
        ages[i]             = age;
        strcpy(diseases[i], disease);
        strcpy(doctors[i], doctor);
        room_numbers[i]     = room;
        strcpy(admission_dates[i], date);
        strcpy(statuses[i], status);

        i++;
    }

    total_records = i;
    fclose(fp);
}

/* ============================================================
   SAVE DATA TO FILE
   Every time something changes (add/update/delete), we open
   patients.txt in "write" mode, which erases the old content,
   then we write out ALL current records fresh from the arrays.
   This keeps the file always matching what is in memory.
   ============================================================ */
void saveData() {
    FILE *fp = fopen("patients.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open patients.txt for saving.\n");
        return;
    }

    int i;
    for (i = 0; i < total_records; i++) {
        fprintf(fp, "%d %s %s %d %s %s %d %s %s\n",
                patient_ids[i], names[i], phones[i], ages[i],
                diseases[i], doctors[i], room_numbers[i],
                admission_dates[i], statuses[i]);
    }

    fclose(fp);
}

/* ============================================================
   ADD A NEW PATIENT
   Expected command line:
   ./hospital add <id> <name> <phone> <age> <disease> <doctor> <room> <date>
   argc should be 10 (program name + "add" + 8 fields)
   ============================================================ */
void addPatient(int argc, char *argv[]) {
    if (argc < 10) {
        printf("Error: Missing information. Need id, name, phone, age, disease, doctor, room, date.\n");
        return;
    }

    if (total_records >= MAX) {
        printf("Error: Patient list is full (max 100 patients).\n");
        return;
    }

    int newId = atoi(argv[2]);

    /* Check if this ID is already used by looping through the array */
    int i;
    for (i = 0; i < total_records; i++) {
        if (patient_ids[i] == newId) {
            printf("Error: Patient ID %d already exists.\n", newId);
            return;
        }
    }

    /* Add the new patient at the end of every array (at index total_records) */
    patient_ids[total_records] = newId;
    strcpy(names[total_records], argv[3]);
    strcpy(phones[total_records], argv[4]);
    ages[total_records] = atoi(argv[5]);
    strcpy(diseases[total_records], argv[6]);
    strcpy(doctors[total_records], argv[7]);
    room_numbers[total_records] = atoi(argv[8]);
    strcpy(admission_dates[total_records], argv[9]);
    strcpy(statuses[total_records], "Admitted");

    total_records++;
    saveData();

    printf("Success: Patient %d (%s) was admitted.\n", newId, argv[3]);
}

/* ============================================================
   SEARCH FOR A PATIENT
   Expected command line: ./hospital search <id>
   ============================================================ */
void searchPatient(char *idStr) {
    int targetId = atoi(idStr);
    int i;

    for (i = 0; i < total_records; i++) {
        if (patient_ids[i] == targetId) {
            printf("FOUND\n");
            printf("ID:%d\n", patient_ids[i]);
            printf("NAME:%s\n", names[i]);
            printf("PHONE:%s\n", phones[i]);
            printf("AGE:%d\n", ages[i]);
            printf("DISEASE:%s\n", diseases[i]);
            printf("DOCTOR:%s\n", doctors[i]);
            printf("ROOM:%d\n", room_numbers[i]);
            printf("DATE:%s\n", admission_dates[i]);
            printf("STATUS:%s\n", statuses[i]);
            return;
        }
    }

    printf("NOTFOUND\n");
    printf("Error: Patient with ID %d not found.\n", targetId);
}

/* ============================================================
   UPDATE A PATIENT
   Expected command line: ./hospital update <id> <field> <newValue>
   field can be: room, doctor, status, phone, disease
   ============================================================ */
void updatePatient(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Error: Need patient id, field name, and new value.\n");
        return;
    }

    int targetId = atoi(argv[2]);
    char *field = argv[3];
    char *value = argv[4];
    int i;

    for (i = 0; i < total_records; i++) {
        if (patient_ids[i] == targetId) {

            if (strcmp(field, "room") == 0) {
                room_numbers[i] = atoi(value);
            } else if (strcmp(field, "doctor") == 0) {
                strcpy(doctors[i], value);
            } else if (strcmp(field, "status") == 0) {
                strcpy(statuses[i], value);
            } else if (strcmp(field, "phone") == 0) {
                strcpy(phones[i], value);
            } else if (strcmp(field, "disease") == 0) {
                strcpy(diseases[i], value);
            } else {
                printf("Error: '%s' is not a field that can be updated.\n", field);
                return;
            }

            saveData();
            printf("Success: Patient %d updated (%s changed to %s).\n", targetId, field, value);
            return;
        }
    }

    printf("Error: Patient with ID %d not found.\n", targetId);
}

/* ============================================================
   DELETE A PATIENT
   Expected command line: ./hospital delete <id>

   How the shifting works:
   Imagine our arrays look like this (index: value)
        0: 101   1: 102   2: 103   3: 104
   If we want to delete ID 102 (index 1), every record AFTER it
   needs to move one slot to the LEFT, so there is no empty gap:
        0: 101   1: 103   2: 104
   Then we reduce total_records by 1 so the program "forgets"
   about the old last slot.
   ============================================================ */
void deletePatient(char *idStr) {
    int targetId = atoi(idStr);
    int i, j;
    int found = -1;

    /* Step 1: find the index of the patient to delete */
    for (i = 0; i < total_records; i++) {
        if (patient_ids[i] == targetId) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Error: Patient with ID %d not found.\n", targetId);
        return;
    }

    /* Step 2: shift every record after "found" one position left,
       for ALL nine arrays at the same time so nothing gets mixed up */
    for (j = found; j < total_records - 1; j++) {
        patient_ids[j] = patient_ids[j + 1];
        strcpy(names[j], names[j + 1]);
        strcpy(phones[j], phones[j + 1]);
        ages[j] = ages[j + 1];
        strcpy(diseases[j], diseases[j + 1]);
        strcpy(doctors[j], doctors[j + 1]);
        room_numbers[j] = room_numbers[j + 1];
        strcpy(admission_dates[j], admission_dates[j + 1]);
        strcpy(statuses[j], statuses[j + 1]);
    }

    /* Step 3: shrink the record count and save the clean list */
    total_records--;
    saveData();

    printf("Success: Patient %d was discharged and removed.\n", targetId);
}

/* ============================================================
   LIST ALL PATIENTS
   Expected command line: ./hospital list
   Prints every record, one line per patient.
   ============================================================ */
void listPatients() {
    if (total_records == 0) {
        printf("No patients in the system yet.\n");
        return;
    }

    int i;
    for (i = 0; i < total_records; i++) {
        printf("ID:%d|NAME:%s|PHONE:%s|AGE:%d|DISEASE:%s|DOCTOR:%s|ROOM:%d|DATE:%s|STATUS:%s\n",
               patient_ids[i], names[i], phones[i], ages[i],
               diseases[i], doctors[i], room_numbers[i],
               admission_dates[i], statuses[i]);
    }
}

/* ============================================================
   MAIN FUNCTION
   Reads argv[1] to decide which operation to run.
   ============================================================ */
int main(int argc, char *argv[]) {

    /* Always load whatever is currently saved before doing anything */
    loadData();

    if (argc < 2) {
        printf("Error: No action specified. Use add, search, update, delete, or list.\n");
        return 0;
    }

    if (strcmp(argv[1], "add") == 0) {
        addPatient(argc, argv);
    }
    else if (strcmp(argv[1], "search") == 0) {
        if (argc < 3) {
            printf("Error: Please provide a patient ID to search.\n");
        } else {
            searchPatient(argv[2]);
        }
    }
    else if (strcmp(argv[1], "update") == 0) {
        updatePatient(argc, argv);
    }
    else if (strcmp(argv[1], "delete") == 0) {
        if (argc < 3) {
            printf("Error: Please provide a patient ID to delete.\n");
        } else {
            deletePatient(argv[2]);
        }
    }
    else if (strcmp(argv[1], "list") == 0) {
        listPatients();
    }
    else {
        printf("Error: Unknown action '%s'.\n", argv[1]);
    }

    return 0;
}
