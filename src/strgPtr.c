#include <stdlib.h>
#include "strgPtr.h"

int strgLen(const char *s) {
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
    // TODO: implement
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

	return 0;
}