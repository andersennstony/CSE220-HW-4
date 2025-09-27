#include <stdlib.h>
#include "caesar.h" 
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

int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    // We are assuming that the ciphertext is large enough to hold the plaintext
    // And the __EOM__ marker and null character (plaintext + EOM + 1)
	if ((plaintext == NULL) || (ciphertext == NULL))
        return -2;
    int i = 0;
    char currentChar;
    // Go through each character in plaintext
    while ((currentChar = plaintext[i])){ // This is a variable assignment
        if (currentChar >= 'A' && currentChar <= 'Z') // Uppercase letter
            currentChar = (currentChar - 'A' + key + i) % 26 + 'A';
        else if (currentChar >= 'a' && currentChar <= 'z') // Lowercase
            currentChar = (currentChar - 'a' + key + i) % 26 + 'a';
        else if (currentChar >= '0' && currentChar <= '9') // Number
            currentChar = (currentChar - '0' + key + i * 2) % 10 + '0';
        ciphertext[i] = currentChar;
        i++;
    }
    // Add the __EOM__ marker
    char *marker = "__EOM__";
    ciphertext += i;
    for (int j = 0; j < 8; j++)
        ciphertext[j] = marker[j];
    (void)plaintext;
    (void)ciphertext;
    (void)key;
    return i;
}

int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
	// TODO: implement
    (void)ciphertext;
    (void)plaintext;
    (void)key;
    return 0;
}


/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then 
 * running "./bin/caesar"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs. 
 * Comment out if using criterion to test.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	
    char encryptedText[100] = {0};
    printf("%d: ", encryptCaesar("System Fundamentals", encryptedText, 1));
    printf("%s\n", encryptedText);
    printf("%d: ", encryptCaesar("abc", encryptedText, 2));
    printf("%s\n", encryptedText);
    printf("%d: ", encryptCaesar("Ayb", encryptedText, 3));
    printf("%s\n", encryptedText);

	return 0;
}