/*
 * ============================================
 *   WHACK A MOLE - Terminal Game in C
 *   Name: [Your Name]
 *   Roll No: [Your Roll No]
 *   Subject: OEL - Semester 1
 * ============================================
 *
 * CONCEPTS USED (for viva):
 *   1. 2D Arrays        - to store the 6x6 grid
 *   2. Functions        - displayGrid(), generateMole(), checkGuess()
 *   3. Loops            - for loop to run 10 rounds, nested loops for grid
 *   4. Conditionals     - if/else to check hit or miss
 *   5. Random Numbers   - rand() and srand() to place mole randomly
 *   6. User Input       - scanf() to get row and column from player
 */

#include <stdio.h>
#include <stdlib.h>   /* for rand() and srand() */
#include <time.h>     /* for time() - used to seed random numbers */

/* ── Constants ──────────────────────────────────────────────
   #define lets us set fixed values without using variables.
   ROWS and COLS define the grid size.
   ROUNDS is how many turns the player gets.
*/
#define ROWS   6
#define COLS   6
#define ROUNDS 10

/* ── Global Variables ───────────────────────────────────────
   These are declared outside functions so every function
   can access them without passing them as parameters.
   grid[][] is our 6x6 playing board.
   moleRow and moleCol store where the mole is hiding.
*/
char grid[ROWS][COLS];
int  moleRow, moleCol;

/* ============================================================
   FUNCTION: clearGrid()
   PURPOSE : Fills every cell in the grid with '.' (empty)
   CONCEPT : Nested for loops + 2D array indexing
   VIVA TIP: "I use a nested loop - outer loop for rows,
              inner loop for columns."
   ============================================================ */
void clearGrid()
{
    int r, c;
    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            grid[r][c] = '.';   /* '.' means this cell is empty */
        }
    }
}

/* ============================================================
   FUNCTION: generateMole()
   PURPOSE : Picks a random row and column, places 'M' there
   CONCEPT : rand() % N gives a number from 0 to N-1
   VIVA TIP: "srand(time(NULL)) seeds the random number
              generator so we get different numbers each run."
   ============================================================ */
void generateMole()
{
    /* rand() % ROWS gives 0..5, so mole stays inside the grid */
    moleRow = rand() % ROWS;
    moleCol = rand() % COLS;

    /* Place the mole character in the grid */
    grid[moleRow][moleCol] = 'M';
}

/* ============================================================
   FUNCTION: displayGrid()
   PURPOSE : Prints the grid to the terminal
   CONCEPT : Nested loops + printf formatting
   NOTE    : We HIDE the mole ('M') from the player.
             The player has to guess where it is!
   VIVA TIP: "I replace 'M' with '?' when printing so the
              player cannot see where the mole is."
   ============================================================ */
void displayGrid()
{
    int r, c;

    printf("\n    ");
    /* Print column numbers across the top */
    for (c = 0; c < COLS; c++)
    {
        printf("  %d", c + 1);  /* +1 so display is 1-6, not 0-5 */
    }
    printf("\n");

    /* Print a separator line */
    printf("    +--+--+--+--+--+--+\n");

    for (r = 0; r < ROWS; r++)
    {
        printf("  %d |", r + 1);   /* Row number on the left */

        for (c = 0; c < COLS; c++)
        {
            /* If this cell has the mole, show '?' to hide it */
            if (grid[r][c] == 'M')
                printf(" ?|");
            else
                printf(" %c|", grid[r][c]);
        }
        printf("\n");
        printf("    +--+--+--+--+--+--+\n");
    }
    printf("\n");
}

/* ============================================================
   FUNCTION: checkGuess()
   PURPOSE : Compares player's guess with mole's real position
   RETURNS : 1 if correct (hit), 0 if wrong (miss)
   CONCEPT : if/else + comparing int values
   VIVA TIP: "The function returns 1 for hit and 0 for miss.
              The return type is int, not void."
   ============================================================ */
int checkGuess(int guessRow, int guessCol)
{
    /* Convert player input (1-6) to array index (0-5) */
    int r = guessRow - 1;
    int c = guessCol  - 1;

    if (r == moleRow && c == moleCol)
    {
        return 1;   /* Correct! */
    }
    else
    {
        return 0;   /* Wrong guess */
    }
}

/* ============================================================
   FUNCTION: revealMole()
   PURPOSE : After a wrong guess, show where the mole was
   CONCEPT : printf with stored moleRow and moleCol values
   ============================================================ */
void revealMole()
{
    /* +1 to convert 0-based index back to 1-based for display */
    printf("  The mole was hiding at Row %d, Column %d!\n",
           moleRow + 1, moleCol + 1);
}

/* ============================================================
   FUNCTION: printResult()
   PURPOSE : Shows final score, hits, and misses at game end
   CONCEPT : Function parameters + simple arithmetic
   VIVA TIP: "hits + misses always equals ROUNDS (10)."
   ============================================================ */
void printResult(int hits, int misses, int score)
{
    printf("\n");
    printf("  =========================================\n");
    printf("           GAME OVER! FINAL RESULTS        \n");
    printf("  =========================================\n");
    printf("  Total Rounds  : %d\n", ROUNDS);
    printf("  Moles Whacked : %d\n", hits);
    printf("  Misses        : %d\n", misses);
    printf("  Final Score   : %d / %d\n", score, ROUNDS * 10);
    printf("  =========================================\n");

    /* Give a message based on score */
    if (score == ROUNDS * 10)
        printf("  PERFECT! You whacked every mole!\n");
    else if (score >= 70)
        printf("  Great job! You are a mole hunter!\n");
    else if (score >= 40)
        printf("  Good effort! Keep practising.\n");
    else
        printf("  Better luck next time!\n");

    printf("  =========================================\n\n");
}

/* ============================================================
   FUNCTION: main()
   PURPOSE : Entry point - controls the game loop
   CONCEPT : for loop for rounds, calls all other functions
   VIVA TIP: "main() is the driver. It calls each function
              in the right order every round."
   ============================================================ */
int main()
{
    int round, guessRow, guessCol;
    int result;
    int hits   = 0;   /* counts correct guesses */
    int misses = 0;   /* counts wrong guesses   */
    int score  = 0;   /* total score            */

    /* Seed the random number generator once at program start.
       time(NULL) returns current time - different every run,
       so mole appears in a different spot each game.         */
    srand(time(NULL));

    /* Welcome banner */
    printf("\n");
    printf("  =========================================\n");
    printf("         WELCOME TO WHACK-A-MOLE!          \n");
    printf("  =========================================\n");
    printf("  A mole (M) hides in the 6x6 grid.\n");
    printf("  Guess its row and column to whack it!\n");
    printf("  Score +10 for each correct guess.\n");
    printf("  You have %d rounds. Good luck!\n", ROUNDS);
    printf("  =========================================\n\n");

    /* ── Main Game Loop ─────────────────────────────────────
       Runs exactly ROUNDS (10) times.
       Each iteration = one full round of the game.
    */
    for (round = 1; round <= ROUNDS; round++)
    {
        printf(" - \n");
        printf("  Round %d of %d   |   Score: %d\n",
               round, ROUNDS, score);
        printf(" - \n");

        /* Step 1: Reset the grid to all dots */
        clearGrid();

        /* Step 2: Place the mole randomly */
        generateMole();

        /* Step 3: Show the grid to the player (mole is hidden) */
        displayGrid();

        /* Step 4: Ask the player for their guess */
        printf("  Where is the mole hiding?\n");

        /* Input validation loop - keeps asking until valid input */
        do {
            printf("  Enter Row    (1 to 6): ");
            scanf("%d", &guessRow);
        } while (guessRow < 1 || guessRow > 6);

        do {
            printf("  Enter Column (1 to 6): ");
            scanf("%d", &guessCol);
        } while (guessCol < 1 || guessCol > 6);

        /* Step 5: Check if guess is correct */
        result = checkGuess(guessRow, guessCol);

        if (result == 1)
        {
            /* Hit! */
            score += 10;
            hits++;
            printf("\n  *** WHACK! You got the mole! +10 points ***\n");
        }
        else
        {
            /* Miss */
            misses++;
            printf("\n  You missed! The mole escaped.\n");
            revealMole();
        }

        printf("  Score after Round %d: %d\n\n", round, score);
    }

    /* ── Game Over ──────────────────────────────────────────
       All rounds finished - show the final results.
    */
    printResult(hits, misses, score);

    return 0;   /* 0 means the program ended successfully */
}
