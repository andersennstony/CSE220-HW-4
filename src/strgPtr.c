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
 * Test cases in base_tests.c using criterion
 */

/*
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
    return 0;
} */