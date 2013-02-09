/* Prints a Mario-style pyramid of blocks based on a user-specified height */


#include <cs50.h>
#include <stdio.h>
#include <math.h>

int
main(void)
{
    int height, i, j, n, spaces, hashes;
    
    // prompt the user for the height of the pyramid
    printf("What is the height of your pyramid?\n");
    printf("Height: ");
    fflush(stdout);
    height = GetInt();
    
    // repeat question until user inputs a non-negative integer between 0 and 23
    while (height < 0 || height > 23)
    {
        printf("What is the height of your pyramid?\n");
        height = GetInt();
    }
    
    spaces = height - 1;
    hashes = 2;
    for (n = 0; n < height; n++)
    {
        for (i = 0; i < spaces; i++)
            printf(" ");
            spaces--;
        for (j = hashes; j > 0; j--)
            printf("#");
            hashes++;

            printf("\n");
    }
    return 0;
}