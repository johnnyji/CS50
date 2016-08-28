/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <string.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define BLANK_SPACE 0
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
char * format_board_item(int item, int max);
int get_digits_size(int digit);
int get_max_num(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{

    // Generates the board
    int max = d - 1;
    int number = get_max_num();
    int row_index_tracker = 0;
    int column_index_tracker = 0;

    while (number >= 0)
    {
        // Adds the current item
        board[row_index_tracker][column_index_tracker] = number;
        number--;

        // We're done filling the board
        if (column_index_tracker == max && row_index_tracker == max)
        {
            break;
        }
        // We're onto a new row
        else if (column_index_tracker == max)
        {
            column_index_tracker = 0;
            row_index_tracker++;
        }
        // Still on the same row, need to increase the colum index
        else {
            column_index_tracker++;
        }

    }

    // Flips 1 and 2 if the board dimensions are even
    if (d % 2 == 0)
    {
        int n = sizeof(board) / sizeof(board[0]);
        board[n - 1][n - 1] = 2;
        board[n - 1][n - 2] = 1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{

    // Finds how long the biggest number is, so we can pad the other numbers to make sure
    // that the table wont print malformed
    int max_item_length = get_digits_size(get_max_num());

    for (int row_index = 0; row_index < d; row_index++)
    {
        for (int column_index = 0; column_index < d; column_index++)
        {
            int item = board[row_index][column_index];
            // If this is the last column in a row, print the item and a break, otherwise print the item with a space
            if (column_index == d - 1)
                printf("%s\n", format_board_item(item, max_item_length));
            else
                printf("%s ", format_board_item(item, max_item_length));
        }
    }
}

/**
 * Formats the number to contain the proper amount of padding for printing
 */
char * format_board_item(int item, int max)
{
    // If we want to return a char list, we need to manually allocate memory for it
    char *formatted = (char *) malloc(sizeof(char) * max);
    char item_str[get_digits_size(item)];

    // Converts number to string
    sprintf(item_str, "%d", item);

    int item_index = max - sizeof(item_str)/sizeof(item_str[0]);

    // Pads the formatted string with empty spaces
    for (int i = 0; i < item_index; i++)
        formatted[i] = ' ';

    // Sets the number in the return string
    for (int i = item_index; i < max; i++)
    {
        if (atoi(item_str) == BLANK_SPACE)
            formatted[i] = '_';
        else
            formatted[i] = item_str[i - item_index];
    }

    return formatted;
}

/**
 * Gets the length of the digit, ie:
 *
 * 1 -> 1
 * 0 -> 1
 * 100 -> 3
 * 10 -> 2
 */
int get_digits_size(int digit)
{
    // In the case the digit is `0`, we default to 1 size
    int size = floor(log10(abs(digit))) + 1;

    if (size <= 0) return 1;
    return size;
}

/**
 * Gets the max number on the board
 */
int get_max_num(void)
{
    return d * d - 1;
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    return false;
}
