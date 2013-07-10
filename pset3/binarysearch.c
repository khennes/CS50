/* Implement binary search using a recursive function */


#include <cs50.h>
#include <stdio.h>

#define SIZE 8


bool search(int needle, int haystack[], int size)
{
    int start;
    int end;
    int middle = size / 2;
  
    // base case (if there is only one value left to compare)
    if (size == 1)
    {
        if (needle == haystack[middle])
        {
            printf("Found it!\n");
            return 0;
        }
        else
        {
            printf("Nope, not here.\n");
            return 1;
        }
    }
    
    // if "needle" is lower than the middle value
    else if (needle < haystack[middle])
    {
        // reset start & end points
        start = 0;
        end = middle;
        
        // bisect array and initialize new array (a copy)
        size = size / 2;
        int new_haystack[size];
       
        // store relevant half of old array in new array
        for (int i = 0; i < size; i++)
        {
        	new_haystack[i] = haystack[start];
            start++;
        }
		// recurse!
        search(needle, new_haystack, size);
        return 1;
    }
    
    // if "needle" is higher than the middle value
    else if (needle > haystack[middle - 1])
    {
        // reset start & end points
        start = middle;
        end = size;
        
        // bisect array and initialize new array (a copy)
        size = size / 2;
        int new_haystack[size];

        // store relevant half of old array in new array
        for (int i = 0; i < size; i++)
        {
            new_haystack[i] = haystack[start];
            start++;
        }
        // recurse!
        search(needle, new_haystack, size);
        return 1;
    }
    
    // failsafe for the compiler
    else
    	return 1;
}

int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("> ");
    int n = GetInt(); // get user input (from CS50.h)
    if (search(n, numbers, SIZE))
		// search function does not always return correct output
    	printf("YES\n");
    return 0;
}
