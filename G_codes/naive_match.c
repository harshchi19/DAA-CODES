#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "hiehelloi";
    char pattern[] = "hello";
    int i, j;

    for (i = 0; i < strlen(string); i++) {
        int found = 1;
        for (j = 0; j < strlen(pattern); j++) {
            if (string[i + j] != pattern[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            printf("Pattern found at index %d\n", i);
        }
    }

    return 0;
}