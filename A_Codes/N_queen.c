#include<stdio.h>
#include<stdbool.h>
#define N 4


void print(int board[N][N]) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool safe(int board[N][N] , int row , int col){
    for(int i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }

    for(int i=row , j=col ; i>=0 && j>=0 ; i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    for(int i=row , j=col ; i<N && j>=0 ; i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}



bool solve_util(int board[N][N] , int col){
    if(col>=N){
        return true;
    }
    for(int i=0;i<N;i++){
        if(safe(board,i,col)){
            board[i][col] = 1;
            if(solve_util(board , col+1)){
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}


bool solve(){
    int board[N][N] = {0};
    if(!solve_util(board,0)){
        printf("Solution does not exist");
        return false;
    }
    printf("Solution is : ");
    print(board);
    return true;
}

void main(){
    solve();
}