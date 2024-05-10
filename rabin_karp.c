#include <stdio.h>
#include <string.h>

#define d 256         

void rabinKarp(char pattern[], char text[], int q) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0;  
    int t = 0;  
    int h = 1;

  
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

  
    for (i = 0; i <= N - M; i++) {
        
        if (p == t) {
            
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    char text[1024];              
    char pattern[256];
    int q = 101;  

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);                   
    text[strcspn(text, "\n")] = 0;                       

    printf("Enter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);                   
    pattern[strcspn(pattern, "\n")] = 0;                        

    rabinKarp(pattern, text, q);
    return 0;
}
