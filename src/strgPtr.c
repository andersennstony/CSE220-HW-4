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
    if ((s1 == NULL) || (s2 == NULL))
        return -2;
    int i = 0;
    while (1) {
        if (s1[i] != s2[i])
            return i;
        if (!s1[i] || !s2[i])
            break;
        i++;
    }
    (void)s1;
    (void)s2;
    return -1;
}

void strgInterleave(char *s1, char *s2, char *d) {
    // Similar to strgCopy(), we cannot get the size of d,
    // So we will assume that d is large enough
    if ((s1 == NULL) || (s2 == NULL) || (d == NULL))
        return;
    int i = 0, j = 0;
    while (s1[i] || s2[j]){
        if (s1[i]){
            *d = s1[i];
            i++;
            d++;
        }
        if (s2[j]){
            *d = s2[j];
            j++;
            d++;
        }
    }
    *d = 0;
    (void)s1;
    (void)s2;
    (void)d;
}

void strgReverseLetters(char *s) {
    if (s == NULL)
        return;
    int low = 0;
    int high = strgLen(s) - 1;
    int lowIsLetter, highIsLetter;
    char temp;
    while (low < high){
        lowIsLetter = (s[low] >= 'A' && s[low] <= 'Z') || (s[low] >= 'a' && s[low] <= 'z');
        highIsLetter = (s[high] >= 'A' && s[high] <= 'Z') || (s[high] >= 'a' && s[high] <= 'z');
        if (lowIsLetter && highIsLetter){
            temp = s[low];
            s[low] = s[high];
            s[high] = temp;
            low++;
            high--;
            continue;
        }
        if (!lowIsLetter)
            low++;
        if (!highIsLetter)
            high--;
    }
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

/*
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv; */
	
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

    // strgDiff
    /*
    printf("%d\n", strgDiff("Hello", "Hello")); // -1
    printf("%d\n", strgDiff("CSE-220", "CSE220")); // 3
    printf("%d\n", strgDiff("CSE220", "SE220")); // 0
    printf("%d\n", strgDiff("", "")); // -1
    printf("%d\n", strgDiff(NULL, "")); // -2
    printf("%d\n", strgDiff("a", NULL)); // -2
    printf("%d\n", strgDiff("abc", "abcd")); // 3
    printf("%d\n", strgDiff("98765", "98765 ")); // 5
    printf("%d\n", strgDiff("1234", "1234")); // -1
    printf("%d\n", strgDiff("Hello world", "Helloworld")); // 5 */

    // strgInterleave
    /*
    char destination[32] = {0};
    strgInterleave("abc", "123", destination); // a1b2c3
    printf("%s\n", destination);
    strgInterleave("abcdef", "123", destination); // a1b2c3def
    printf("%s\n", destination);
    strgInterleave("cse", "12345", destination); // c1s2e345
    printf("%s\n", destination);
    strgInterleave("1234", "cs", destination); // 1c2s34
    printf("%s\n", destination);
    strgInterleave("", "", destination); // ""
    printf("%s\n", destination);
    strgInterleave("", "123", destination); // 123
    printf("%s\n", destination);
    strgInterleave(NULL, "45", destination); // 123 (should not be changed since NULL is an argument)
    printf("%s\n", destination);
    strgInterleave("HLOWRD", "EL OL", destination); // HELLO WORLD
    printf("%s\n", destination);
    strgInterleave("432", "A", destination); // 4A32
    printf("%s\n", destination);
    strgInterleave("B", "357", destination); // B357
    printf("%s\n", destination); */

    // strgReverseLetters
    /*
    char t1[] = "hello"; // olleh
    strgReverseLetters(t1);
    printf("%s\n", t1);
    char t2[] = "ab-cd"; // dc-ba
    strgReverseLetters(t2);
    printf("%s\n", t2);
    char t3[] = "a1b2c"; // c1b2a
    strgReverseLetters(t3);
    printf("%s\n", t3);
    char t4[] = "hello world"; // dlrow olleh
    strgReverseLetters(t4);
    printf("%s\n", t4);
    char t5[] = "e1f!"; // f1e!
    strgReverseLetters(t5);
    printf("%s\n", t5);
    char t6[] = ""; // ""
    strgReverseLetters(t6);
    printf("%s\n", t6);
    char *t7 = NULL; // Do nothing. We will not print the value at
    strgReverseLetters(t7);
    printf("%p\n", t7);
    char t8[] = "_A__"; // _A__
    strgReverseLetters(t8);
    printf("%s\n", t8);
    char t9[] = "A1B CD2"; // D1C BA2
    strgReverseLetters(t9);
    printf("%s\n", t9);
    char t10[] = "!443qr"; // !443rq
    strgReverseLetters(t10);
    printf("%s\n", t10); */
    
//	return 0;
// }