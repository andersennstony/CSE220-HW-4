#include <criterion/criterion.h>
#include <string.h>

#include "caesar.h" 
#include "strgPtr.h"

// Part 1: String utility functions

Test(strgLen, basic) {
    cr_assert_eq(strgLen("Stony Brook"), 11);
    cr_assert_eq(strgLen("CSE 220"), 7);
    cr_assert_eq(strgLen("C"), 1);
    cr_assert_eq(strgLen("System Fundamental"), 18);
    cr_assert_eq(strgLen("1"), 1);
    cr_assert_eq(strgLen(""), 0);
    cr_assert_eq(strgLen("Hello"), 5);
    cr_assert_eq(strgLen("Hello!"), 6);
    cr_assert_eq(strgLen("Hi"), 2);
    cr_assert_eq(strgLen("Hello world!"), 12);
}

Test(strgLen, null_input) {
    cr_assert_eq(strgLen(NULL), -1);
}

Test(strgCopy, normal_and_empty) {
    char dest[32] = {0};
    strgCopy(dest, "Computer Science");
    cr_assert_str_eq(dest, "Computer Science");
    
    strgCopy(dest, "CSE-220");
    cr_assert_str_eq(dest, "CSE-220");
    
    strgCopy(dest, "System Fundamental");
    cr_assert_str_eq(dest, "System Fundamental");
    
    strgCopy(dest, "1");
    cr_assert_str_eq(dest, "1");
    
    strgCopy(dest, "abcde");
    cr_assert_str_eq(dest, "abcde");
    
    strgCopy(dest, ".2f");
    cr_assert_str_eq(dest, ".2f");
    
    strgCopy(dest, "9876");
    cr_assert_str_eq(dest, "9876");
    
    strgCopy(dest, " ");
    cr_assert_str_eq(dest, " ");

    dest[0] = '\0';
    strgCopy(dest, "");
    cr_assert_str_eq(dest, "");
}

Test(strgCopy, null_args_do_nothing) {
    char dest[16] = "UNCHANGED";
    strgCopy(NULL, "foo");
    cr_assert_str_eq(dest, "UNCHANGED");
    strgCopy(dest, NULL);
    cr_assert_str_eq(dest, "UNCHANGED");
}

Test(strgChangeCase, flip_only_non_adjacent_to_digits) {
    char s1[] = "Stony Brook";
    strgChangeCase(s1);
    cr_assert_str_eq(s1, "sTONY bROOK");

    char s2[] = "CSE220";
    strgChangeCase(s2);
    cr_assert_str_eq(s2, "csE220");

    char s3[] = "a1b";
    strgChangeCase(s3);
    cr_assert_str_eq(s3, "a1b");

    char s4[] = "A9B";
    strgChangeCase(s4);
    cr_assert_str_eq(s4, "A9B");

    char s5[] = "_X_";
    strgChangeCase(s5);
    cr_assert_str_eq(s5, "_x_");

    char s6[] = "System Fundamental220";
    strgChangeCase(s6);
    cr_assert_str_eq(s6, "sYSTEM fUNDAMENTAl220");

    char s7[] = "a12b3cde4fg";
    strgChangeCase(s7);
    cr_assert_str_eq(s7, "a12b3cDe4fG");

    char s8[] = "9AA_.Z.2E";
    strgChangeCase(s8);
    cr_assert_str_eq(s8, "9Aa_.z.2E");

    char s9[] = "A9B";
    strgChangeCase(s9);
    cr_assert_str_eq(s9, "A9B");

    char s10[] = "aBcDeFg2HiJkLmNoP5";
    strgChangeCase(s10);
    cr_assert_str_eq(s10, "AbCdEfg2HIjKlMnOP5");
}

Test(strgChangeCase, empty_and_digit_only) {
    char e1[] = "";
    strgChangeCase(e1);
    cr_assert_str_eq(e1, "");

    char e2[] = "1";
    strgChangeCase(e2);
    cr_assert_str_eq(e2, "1");
}

Test(strgDiff, differences_and_equals) {
    cr_assert_eq(strgDiff("Hello","Hello"), -1);
    cr_assert_eq(strgDiff("CSE-220","CSE220"), 3);
    cr_assert_eq(strgDiff("CSE220","SE220"), 0);
    cr_assert_eq(strgDiff("",""), -1);
    cr_assert_eq(strgDiff("1234","1234"), -1);
    cr_assert_eq(strgDiff("98765","98765 "), 5);
    cr_assert_eq(strgDiff("Hello world","Helloworld"), 5);
    cr_assert_eq(strgDiff("123","456"), 0);
    cr_assert_eq(strgDiff("ABC","ACB"), 1);
}

Test(strgDiff, null_inputs) {
    cr_assert_eq(strgDiff(NULL, "foo"), -2);
    cr_assert_eq(strgDiff("foo", NULL), -2);
}

Test(strgInterleave, normal_and_unequal_lengths) {
    char dest[32] = {0};

    strgInterleave("abc","123", dest);
    cr_assert_str_eq(dest, "a1b2c3");

    strgInterleave("abcdef","123", dest);
    cr_assert_str_eq(dest, "a1b2c3def");

    strgInterleave("cse","12345", dest);
    cr_assert_str_eq(dest, "c1s2e345");

    strgInterleave("1234","cs", dest);
    cr_assert_str_eq(dest, "1c2s34");

    strgInterleave("", "", dest);
    cr_assert_str_eq(dest, "");

    strgInterleave("","123", dest);
    cr_assert_str_eq(dest, "123");

    strgInterleave("HLOWRD", "EL OL", dest);
    cr_assert_str_eq(dest, "HELLO WORLD");

    strgInterleave("432", "A", dest);
    cr_assert_str_eq(dest, "4A32");

    strgInterleave("B", "357", dest);
    cr_assert_str_eq(dest, "B357");

    strgInterleave("abcefg", "./d", dest);
    cr_assert_str_eq(dest, "a.b/cdefg");
}

Test(strgReverseLetters, basic) {
    char t1[] = "hello";
    strgReverseLetters(t1);
    cr_assert_str_eq(t1, "olleh");

    char t2[] = "hello world";
    strgReverseLetters(t2);
    cr_assert_str_eq(t2, "dlrow olleh");

    char t3[] = "ab-cd";
    strgReverseLetters(t3);
    cr_assert_str_eq(t3, "dc-ba");

    char t4[] = "e1f!";
    strgReverseLetters(t4);
    cr_assert_str_eq(t4, "f1e!");

    char t5[] = "_X_";
    strgReverseLetters(t5);
    cr_assert_str_eq(t5, "_X_");

    char t6[] = "_A__";
    strgReverseLetters(t6);
    cr_assert_str_eq(t6, "_A__");

    char t7[] = "A1B CD2";
    strgReverseLetters(t7);
    cr_assert_str_eq(t7, "D1C BA2");

    char t8[] = "!443qr";
    strgReverseLetters(t8);
    cr_assert_str_eq(t8, "!443rq");

    char t9[] = "__AB_C..";
    strgReverseLetters(t9);
    cr_assert_str_eq(t9, "__CB_A..");

    char t10[] = "ab";
    strgReverseLetters(t10);
    cr_assert_str_eq(t10, "ba");
}

/*
 * Part 2: Position-aware Caesar cipher
 */

/* encryptCaesar tests */


Test(encryptCaesar, basic_shifts) {
    char out[64];

    cr_assert_eq(encryptCaesar("abc",  out, 2), 3);
    cr_assert_str_eq(out, "ceg__EOM__");

    cr_assert_eq(encryptCaesar("Ayb",  out, 3), 3);
    cr_assert_str_eq(out, "Dcg__EOM__");

    cr_assert_eq(encryptCaesar("Cse220", out, 1), 6);
    cr_assert_str_eq(out, "Duh911__EOM__");

    cr_assert_eq(encryptCaesar("CS", out, 0), 2);
    cr_assert_str_eq(out, "CT__EOM__");

    cr_assert_eq(encryptCaesar("System Fundamentals", out, 1), 18);
    cr_assert_str_eq(out, "Tavxjs Ndxomzscjrdl__EOM__");

    cr_assert_eq(encryptCaesar("Z", out, 1), 1);
    cr_assert_str_eq(out, "A__EOM__");

    cr_assert_eq(encryptCaesar("12 3 45", out, 0), 5);
    cr_assert_str_eq(out, "14 9 47__EOM__");

    cr_assert_eq(encryptCaesar("__aBc_.", out, 6), 3);
    cr_assert_str_eq(out, "__iKm_.__EOM__");
}

Test(encryptCaesar, empty_input) {
    char out[32] = {0};
    cr_assert_eq(encryptCaesar("", out, 42), 0);
    cr_assert_str_eq(out, "undefined__EOM__");
}

Test(encryptCaesar, null_args) {
    char out[16];
    cr_assert_eq(encryptCaesar(NULL, out, 5), -2);
    cr_assert_eq(encryptCaesar("hi",  NULL, 5), -2);
}

/* decrypt tests */

Test(decryptCaesar, basic_unshifts) {
    char out[64] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // With each decryptCaesar() call, the output string may decrease in length
    // It can never increase back in length

    cr_assert_eq(decryptCaesar("Tavxjs Ndxomzscjrdl__EOM__", out, 1), 18);
    cr_assert_str_eq(out, "System Fundamentals");

    cr_assert_eq(decryptCaesar("__iKm_.__EOM__", out, 6), 3);
    cr_assert_str_eq(out, "__aBc_.");

    cr_assert_eq(decryptCaesar("Duh911__EOM__", out, 1), 6);
    cr_assert_str_eq(out, "Cse220");

    cr_assert_eq(decryptCaesar("ceg__EOM__", out, 2), 3);
    cr_assert_str_eq(out, "abc");

    cr_assert_eq(decryptCaesar("Dcg__EOM__", out, 3), 3);
    cr_assert_str_eq(out, "Ayb");

    cr_assert_eq(decryptCaesar("CT__EOM__", out, 0), 2);
    cr_assert_str_eq(out, "CS");
}

Test(decryptCaesar, empty_input_marker) {
    char out[32];
    cr_assert_eq(decryptCaesar("undefined__EOM__", out, 7), 0);
    cr_assert_str_eq(out, "undefined");
}

Test(decryptCaesar, zero_length_plaintext) {
    /* initial strlen(plaintext)==0 ⇒ return 0, no write */
    char p[1] = "";
    cr_assert_eq(decryptCaesar("ceg__EOM__", p, 2), 0);
    cr_assert_str_eq(p, "");
}

Test(decryptCaesar, missing_marker) {
    /* plaintext must remain unchanged */
    char buf[32];
    strcpy(buf, "no marker here");
    cr_assert_eq(decryptCaesar("no marker here", buf, 1), -1);
    cr_assert_str_eq(buf, "no marker here");
}

Test(decryptCaesar, null_args) {
    char out[16];
    cr_assert_eq(decryptCaesar(NULL, out, 5), -2);
    cr_assert_eq(decryptCaesar("abc__EOM__", NULL, 5), -2);
}

Test(decryptCaesar, truncation_by_strlen) {
    /* initial strlen(plaintext)==4 ⇒ can only store 4 chars + NUL */
    char p[5] = "xxxx";
    int rv = decryptCaesar("Duh911__EOM__", p, 1);
    cr_assert_eq(rv, 6);
    cr_assert_str_eq(p, "Cse2");
}