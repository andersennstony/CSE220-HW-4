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
	// TODO: implement
    (void)plaintext;
    (void)ciphertext;
    (void)key;
    return 0;
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
	/** CREATE TEST CASES HERE **/



	
	/** ---------------------- **/
	return 0;
}