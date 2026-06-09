/*
 * ============================================================
 *  ATM SIMULATOR — Programming Fundamentals Lab (CMC111)
 *  Language : C (C99/C11)
 *  Author   : Muhammad Shan Ul Abdin  |  IU02-0126-0212
 *  Instructor: Mehreen Kanwal
 * ============================================================
 *
 *  KEY CONCEPTS USED (for viva reference)
 *  --------------------------------------------------------------
 *  1. PARALLEL ARRAYS  – Five separate arrays (usernames, pins,
 *     balances, transactions, transaction_counts) share the same
 *     index to represent one "user record" without using structs.
 *
 *  2. 2D ARRAY  – transactions[5][10] stores up to 10 transaction
 *     amounts per user. Row = user index, Column = transaction slot.
 *
 *  3. POINTERS  – deposit() and withdraw() receive float* and int*
 *     arguments so they can modify the original arrays directly,
 *     not a local copy.
 *
 *  4. RECURSION – searchTransaction() calls itself, shrinking the
 *     search range by one on every call until it finds the target
 *     or exhausts the history (base case: current_index >= count).
 *
 *  5. LOOPS     – while() drives the login gate and the main menu;
 *     for() iterates over users and transaction lists.
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ── Constants ─────────────────────────────────────────────── */
#define MAX_USERS  5
#define MAX_TX     10      /* max transactions stored per user  */

/* ── Function Prototypes ────────────────────────────────────── */

/* UI / display */
void printHeader(void);
void printDivider(void);
void printMainMenu(void);
void clearBuffer(void);

/* Auth */
int  loginUser(char usernames[][20], int pins[], int max);

/* Core banking logic — note pointer parameters */
void checkBalance(float balances[], int user_index);
void deposit(float *balance, float transactions[][MAX_TX],
             int *tx_count, int user_index);
void withdraw(float *balance, float transactions[][MAX_TX],
              int *tx_count, int user_index);
void showHistory(float transactions[][MAX_TX],
                 int tx_count, int user_index);
void changePin(int pins[], int user_index);

/* Utility */
void recordTransaction(float transactions[][MAX_TX],
                       int *tx_count, int user_index, float amount);

/*
 * RECURSIVE SEARCH — required by specification.
 *
 * How it works:
 *   Base case 1 : current_index >= count  → not found, return -1
 *   Base case 2 : transactions[user_index][current_index] == target
 *                 → found, return current_index
 *   Recursive   : call self with current_index + 1
 */
int searchTransaction(float transactions[][MAX_TX], int user_index,
                      int count, float target, int current_index);

/* ── Main ───────────────────────────────────────────────────── */
int main(void)
{
    /*
     * DATABASE — parallel arrays.
     * Index 0 in every array belongs to the same user.
     * No structs needed; the shared index IS the record link.
     */
    char  usernames[MAX_USERS][20] = {
        "alice", "bob", "charlie", "diana", "eve"
    };
    int   pins[MAX_USERS]          = { 1111, 2222, 3333, 4444, 5555 };
    float balances[MAX_USERS]      = { 5000.0f, 12000.0f,
                                       3500.0f,  8800.0f, 250.0f };

    /*
     * 2D ARRAY — transactions[user][slot].
     * Positive value = deposit, negative value = withdrawal.
     * Pre-loaded with some history for demo purposes.
     */
    float transactions[MAX_USERS][MAX_TX] = {
        {  500.0f, -200.0f,  300.0f, 0,0,0,0,0,0,0 },  /* alice   */
        { 1000.0f, -500.0f,    0,    0,0,0,0,0,0,0 },  /* bob     */
        {  200.0f,    0,       0,    0,0,0,0,0,0,0 },  /* charlie */
        {  800.0f, -100.0f, -50.0f,  0,0,0,0,0,0,0 },  /* diana   */
        {  100.0f,    0,       0,    0,0,0,0,0,0,0 }   /* eve     */
    };

    /* How many transactions each user already has in history */
    int transaction_counts[MAX_USERS] = { 3, 2, 1, 3, 1 };

    int  logged_in_user = -1;   /* index of authenticated user  */
    int  choice;                /* menu selection               */

    printHeader();

    /* ── Outer loop: keeps returning to login after logout ── */
    while (1)
    {
        logged_in_user = loginUser(usernames, pins, MAX_USERS);

        if (logged_in_user == -1)
        {
            printf("\n  Account locked. Exiting.\n");
            break;
        }

        printf("\n  Welcome, %s!\n", usernames[logged_in_user]);

        /* ── Inner loop: main menu for logged-in user ──────── */
        while (1)
        {
            printMainMenu();
            printf("  Enter choice: ");
            if (scanf("%d", &choice) != 1) choice = -1;
            clearBuffer();   /* flush leftover newline / junk  */

            switch (choice)
            {
                case 1:
                    checkBalance(balances, logged_in_user);
                    break;

                case 2:
                    /*
                     * POINTER USAGE:
                     * &balances[logged_in_user] passes the address of
                     * this user's balance cell so withdraw() can modify
                     * the original array value, not a local copy.
                     * Same pattern for transaction_counts.
                     */
                    withdraw(&balances[logged_in_user],
                             transactions,
                             &transaction_counts[logged_in_user],
                             logged_in_user);
                    break;

                case 3:
                    deposit(&balances[logged_in_user],
                            transactions,
                            &transaction_counts[logged_in_user],
                            logged_in_user);
                    break;

                case 4:
                    showHistory(transactions,
                                transaction_counts[logged_in_user],
                                logged_in_user);
                    break;

                case 5:
                    changePin(pins, logged_in_user);
                    break;

                case 6:
                    printf("\n  Logged out. Goodbye, %s!\n\n",
                           usernames[logged_in_user]);
                    goto next_login;   /* break inner, re-enter outer */

                default:
                    printf("\n  Invalid option. Try again.\n");
            }
        }
        next_login:;   /* label for the goto above */
    }

    printf("\n  Thank you for using the ATM. Goodbye!\n");
    return 0;
}

/* ═══════════════════════════════════════════════════════════
 *  UI / DISPLAY FUNCTIONS
 * ═══════════════════════════════════════════════════════════ */

void printHeader(void)
{
    printf("\n");
    printf("   ...................................  \n");
    printf("  |        C-BANK  ATM  v1.0         |  \n");
    printf("  |         PF Lab  CMC111           |  \n");
    printf("   ...................................  \n");
}

void printDivider(void)
{
    printf("   ...................................  \n");
}

void printMainMenu(void)
{
    printf("\n");
    printDivider();
    printf("  [1] Check Balance\n");
    printf("  [2] Withdraw\n");
    printf("  [3] Deposit\n");
    printf("  [4] Transaction History\n");
    printf("  [5] Change PIN\n");
    printf("  [6] Logout\n");
    printDivider();
}

/*
 * clearBuffer — flushes everything left in stdin after a scanf.
 * Without this, a stray '\n' would be read by the next scanf and
 * cause menus to skip or behave erratically.
 */
void clearBuffer(void)
{
    while (getchar() != '\n');
}

/* ═══════════════════════════════════════════════════════════
 *  AUTH — LOGIN
 * ═══════════════════════════════════════════════════════════ */

int loginUser(char usernames[][20], int pins[], int max)
{
    char  input_name[20];
    int   input_pin;
    int   attempts = 0;
    int   i;

    printf("\n");
    printDivider();

    /* Allow up to 3 login attempts */
    while (attempts < 3)
    {
        printf("  Username: ");
        scanf("%19s", input_name);
        clearBuffer();

        printf("  PIN     : ");
        if (scanf("%d", &input_pin) != 1)
        {
            clearBuffer();
            printf("  Invalid PIN format.\n\n");
            attempts++;
            continue;
        }
        clearBuffer();

        /* Linear search through username array */
        for (i = 0; i < max; i++)
        {
            if (strcmp(usernames[i], input_name) == 0 &&
                pins[i] == input_pin)
            {
                return i;   /* authentication successful */
            }
        }

        attempts++;
        printf("  Incorrect credentials. Attempt %d/3.\n\n", attempts);
    }

    return -1;   /* all attempts exhausted */
}

/* ═══════════════════════════════════════════════════════════
 *  BANKING FUNCTIONS
 * ═══════════════════════════════════════════════════════════ */

void checkBalance(float balances[], int user_index)
{
    printDivider();
    printf("  Current Balance:  PKR %.2f\n", balances[user_index]);
    printDivider();
}

/* ── DEPOSIT ──────────────────────────────────────────────────
 * Parameters:
 *   float *balance   — pointer to this user's cell in balances[].
 *                      Using *balance = *balance + amount modifies
 *                      the original array directly.
 *   int   *tx_count  — pointer to transaction_counts[user_index].
 *                      Incrementing *tx_count updates the real counter.
 */
void deposit(float *balance, float transactions[][MAX_TX],
             int *tx_count, int user_index)
{
    float amount;

    printDivider();
    printf("  Enter deposit amount: PKR ");
    if (scanf("%f", &amount) != 1) { clearBuffer(); return; }
    clearBuffer();

    if (amount <= 0.0f)
    {
        printf("  Error: Amount must be positive.\n");
        return;
    }

    *balance += amount;   /* dereference pointer to update original */
    recordTransaction(transactions, tx_count, user_index, amount);

    printf("  Deposited PKR %.2f successfully.\n", amount);
    printf("  New Balance: PKR %.2f\n", *balance);
    printDivider();
}

/* ── WITHDRAW ─────────────────────────────────────────────────
 * Negative amount is stored so history shows cash-out at a glance.
 */
void withdraw(float *balance, float transactions[][MAX_TX],
              int *tx_count, int user_index)
{
    float amount;

    printDivider();
    printf("  Enter withdrawal amount: PKR ");
    if (scanf("%f", &amount) != 1) { clearBuffer(); return; }
    clearBuffer();

    if (amount <= 0.0f)
    {
        printf("  Error: Amount must be positive.\n");
        return;
    }
    if (amount > *balance)
    {
        printf("  Error: Insufficient funds. Balance: PKR %.2f\n",
               *balance);
        return;
    }

    *balance -= amount;
    recordTransaction(transactions, tx_count, user_index, -amount);

    printf("  Withdrawn PKR %.2f successfully.\n", amount);
    printf("  New Balance: PKR %.2f\n", *balance);
    printDivider();
}

/* ═══════════════════════════════════════════════════════════
 *  recordTransaction
 *  Adds 'amount' to the user's transaction row.
 *
 *  OVERFLOW HANDLING — shift strategy:
 *  If the slot is full (tx_count == MAX_TX), shift all entries
 *  left by one (oldest is discarded) and write the new entry at
 *  the last position, keeping the count at MAX_TX.
 * ═══════════════════════════════════════════════════════════ */
void recordTransaction(float transactions[][MAX_TX],
                       int *tx_count, int user_index, float amount)
{
    int i;

    if (*tx_count < MAX_TX)
    {
        /*
         * 2D ARRAY ACCESS:
         * transactions[user_index][*tx_count] targets the next
         * empty column in this user's row.
         */
        transactions[user_index][*tx_count] = amount;
        (*tx_count)++;   /* update the real counter via pointer */
    }
    else
    {
        /* Shift left: index 0 is dropped, oldest first */
        for (i = 0; i < MAX_TX - 1; i++)
        {
            transactions[user_index][i] = transactions[user_index][i + 1];
        }
        transactions[user_index][MAX_TX - 1] = amount;
        /* tx_count stays at MAX_TX — no increment needed */
    }
}

/* ═══════════════════════════════════════════════════════════
 *  showHistory
 *  Lists every transaction for the active user and then
 *  demonstrates the recursive search by asking for a target.
 * ═══════════════════════════════════════════════════════════ */
void showHistory(float transactions[][MAX_TX],
                 int tx_count, int user_index)
{
    int   i, result;
    float target;

    printDivider();
    printf("  Transaction History (last %d recorded):\n\n", tx_count);

    if (tx_count == 0)
    {
        printf("  No transactions yet.\n");
    }
    else
    {
        for (i = 0; i < tx_count; i++)
        {
            if (transactions[user_index][i] >= 0)
                printf("  [%d]  + PKR %.2f  (deposit)\n",
                       i + 1, transactions[user_index][i]);
            else
                printf("  [%d]  - PKR %.2f  (withdrawal)\n",
                       i + 1, -transactions[user_index][i]);
        }

        /* ── Demonstrate recursive search ───────────────── */
        printf("\n  Search a transaction amount (e.g. 500): PKR ");
        if (scanf("%f", &target) != 1) { clearBuffer(); return; }
        clearBuffer();

        /*
         * RECURSIVE CALL:
         * Start at index 0. The function will keep calling itself
         * with current_index + 1 until it finds 'target' or
         * reaches tx_count (base case → return -1).
         */
        result = searchTransaction(transactions, user_index,
                                   tx_count, target, 0);

        if (result == -1)
            printf("  Amount PKR %.2f not found in history.\n", target);
        else
            printf("  Found PKR %.2f at transaction slot [%d].\n",
                   target, result + 1);
    }

    printDivider();
}

/* ═══════════════════════════════════════════════════════════
 *  RECURSIVE FUNCTION — searchTransaction
 *
 *  Purpose : Search transactions[user_index][0..count-1] for
 *            a value equal to 'target'.
 *
 *  Base cases:
 *    1. current_index >= count  → exhausted, return -1
 *    2. value matches target    → return current_index
 *
 *  Recursive case:
 *    Neither base case hit → call self with current_index + 1.
 *    Each call works on a smaller sub-array (one fewer element).
 *
 *  Call stack example (user has 3 tx: [500, -200, 300], target=300):
 *    search(..., 3, 300.0, 0) → 500 != 300 → recurse
 *    search(..., 3, 300.0, 1) → -200 != 300 → recurse
 *    search(..., 3, 300.0, 2) → 300 == 300  → return 2
 * ═══════════════════════════════════════════════════════════ */
int searchTransaction(float transactions[][MAX_TX], int user_index,
                      int count, float target, int current_index)
{
    /* Base case 1: walked past the end without a match */
    if (current_index >= count)
        return -1;

    /* Base case 2: current slot matches target */
    if (transactions[user_index][current_index] == target)
        return current_index;

    /* Recursive case: check the next slot */
    return searchTransaction(transactions, user_index,
                             count, target, current_index + 1);
}

/* ═══════════════════════════════════════════════════════════
 *  changePin
 * ═══════════════════════════════════════════════════════════ */
void changePin(int pins[], int user_index)
{
    int current, new_pin, confirm;

    printDivider();
    printf("  Current PIN  : ");
    if (scanf("%d", &current) != 1) { clearBuffer(); return; }
    clearBuffer();

    if (current != pins[user_index])
    {
        printf("  Incorrect PIN. Change cancelled.\n");
        return;
    }

    printf("  New PIN      : ");
    if (scanf("%d", &new_pin) != 1) { clearBuffer(); return; }
    clearBuffer();

    printf("  Confirm PIN  : ");
    if (scanf("%d", &confirm) != 1) { clearBuffer(); return; }
    clearBuffer();

    if (new_pin != confirm)
    {
        printf("  PINs do not match. Change cancelled.\n");
        return;
    }
    if (new_pin < 1000 || new_pin > 9999)
    {
        printf("  PIN must be a 4-digit number.\n");
        return;
    }

    pins[user_index] = new_pin;
    printf("  PIN changed successfully.\n");
    printDivider();
}
