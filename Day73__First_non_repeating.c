/*
Problem Statement:
Given a string s consisting of lowercase English letters, find and return
the first character that does not repeat in the string. If all characters
repeat, return '$'.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    int freq[26] = {0};

    printf("Enter string: ");
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("First non-repeating character: %c", s[i]);
            return 0;
        }
    }

    printf("First non-repeating character: $");
    return 0;
}
