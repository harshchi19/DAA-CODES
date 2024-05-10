#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int f(char c){
	return (int)c - 97 + 1;
	}

int power(int p){
	int i, res=1;
	for(i=1; i<=p; i++){
		res *= 10;
	}
	return res;
}

int main(){

	int i, n, m;
	int str_hash=0, pat_hash=0;
	char S[100], P[100];
	clrscr();

	printf("Enter the length of string and pattern:");
	scanf("%d %d", &n, &m);

	printf("Enter the string:");
	scanf("%s", &S);

	printf("Enter the Pattern:");
	scanf("%s", &P);

	for( i=0; i<m; i++)
	{
		str_hash = (10*str_hash) + f( S[i] );
		pat_hash = (10*pat_hash) + f( P[i] );
	}

	for( i=0; i<= n-m; i++){
		if(str_hash==pat_hash){
			printf("Pattern found at %d: \n",i);
		}
		printf("\n %d %d \n",pat_hash,str_hash);

		str_hash -= ( f(S[i]) * power(m-1));
		str_hash *= 10;
		str_hash += f( S[i+m]);
		printf("Iteration: %d", i);
	}

	printf("Done");
	getch();
	return 0;
}






