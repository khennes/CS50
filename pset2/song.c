/* Prints the song "This Old Man" using arrays and loops */

#include <cs50.h>
#include <stdio.h>

void chorus(void);

// number of verses in the song
#define VERSES 10

int main(int argc, string argv[])
{   
    char *numbers[VERSES];
	numbers[0] = "one";
	numbers[1] = "two";
	numbers[2] = "three";
    numbers[3] = "four";
	numbers[4] = "five";
	numbers[5] = "six";
    numbers[6] = "seven";
	numbers[7] = "eight";
	numbers[8] = "nine";
    numbers[9] = "ten";
    
    char *strings[VERSES];
	strings[0] = "on my thumb";
    strings[1] = "on my shoe";
    strings[2] = "on my knee";
    strings[3] = "on my door";
    strings[4] = "on my hive";
    strings[5] = "on my sticks";
    strings[6] = "up in heaven";
    strings[7] = "on my gate";
    strings[8] = "on my spine";
    strings[9] = "once again";
    
    for (int i = 0; i < VERSES; i++)
    {
    	printf("This old man, he played %s\n", numbers[i]);
    	printf("He played knick-knack %s\n", strings[i]);
    	chorus();
        printf("\n");
    }
}

void 
chorus(void)
{
    printf("Knick-knack paddywhack, give your dog a bone\n");
    printf("This old man came rolling home\n");
}