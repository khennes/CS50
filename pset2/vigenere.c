/* Vigenere cipher: Encrypts a user's plaintext input using a command-line argument as a keyword */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{    
    string k, p;
    int i, j, x, m, n, var;
    
    // return an error if command line takes other than one argument
    if (argc != 2)
    {
        printf("An error has occurred. Please try again.\n");
        return 1;
    }  
    // store keyword argv[1] in string k
    k = argv[1];
    x = strlen(k);
    int key[x];
    
    for (j = 0; j < x; j++)
    {
        // cast and store ASCII values of each char in string k in an array called key
        key[j] = (int) k[j];
            
        // return an error if key contains a non-alphabetical character
        if (isalpha(key[j]) == 0)
        {
            printf("An error has occurred. Please enter a new keyword.\n");
            return 1;
        }   
        // test key array for capital letters and set all letters equivalent to 0-25, regardless of case
        else if (isupper(key[j]) != 0)
            key[j] -= 65;

        // do the same for lowercase
        else
            key[j] -= 97;
    }
    
    // prompt user for plaintext string p
    p = GetString();
    n = strlen(p);
    int plain[n];
    
    for (i = 0, m = 0; i < n; i++)
    {
        // cast and store ASCII values of each char in string p in an array called plain
        plain[i] = (int) p[i];

        // store non-alphabetical characters unchanged
        if (isalpha(plain[i]) == 0) 
            var = plain[i];
        
        // test for capital letters, set equivalent to 0-25
        else if (isupper(plain[i]) != 0)
        {
            var = (plain[i] - 65 + key[m % x]) % 26 + 65;
            m++;
        }
        // do the same for lowercase
        else
        {
            var = (plain[i] - 97 + key[m % x]) % 26 + 97; 
            m++;
        }
        // print the enciphered text, recast as chars
        printf("%c", (char) var);
    }

    printf("\n");
    return 0;
}