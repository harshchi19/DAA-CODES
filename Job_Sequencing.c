#include <stdio.h>
#include <stdlib.h>
#include<conio.h>


typedef struct {
    int id;         
    int profit;     
    int deadline;   
} Job;


int compare_jobs(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}


int max_deadline(Job* jobs, int n) {
    int i;
    int max = 0;
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}


void schedule_with_deadline(Job* jobs, int n) {
    int i, j;         
    int max_dl = max_deadline(jobs, n);
    int* schedule = (int*)malloc((max_dl + 1) * sizeof(int));
    int* profit_set = (int*)malloc((max_dl + 1) * sizeof(int));
    int total_profit = 0;

   
    qsort(jobs, n, sizeof(Job), compare_jobs);

 
    for (i = 0; i <= max_dl; i++) {
        schedule[i] = -1;     
        profit_set[i] = 0;     
    }


    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline; j > 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].id;
                profit_set[j] = jobs[i].profit;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    
    printf("Optimal schedule J: ");
    for (i = 1; i <= max_dl; i++) {
        if (schedule[i] != -1) {
            printf("%d ", schedule[i]);
        }
    }
    printf("\n");

    
    printf("Profit set after job scheduling: ");
    for (i = 1; i <= max_dl; i++) {
        printf("%d ", profit_set[i]);
    }
    printf("\n");


    printf("Total profit: %d\n", total_profit);

   
    free(schedule);
    free(profit_set);
}

int main() {
    int n, i;
    Job* jobs;      
    clrscr();
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    jobs = (Job*)malloc(n * sizeof(Job));      


    for (i = 0; i < n; i++) {
        printf("Enter job ID, profit, and deadline for job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].profit, &jobs[i].deadline);
    }

    
    schedule_with_deadline(jobs, n);

    
    free(jobs);
    getch();
    return 0;
}
