#include <stdlib.h>
#include "strgPtr.h"

int strgLen(const char *s) {
    // Does not include the null character
    if (s == NULL)
        return -1;
    int count = 0;
    while (*s){
        s++;
        count++;
    }
    return count;
}

void strgCopy(char *dest, char *src) {
    // May have to fix this
    if ((dest == NULL) || (src == NULL))
        return;
    /*
    int i = 0;
    while (dest[i] && src[i]){
        dest[i] = src[i];
        i++;
    }
    */
    while (*dest){ // While we have not reached the null character
        if (*src){ // See if the source string has another character
            *dest = *src; // If so, copy it and move on
            src++;
        }
        else // The source string has ended
            *dest = 0x20; // We will fill the destination string with empty space
        dest++;
    }
    (void)dest;
    (void)src;
}

void strgChangeCase(char *s) {
    // TODO: implement
    (void)s;
}

int strgDiff(char *s1, char *s2) {
    // TODO: implement
    (void)s1;
    (void)s2;
    return 0;
}

void strgInterleave(char *s1, char *s2, char *d) {
    // TODO: implement
    (void)s1;
    (void)s2;
    (void)d;
}

void strgReverseLetters(char *s) {
    // TODO: implement
    (void)s;
}



/**
 * Run the test cases by first compiling with "make" and then 
 * running "./bin/strgPtr"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs. 
 * Comment out if using criterion to test.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	
    // strgLen()
    /*
    printf("%d\n", strgLen("Stony Brook")); // 11
    printf("%d\n", strgLen("CSE 220")); // 7
    printf("%d\n", strgLen("C")); // 1
    printf("%d\n", strgLen("System Fundamental")); // 18
    printf("%d\n", strgLen("1")); // 1
    printf("%d\n", strgLen("")); // 0
    printf("%d\n", strgLen(NULL)); // -1

    printf("%d\n", strgLen("Hi")); // 2
    printf("%d\n", strgLen("Hello!")); // 6
    printf("%d\n", strgLen("Hello world")); // 11 */

    // strgCopy
    /*
    char destination[] = "abcdefghijklmnopqrst";
    // Most of the test cases should print the same as the input function
    // So the first one should print "Computer Science" as normal
    // However, the one with the letters of the alphabet should print up to t
    // The one with NULL should do nothing to the destination and should print Hello World!
    strgCopy(destination, "Computer Science");
    printf("%s\n", destination);
    strgCopy(destination, "CSE-220");
    printf("%s\n", destination);
    strgCopy(destination, "System Fundamental");
    printf("%s\n", destination);
    strgCopy(destination, "1");
    printf("%s\n", destination);
    strgCopy(destination, "");
    printf("%s\n", destination);

    strgCopy(destination, "abcde");
    printf("%s\n", destination);
    strgCopy(destination, "abcdefghijklmnopqrstuvwxyz");
    printf("%s\n", destination);
    strgCopy(destination, "Hello world!");
    printf("%s\n", destination);
    strgCopy(destination, NULL);
    printf("%s\n", destination);
    strgCopy(destination, "0");
    printf("%s\n", destination); */

	return 0;
}