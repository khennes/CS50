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
        printf("What is the height of your pyramid? ");
        fflush(stdout);
        height = GetInt();
    }
    
    // first row will print (height - 1) spaces
    spaces = height - 1;
    
    // first row will print 2 hashes, assuming the pyramid has a height of at least 1
    hashes = 2;
    for (n = 0; n < height; n++)
    {
        for (i = 0; i < spaces; i++)
        {
            printf("_");
            spaces--;
        }
        for (j = hashes; j > 0; j--)
        {
            printf("#");
            hashes++;
            printf("\n");
        }
    }
    return 0;
}