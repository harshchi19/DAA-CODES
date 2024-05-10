#include <stdio.h>
#include <string.h> 
#include <conio.h>
void naiveStringMatch(char *text, char *pattern) {
    int textLen = strlen(text);       
    int patternLen = strlen(pattern); 
    int i, j;

    for (i = 0; i <= textLen - patternLen; i++) {
        j = 0;
        while (j < patternLen && text[i + j] == pattern[j]) {
            j++; 
        }
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[256]; 
    char pattern[256]; 
    clrscr();
    printf("Enter the text: ");
    gets(text); 
    printf("Enter the pattern: ");
    gets(pattern); 

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Pattern found at following indices:\n");
    naiveStringMatch(text, pattern);
    getch();
    return 0;
}
