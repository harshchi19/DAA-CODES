#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int start[100], finish[100];
char task[100], activity[100];

void swap(int a[], int j) {
    int temp1;
    temp1 = a[j];
    a[j] = a[j+1];
    a[j+1] = temp1;
}

void swap2(char a[], int j) {
    char temp1;
    temp1 = a[j];
    a[j] = a[j+1];
    a[j+1] = temp1;
}
int main() {
    int n, i=0, j, temp1, temp2, temp3 , count;
    clrscr();
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    printf("Enter the start time of tasks: ");
    for(i=0; i<n; i++) {
        scanf("%d", &start[i]);
        task[i] = i+1;
    }
    printf("Enter the finish time of tasks: ");
    for(i=0; i<n; i++) {
        scanf("%d", &finish[i]);
    }
    
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(finish[j] > finish[j+1]) {
                swap(finish, j);
                swap(start, j);
                swap2(task, j);
            }
        }
    }
   
    activity[0] = task[0];
    i = 0;
    count = 1;
    for(j=1; j<n; j++) {
        if(start[j] >= finish[i]) {
            activity[count++] = task[j];
            i=j;
        }
    }

   
    printf("\nTasks that are selected: ");
    for(i=0; i<count; i++) {
        printf("%d\t", activity[i]);
    }
    getch();
    return 0;
}
