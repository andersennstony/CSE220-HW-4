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
    // We assume that src is no longer than dest
    if ((dest == NULL) || (src == NULL))
        return;
    while (*src){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = 0;
    (void)dest;
    (void)src;
}

void strgChangeCase(char *s) {
    if (s == NULL || !s[0])
        return;
     // Not an empty string
        if (s[1] < '0' || s[1] > '9'){
            if (s[0] >= 'A' && s[0] <= 'Z')
                s[0] += 32;
            else if (s[0] >= 'a' && s[0] <= 'z')
                s[0] -= 32;
        }
    int i = 1;
    while (s[i]){ // First see if the surrounding characters are numbers
        if ((s[i + 1] < '0' || s[i + 1] > '9') && (s[i - 1] < '0' || s[i - 1] > '9')){
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
            else if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
        }
        i++;
    }
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
    char destination[32] = {0};
    // The test case with NULL should do nothing to the destination and should print Hello World!
    // All other test cases should print the same as the input function
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

    // strgChangeCase
    /*
    char s1[] = "Stony Brook"; // sTONY bROOK
    strgChangeCase(s1);
    printf("%s\n", s1);
    char s2[] = "CSE220"; // csE220
    strgChangeCase(s2);
    printf("%s\n", s2);
    char s3[] = "a1b"; // a1b
    strgChangeCase(s3);
    printf("%s\n", s3);
    char s4[] = "System Fundamental220"; // sYSTEM fUNDAMENTAl220
    strgChangeCase(s4);
    printf("%s\n", s4);
    char s5[] = ""; // ""
    strgChangeCase(s5);
    printf("%s\n", s5);
    char *s6 = NULL; // We will not print this because it will crash
    strgChangeCase(s6);
    printf("%p\n", s6);
    char s7[] = "a12b3cde4fg"; // a12b3cDe4fG
    strgChangeCase(s7);
    printf("%s\n", s7);
    char s8[] = "9AA_.Z.2E"; // 9Aa_.z.2E
    strgChangeCase(s8);
    printf("%s\n", s8);
    char s9[] = "A9B"; // A9B
    strgChangeCase(s9);
    printf("%s\n", s9);
    char s10[] = "_X_"; // _x_
    strgChangeCase(s10);
    printf("%s\n", s10);
    char s11[] = "aBcDeFg2HiJkLmNoP5"; // AbCdEfg2HIjKlMnOP5
    strgChangeCase(s11);
    printf("%s\n", s11); */

	return 0;
}