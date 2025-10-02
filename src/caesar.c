#include <stdlib.h>
#include "caesar.h" 
#include "strgPtr.h"

int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    // We are assuming that the ciphertext is large enough to hold the plaintext
    // And the __EOM__ marker and null character (plaintext + EOM + 1)
	if ((plaintext == NULL) || (ciphertext == NULL))
        return -2;
    int i = 0, charsEncrypted = 0;
    char currentChar;
    // Go through each character in plaintext
    while ((currentChar = plaintext[i])){ // This is a variable assignment
        charsEncrypted++;
        if (currentChar >= 'A' && currentChar <= 'Z') // Uppercase letter
            currentChar = (currentChar - 'A' + key + i) % 26 + 'A';
        else if (currentChar >= 'a' && currentChar <= 'z') // Lowercase
            currentChar = (currentChar - 'a' + key + i) % 26 + 'a';
        else if (currentChar >= '0' && currentChar <= '9') // Number
            currentChar = (currentChar - '0' + key + i * 2) % 10 + '0';
        else
            charsEncrypted--;
        ciphertext[i] = currentChar;
        i++;
    }
    // See if the plaintext is an empty string
    if (i == 0){ // ciphertext becomes undefined__EOM__
        char undefined[] = "undefined";
        for (i = 0; i < 9; i++)
            ciphertext[i] = undefined[i];
    }
    // Add the __EOM__ marker
    char *marker = "__EOM__";
    ciphertext += i;
    for (i = 0; i < 8; i++)
        ciphertext[i] = marker[i];
    (void)plaintext;
    (void)ciphertext;
    (void)key;
    return charsEncrypted;
}

int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
	if ((plaintext == NULL) || (ciphertext == NULL)) // -2 error code
        return -2;
    // Find the first __EOM__ marker
    // First, find the length of the ciphertext
    int ciphertextLength = strgLen(ciphertext),
        i = 0, j, EOMFound,
        markerIndex = 0;
    char remainingEOM[] = "_EOM__";
    while (i <= ciphertextLength - 7){
        if (ciphertext[i] == '_'){ // Possibly the beginning of the __EOM__ marker
            EOMFound = 1;
            for (j = 0; j < 6; j++){
                if (ciphertext[i + j + 1] != remainingEOM[j]){
                    EOMFound = 0;
                    break;
                }
            }
            if (EOMFound){
                markerIndex = i;
                break;
            }
        }
        i++;
    }
    // Note that "__EOM__" will return an index of 0
    // To make this return -1 instead, change the line below to if (markerIndex == 0)
    if (EOMFound == 0)
        return -1;

    int plaintextLength = strgLen(plaintext); // Empty plaintext (error code 0)
    if (plaintextLength == 0)
        return 0;

    // Check for undefined__EOM__
    if (markerIndex >= 9){
        char undefined[] = "undefined";
        int isUndefined = 1;
        for (i = 0; i < 9; i++)
            if (ciphertext[i] != undefined[i]){
                isUndefined = 0;
                break;
            }
        if (isUndefined){
            for (i = 0; i < 9; i++)
                plaintext[i] = undefined[i];
            plaintext[i] = 0;
            return 0;
        }
    }
    char currentChar, shifted;
    int charsEncrypted = 0;
    j = 0;
    for (i = 0; i < markerIndex; i++){
        currentChar = ciphertext[i];
        charsEncrypted++;
        if (currentChar >= 'A' && currentChar <= 'Z'){ // Uppercase letter
            shifted = (currentChar - key - i - 'A') % 26;
            if (shifted >= 0)
                currentChar = shifted % 26 + 'A';
            else
                currentChar = 'Z' + (shifted % 26) + 1;
        }
        else if (currentChar >= 'a' && currentChar <= 'z'){ // Lowercase
            shifted = (currentChar - key - i - 'a') % 26;
            if (shifted >= 0)
                currentChar = shifted % 26 + 'a';
            else
                currentChar = 'z' + (shifted % 26) + 1;
        }
        else if (currentChar >= '0' && currentChar <= '9'){ // Number
            shifted = (currentChar - key - i * 2 - '0') % 10;
            if (shifted >= 0)
                currentChar = shifted % 10 + '0';
            else
                currentChar = '9' + (shifted % 10) + 1;
        }
        else
            charsEncrypted--;
        if (i < plaintextLength){
            plaintext[i] = currentChar;
            j++;
        }
    }
    plaintext[j] = 0; // Do not forget the null character
    (void)ciphertext;
    (void)plaintext;
    (void)key;
    return charsEncrypted;
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
/*
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv; */
	
    // Encryption
    /*
    char encryptedText[100] = {0};
    int charsEncrypted;
    charsEncrypted = encryptCaesar("System Fundamentals", encryptedText, 1); // 18, Tavxjs Ndxomzscjrdl__EOM__
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText);
    charsEncrypted = encryptCaesar("abc", encryptedText, 2); // 3, ceg__EOM__
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText);
    charsEncrypted = encryptCaesar("Ayb", encryptedText, 3); // 3, Dcg__EOM__
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText);
    charsEncrypted = encryptCaesar("Cse220", encryptedText, 1); // 6, Duh911__EOM__ 
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText);
    charsEncrypted = encryptCaesar("CS", encryptedText, 0); // 2, CT__EOM__
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText);
    charsEncrypted = encryptCaesar("", encryptedText, 5); // 0, undefined__EOM__
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText);
    charsEncrypted = encryptCaesar("Z", encryptedText, 1); // 1, A__EOM__
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText);
    charsEncrypted = encryptCaesar(NULL, encryptedText, 3); // -2, encryptedText remains same
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText);
    printf("Characters encoded: %d\n", encryptCaesar("12345", NULL, 0)); // Prints -2
    charsEncrypted = encryptCaesar("12 3 45", encryptedText, 0); // 5, 14 9 47__EOM__
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText);
    charsEncrypted = encryptCaesar("__aBc_.", encryptedText, 6); // 3, __iKm_.__EOM__
    printf("Characters encoded: %d. Ciphertext: %s\n", charsEncrypted, encryptedText); */

    // Decryption
    /*
    char plainText[100] = {0};
    int charsDecrypted;
    charsDecrypted = decryptCaesar("ceg__EOM__", plainText, 2); // 3, abc
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText);
    charsDecrypted = decryptCaesar("Dcg__EOM__", plainText, 3); // 3, Ayb
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText);
    charsDecrypted = decryptCaesar("Duh911__EOM__", plainText, 1); // 6, CSE220
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText);
    charsDecrypted = decryptCaesar("CT__EOM__", plainText, 0); // 2, CS
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText);
    charsDecrypted = decryptCaesar("Tavxjs Ndxomzscjrdl__EOM__", plainText, 1); // 18, System Fundamentals
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText);
    charsDecrypted = decryptCaesar("undefined__EOM__", plainText, 5); // 0, undefined
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText);
    printf("%d\n", decryptCaesar(NULL, plainText, 5)); // -2
    charsDecrypted = decryptCaesar("__iKm_.__EOM__", plainText, 6); // 3, __aBc_.
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText);
    charsDecrypted = decryptCaesar("Will not decode", plainText, 3); // -1, plainText remains same
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText);
    charsDecrypted = decryptCaesar("14 9 47__EOM__", plainText, 0); // 5, 12 3 45
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText);
    charsDecrypted = decryptCaesar("A__EOM__", plainText, 1); // 1, Z
    printf("Characters decrypted: %d. Plaintext: %s\n", charsDecrypted, plainText); */    

//	return 0;
// }