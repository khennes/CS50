#include <cs50.h>
#include <stdio.h>
#include <math.h>

int
main(void)
{
    // ask the user how much change is owed
    printf("O hai! How much change is owed?\n");
    float f = GetFloat();
    
    // repeat the question until user supplies a non-negative input
    while (f < 0)
    {
        printf("How much change is owed?\n");
    	f = GetFloat();
    }
    // convert float to int (number of pennies)
    int change = round(f * 100);
    int coins = 0;

    // loop through each type of coin possible
    do
    {
    	if (change >= 25)
        {
            coins += floor(change / 25);
            change = change % 25;
        }
        else if (change >= 10)
        {
            coins += floor(change / 10);
            change = change % 10;
        }  
        else if (change >= 5)
        {
            coins += floor(change / 5);
            change = change % 5;
        }
        else if (change >= 1)
        {
            coins += floor(change / 1);
            change -= (change / 1);
        }
    }
    while (change > 0);
    printf("%d\n", coins);
}