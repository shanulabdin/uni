#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6
#define ROUNDS 10

char grid[ROWS][COLS];
int moleRow, moleCol;

void clearGrid()
{
    int r, c;
    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            grid[r][c] = '.';
        }
    }
}

void generateMole()
{
    moleRow = rand() % ROWS;
    moleCol = rand() % COLS;

    grid[moleRow][moleCol] = 'O';
}

void displayGrid()
{
    int r, c;

    printf("\n    ");
    for (c = 0; c < COLS; c++)
    {
        printf("  0");
    }
    printf("\n");

    printf("    +--+--+--+--+--+--+\n");

    for (r = 0; r < ROWS; r++)
    {
        printf("  0 |");

        for (c = 0; c < COLS; c++)
        {
            if (grid[r][c] == 'O')
                printf(" O|");
            else
                printf(" %c|", grid[r][c]);
        }
        printf("\n");
        printf("    +--+--+--+--+--+--+\n");
    }
    printf("\n");
}

int checkGuess(int guessRow, int guessCol)
{
    int r = guessRow - 1;
    int c = guessCol - 1;

    if (r == moleRow && c == moleCol)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void revealMole()
{
    printf("  The mole was hiding at Row %d, Column %d!\n",
           moleRow + 1, moleCol + 1);
}

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

int main()
{
    int round, guessRow, guessCol;
    int result;
    int hits = 0;
    int misses = 0;
    int score = 0;

    srand(time(NULL));

    printf("\n");
    printf("  =========================================\n");
    printf("         WELCOME TO WHACK-A-MOLE!          \n");
    printf("  =========================================\n");
    printf("  A mole (M) hides in the 6x6 grid.\n");
    printf("  Guess its row and column to whack it!\n");
    printf("  Score +10 for each correct guess.\n");
    printf("  You have %d rounds. Good luck!\n", ROUNDS);
    printf("  =========================================\n\n");

    for (round = 1; round <= ROUNDS; round++)
    {
        printf("  =========================================\n");
        printf("  Round %d of %d   |   Score: %d\n",
               round, ROUNDS, score);
        printf("  =========================================\n");

        clearGrid();
        generateMole();
        displayGrid();

        printf("  Where is the mole hiding?\n");

        do
        {
            printf("  Enter Row    (1 to 6): ");
            scanf("%d", &guessRow);
        } while (guessRow < 1 || guessRow > 6);

        do
        {
            printf("  Enter Column (1 to 6): ");
            scanf("%d", &guessCol);
        } while (guessCol < 1 || guessCol > 6);

        result = checkGuess(guessRow, guessCol);

        if (result == 1)
        {
            score += 10;
            hits++;
            printf("\n  *** WHACK! You got the mole! +10 points ***\n");
        }
        else
        {
            misses++;
            printf("\n  You missed! The mole escaped.\n");
            revealMole();
        }

        printf("  Score after Round %d: %d\n\n", round, score);
    }

    printResult(hits, misses, score);

    return 0;
}
