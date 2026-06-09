#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS  5
#define MAX_TX     10

void printHeader(void);
void printDivider(void);
void printMainMenu(void);

int  loginUser(char usernames[][20], int pins[], int max);

void checkBalance(float balances[], int user_index);
void deposit(float *balance, float transactions[][MAX_TX], int *tx_count, int user_index);
void withdraw(float *balance, float transactions[][MAX_TX], int *tx_count, int user_index);
void showHistory(float transactions[][MAX_TX], int tx_count, int user_index);
void changePin(int pins[], int user_index);
void recordTransaction(float transactions[][MAX_TX], int *tx_count, int user_index, float amount);

int  searchTransaction(float transactions[][MAX_TX], int user_index,
                       int count, float target, int current_index);

int main(void)
{
    char  usernames[MAX_USERS][20]   = { "shan", "waiz", "muneeb", "umer", "saim" };
    int   pins[MAX_USERS]            = { 1111, 2222, 3333, 4444, 5555 };
    float balances[MAX_USERS]        = { 5000.0f, 12000.0f, 3500.0f, 8800.0f, 250.0f };

    float transactions[MAX_USERS][MAX_TX] = {
        {  500.0f, -200.0f,  300.0f, 0,0,0,0,0,0,0 },
        { 1000.0f, -500.0f,    0,    0,0,0,0,0,0,0 },
        {  200.0f,    0,       0,    0,0,0,0,0,0,0 },
        {  800.0f, -100.0f, -50.0f,  0,0,0,0,0,0,0 },
        {  100.0f,    0,       0,    0,0,0,0,0,0,0 }
    };
    int transaction_counts[MAX_USERS] = { 3, 2, 1, 3, 1 };

    int logged_in_user;
    int choice;
    int running = 1;   /* outer loop flag */

    printHeader();

    /* Outer loop — return here after each logout */
    while (running)
    {
    logged_in_user = loginUser(usernames, pins, MAX_USERS);

        if (logged_in_user == -1)
        {
            printf("\n  Too many failed attempts. Goodbye.\n");
            running = 0;
            break;
        }

        printf("\n  Welcome, %s!\n", usernames[logged_in_user]);

        int logged_in = 1;

        while (logged_in)
        {
            printMainMenu();
            printf("  Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    checkBalance(balances, logged_in_user);
                    break;

                case 2:
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
                    logged_in = 0;
                    break;

                default:
                    printf("\n  Invalid option. Please enter 1-6.\n");
            }
        }
    }

    printf("  Thank you for using the ATM!\n");
    return 0;
}

void printHeader(void)
{
    printf("\n");
    printf("  ================================\n");
    printf("         C-BANK  ATM  v1.0        \n");
    printf("  ================================\n");
}

void printDivider(void)
{
    printf("  --------------------------------\n");
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

int loginUser(char usernames[][20], int pins[], int max)
{
    char input_name[20];
    int  input_pin;
    int  attempts = 0;
    int  i;

    printf("\n");
    printDivider();

    while (attempts < 3)
    {
        printf("  Username: ");
        scanf("%s", input_name);

        printf("  PIN     : ");
        scanf("%d", &input_pin);

        for (i = 0; i < max; i++)
        {
            if (strcmp(usernames[i], input_name) == 0 && pins[i] == input_pin)
                return i;
        }

        attempts++;
        printf("  Wrong username or PIN. Attempt %d/3.\n\n", attempts);
    }

    return -1;
}

void checkBalance(float balances[], int user_index)
{
    printDivider();
    printf("  Balance: PKR %.2f\n", balances[user_index]);
    printDivider();
}

void deposit(float *balance, float transactions[][MAX_TX],
             int *tx_count, int user_index)
{
    float amount;

    printDivider();

    amount = 0;
    while (amount <= 0)
    {
        printf("  Deposit amount: PKR ");
        scanf("%f", &amount);

        if (amount <= 0)
            printf("  Amount must be greater than zero. Try again.\n");
    }

    *balance += amount;
    recordTransaction(transactions, tx_count, user_index, amount);

    printf("  Deposited PKR %.2f\n", amount);
    printf("  New Balance: PKR %.2f\n", *balance);
    printDivider();
}


void withdraw(float *balance, float transactions[][MAX_TX],
              int *tx_count, int user_index)
{
    float amount;
    int   valid;

    printDivider();

    valid = 0;
    while (valid == 0)
    {
        printf("  Withdrawal amount: PKR ");
        scanf("%f", &amount);

        if (amount <= 0)
            printf("  Amount must be greater than zero. Try again.\n");
        else if (amount > *balance)
            printf("  Insufficient funds. Balance is PKR %.2f. Try again.\n", *balance);
        else
            valid = 1;
    }

    *balance -= amount;
    recordTransaction(transactions, tx_count, user_index, -amount);

    printf("  Withdrawn PKR %.2f\n", amount);
    printf("  New Balance: PKR %.2f\n", *balance);
    printDivider();
}

void recordTransaction(float transactions[][MAX_TX],
                       int *tx_count, int user_index, float amount)
{
    int i;

    if (*tx_count < MAX_TX)
    {
        transactions[user_index][*tx_count] = amount;
        (*tx_count)++;
    }
    else
    {
        for (i = 0; i < MAX_TX - 1; i++)
            transactions[user_index][i] = transactions[user_index][i + 1];

        transactions[user_index][MAX_TX - 1] = amount;
    }
}

void showHistory(float transactions[][MAX_TX], int tx_count, int user_index)
{
    int   i, result;
    float target;

    printDivider();
    printf("  Transaction History (%d recorded):\n\n", tx_count);

    if (tx_count == 0)
    {
        printf("  No transactions yet.\n");
    }
    else
    {
        for (i = 0; i < tx_count; i++)
        {
            if (transactions[user_index][i] >= 0)
                printf("  [%d]  + PKR %.2f  (deposit)\n",    i + 1,  transactions[user_index][i]);
            else
                printf("  [%d]  - PKR %.2f  (withdrawal)\n", i + 1, -transactions[user_index][i]);
        }

        printf("\n  Search a transaction, enter amount: PKR ");
        scanf("%f", &target);

        result = searchTransaction(transactions, user_index, tx_count, target, 0);

        if (result == -1)
            printf("  PKR %.2f not found in history.\n", target);
        else
            printf("  Found PKR %.2f at slot [%d].\n", target, result + 1);
    }

    printDivider();
}

int searchTransaction(float transactions[][MAX_TX], int user_index,
                      int count, float target, int current_index)
{
    if (current_index >= count)
        return -1;

    if (transactions[user_index][current_index] == target)
        return current_index;

    return searchTransaction(transactions, user_index, count, target, current_index + 1);
}


void changePin(int pins[], int user_index)
{
    int current_pin;
    int new_pin;
    int confirm_pin;

    printDivider();
    printf("  Current PIN: ");
    scanf("%d", &current_pin);

    if (current_pin != pins[user_index])
    {
        printf("  Incorrect PIN. Cancelled.\n");
        return;
    }

    new_pin = 0;
    confirm_pin = -1;
    while (new_pin != confirm_pin)
    {
        printf("  New PIN (4 digits): ");
        scanf("%d", &new_pin);

        printf("  Confirm PIN       : ");
        scanf("%d", &confirm_pin);

        if (new_pin != confirm_pin)
            printf("  PINs do not match. Try again.\n");
    }

    pins[user_index] = new_pin;
    printf("  PIN changed successfully.\n");
    printDivider();
}
