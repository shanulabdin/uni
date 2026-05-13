# WHACK A MOLE - Explanations

This file contains the explanations and comments from the `whack_a_mole.c` source code.

---

## Game Overview

```
 * ============================================
 *   WHACK A MOLE - Terminal Game in C
 *   Name: [Your Name]
 *   Roll No: [Your Roll No]
 *   Subject: OEL - Semester 1
 * ============================================
```

### CONCEPTS USED (for viva):
  1. 2D Arrays        - to store the 6x6 grid
  2. Functions        - displayGrid(), generateMole(), checkGuess()
  3. Loops            - for loop to run 10 rounds, nested loops for grid
  4. Conditionals     - if/else to check hit or miss
  5. Random Numbers   - rand() and srand() to place mole randomly
  6. User Input       - scanf() to get row and column from player

---

## Code Details

### Constants
`#define` lets us set fixed values without using variables.
- `ROWS` and `COLS` define the grid size.
- `ROUNDS` is how many turns the player gets.

### Global Variables
These are declared outside functions so every function can access them without passing them as parameters.
- `grid[][]` is our 6x6 playing board.
- `moleRow` and `moleCol` store where the mole is hiding.

---

## Function Explanations

### `clearGrid()`
- **PURPOSE**: Fills every cell in the grid with `.` (empty).
- **CONCEPT**: Nested for loops + 2D array indexing.
- **VIVA TIP**: "I use a nested loop - outer loop for rows, inner loop for columns."

### `generateMole()`
- **PURPOSE**: Picks a random row and column, places 'M' there.
- **CONCEPT**: `rand() % N` gives a number from 0 to N-1.
- **VIVA TIP**: "`srand(time(NULL))` seeds the random number generator so we get different numbers each run."

### `displayGrid()`
- **PURPOSE**: Prints the grid to the terminal.
- **CONCEPT**: Nested loops + `printf` formatting.
- **NOTE**: We HIDE the mole ('M') from the player. The player has to guess where it is!
- **VIVA TIP**: "I replace 'M' with '?' when printing so the player cannot see where the mole is."

### `checkGuess()`
- **PURPOSE**: Compares player's guess with mole's real position.
- **RETURNS**: 1 if correct (hit), 0 if wrong (miss).
- **CONCEPT**: `if/else` + comparing `int` values.
- **VIVA TIP**: "The function returns 1 for hit and 0 for miss. The return type is `int`, not `void`."

### `revealMole()`
- **PURPOSE**: After a wrong guess, show where the mole was.
- **CONCEPT**: `printf` with stored `moleRow` and `moleCol` values.

### `printResult()`
- **PURPOSE**: Shows final score, hits, and misses at game end.
- **CONCEPT**: Function parameters + simple arithmetic.
- **VIVA TIP**: "`hits + misses` always equals `ROUNDS` (10)."

### `main()`
- **PURPOSE**: Entry point - controls the game loop.
- **CONCEPT**: `for` loop for rounds, calls all other functions.
- **VIVA TIP**: "`main()` is the driver. It calls each function in the right order every round."
