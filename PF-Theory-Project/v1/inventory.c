/* =====================================================================
   INVENTORY DATABASE ENGINE (Pure C99, Beginner Style)
   =====================================================================
   - No structs, no malloc, no fancy functions.
   - Data is stored in 4 "parallel arrays" -> item at index i has its
     ID in item_ids[i], its name in item_names[i], its supplier in
     manufacturers[i], and its stock count in quantities[i].
   - Everything is saved to / loaded from "database.txt" as plain text.
   - The program is run from the command line like this:
       ./inventory add 101 Laptop DellInc 15
       ./inventory search 101
       ./inventory update 101 Laptop HPInc 20
       ./inventory delete 101
   ===================================================================== */

#include <stdio.h>
#include <stdlib.h>   /* only used for atoi() to turn "101" into 101 */
#include <string.h>   /* only used for strcmp() and strcpy() */

#define MAX_RECORDS 100
#define NAME_LEN 50
#define FILENAME "database.txt"

/* ---------------------------------------------------------------
   GLOBAL PARALLEL ARRAYS
   These hold ALL the inventory data while the program is running.
   --------------------------------------------------------------- */
int item_ids[MAX_RECORDS];
char item_names[MAX_RECORDS][NAME_LEN];
char manufacturers[MAX_RECORDS][NAME_LEN];
int quantities[MAX_RECORDS];
int total_records = 0;   /* how many rows are currently used */


/* ---------------------------------------------------------------
   LOAD DATABASE FROM FILE
   Reads database.txt line by line into the parallel arrays.
   Each line in the file looks like:   101 Laptop DellInc 15
   --------------------------------------------------------------- */
void load_database() {
    FILE *fp;
    int temp_id;
    char temp_name[NAME_LEN];
    char temp_manufacturer[NAME_LEN];
    int temp_qty;

    fp = fopen(FILENAME, "r");

    /* If the file does not exist yet, just start with an empty database */
    if (fp == NULL) {
        total_records = 0;
        return;
    }

    /* Keep reading until we hit the end of the file */
    while (!feof(fp)) {
        /* Try to read one full record (4 values) from the file */
        int items_read = fscanf(fp, "%d %s %s %d", &temp_id, temp_name, temp_manufacturer, &temp_qty);

        /* If fscanf could not fill all 4 values, we reached the end */
        if (items_read != 4) {
            break;
        }

        /* Copy the values we just read into our arrays */
        item_ids[total_records] = temp_id;
        strcpy(item_names[total_records], temp_name);
        strcpy(manufacturers[total_records], temp_manufacturer);
        quantities[total_records] = temp_qty;

        total_records = total_records + 1;
    }

    fclose(fp);
}


/* ---------------------------------------------------------------
   SAVE DATABASE TO FILE
   This OVERWRITES database.txt with whatever is currently in the
   parallel arrays. We call this after every add/update/delete so
   the text file always matches the arrays.
   --------------------------------------------------------------- */
void save_database() {
    FILE *fp;
    int i;

    /* "w" mode wipes the old file and starts fresh */
    fp = fopen(FILENAME, "w");

    if (fp == NULL) {
        printf("ERROR: Could not open database file for writing.\n");
        return;
    }

    /* Write every record, one per line */
    for (i = 0; i < total_records; i++) {
        fprintf(fp, "%d %s %s %d\n", item_ids[i], item_names[i], manufacturers[i], quantities[i]);
    }

    fclose(fp);
}


/* ---------------------------------------------------------------
   FIND THE ARRAY INDEX OF AN ID
   Returns the index (0 to total_records-1) if found, or -1 if not.
   --------------------------------------------------------------- */
int find_index_by_id(int id) {
    int i;
    for (i = 0; i < total_records; i++) {
        if (item_ids[i] == id) {
            return i;
        }
    }
    return -1; /* not found */
}


/* ---------------------------------------------------------------
   CREATE: ADD A NEW ITEM
   --------------------------------------------------------------- */
void add_item(int id, char name[], char manufacturer[], int qty) {

    /* First check the array is not already full */
    if (total_records >= MAX_RECORDS) {
        printf("ERROR: Database is full. Cannot add more items.\n");
        return;
    }

    /* Check if this ID already exists */
    if (find_index_by_id(id) != -1) {
        printf("ERROR: Item ID %d already exists.\n", id);
        return;
    }

    /* Append the new item at the end of the arrays */
    item_ids[total_records] = id;
    strcpy(item_names[total_records], name);
    strcpy(manufacturers[total_records], manufacturer);
    quantities[total_records] = qty;

    total_records = total_records + 1;

    /* Write the updated arrays back to the text file */
    save_database();

    printf("SUCCESS: Item %d added.\n", id);
}


/* ---------------------------------------------------------------
   READ / SEARCH: FIND AN ITEM BY ID
   --------------------------------------------------------------- */
void search_item(int id) {
    int index = find_index_by_id(id);

    if (index == -1) {
        printf("ERROR: Item ID %d not found.\n", id);
        return;
    }

    printf("SUCCESS: Item found.\n");
    printf("ID: %d\n", item_ids[index]);
    printf("Name: %s\n", item_names[index]);
    printf("Manufacturer: %s\n", manufacturers[index]);
    printf("Quantity: %d\n", quantities[index]);
}


/* ---------------------------------------------------------------
   UPDATE: CHANGE NAME / MANUFACTURER / QUANTITY OF AN EXISTING ITEM
   --------------------------------------------------------------- */
void update_item(int id, char name[], char manufacturer[], int qty) {
    int index = find_index_by_id(id);

    if (index == -1) {
        printf("ERROR: Item ID %d not found.\n", id);
        return;
    }

    /* Overwrite the old values with the new ones */
    strcpy(item_names[index], name);
    strcpy(manufacturers[index], manufacturer);
    quantities[index] = qty;

    save_database();

    printf("SUCCESS: Item %d updated.\n", id);
}


/* ---------------------------------------------------------------
   DELETE: REMOVE AN ITEM AND CLOSE THE GAP IN THE ARRAYS
   --------------------------------------------------------------- */
void delete_item(int id) {
    int index = find_index_by_id(id);
    int i;

    if (index == -1) {
        printf("ERROR: Item ID %d not found.\n", id);
        return;
    }

    /* Shift every record after "index" one position to the left,
       so the empty slot at "index" gets covered up. */
    for (i = index; i < total_records - 1; i++) {
        item_ids[i] = item_ids[i + 1];
        strcpy(item_names[i], item_names[i + 1]);
        strcpy(manufacturers[i], manufacturers[i + 1]);
        quantities[i] = quantities[i + 1];
    }

    /* The last slot is now a duplicate, so just reduce the count */
    total_records = total_records - 1;

    save_database();

    printf("SUCCESS: Item %d deleted.\n", id);
}


/* ---------------------------------------------------------------
   MAIN: READS COMMAND LINE ARGUMENTS AND PICKS THE RIGHT ACTION
   --------------------------------------------------------------- */
int main(int argc, char *argv[]) {

    /* Always load the existing data first */
    load_database();

    /* Make sure the user typed an action */
    if (argc < 2) {
        printf("ERROR: No command given. Use add, search, update, or delete.\n");
        return 0;
    }

    /* -------- CREATE -------- */
    if (strcmp(argv[1], "add") == 0) {
        if (argc != 6) {
            printf("ERROR: Usage: add <id> <name> <manufacturer> <quantity>\n");
            return 0;
        }
        add_item(atoi(argv[2]), argv[3], argv[4], atoi(argv[5]));
    }
    /* -------- READ / SEARCH -------- */
    else if (strcmp(argv[1], "search") == 0) {
        if (argc != 3) {
            printf("ERROR: Usage: search <id>\n");
            return 0;
        }
        search_item(atoi(argv[2]));
    }
    /* -------- UPDATE -------- */
    else if (strcmp(argv[1], "update") == 0) {
        if (argc != 6) {
            printf("ERROR: Usage: update <id> <name> <manufacturer> <quantity>\n");
            return 0;
        }
        update_item(atoi(argv[2]), argv[3], argv[4], atoi(argv[5]));
    }
    /* -------- DELETE -------- */
    else if (strcmp(argv[1], "delete") == 0) {
        if (argc != 3) {
            printf("ERROR: Usage: delete <id>\n");
            return 0;
        }
        delete_item(atoi(argv[2]));
    }
    /* -------- UNKNOWN COMMAND -------- */
    else {
        printf("ERROR: Unknown command '%s'. Use add, search, update, or delete.\n", argv[1]);
    }

    return 0;
}
