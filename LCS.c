#include <stdio.h>
#include <string.h>
#include <conio.h>
// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

void LCS_computation_and_print(char *x, char *y) {
    int m = strlen(x);
    int n = strlen(y);
    int index;
    
    int LCS[101][101];
    int i, j;
    char lcs[201];
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    
    index = LCS[m][n];
    lcs[index] = '\0'; 

    
   
    i = m, j = n;
    while (i > 0 && j > 0) {
    

        if (x[i - 1] == y[j - 1]) {
            lcs[index - 1] = x[i - 1];             
            i--; j--; index--;                         
        }

        
        else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }

   
    printf("LCS of \"%s\" and \"%s\" is \"%s\"\n", x, y, lcs);
    printf("Length of LCS: %d\n", LCS[m][n]);
}

int main() {
    char x[1000], y[1000];      
    clrscr();

    printf("Enter first string: ");
    fgets(x, sizeof(x), stdin);                   
    x[strcspn(x, "\n")] = 0;                      

    printf("Enter second string: ");
    fgets(y, sizeof(y), stdin);                
    y[strcspn(y, "\n")] = 0;                    

    LCS_computation_and_print(x, y);
    getch();
    return 0;
}
