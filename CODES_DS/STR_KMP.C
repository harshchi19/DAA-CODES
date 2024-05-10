#include<conio.h>
#include<stdio.h>


void pref(char* P, int m, int* prefix)
{
	int i=1, j=0;
	prefix[0] = -1;

	while(i<m)
	{
		while( j>=0 && P[i] != P[j])
		{
			j = prefix[j];
		}
		i++;
		j++;
		prefix[i]=j;
	}
}

void match( char* P, char* T, int m, int n, int* prefix)
{
	int i=0, j=0;
	while(i < n){
		while( j >= 0 && T[i] != P[j] )
		{
			j = prefix[j];
		}
		i++;
		j++;

		if(j==m)
		{
			printf("Pattern found at index: %d \n",i-j);
			j = prefix [i-1];
		}
	}
	printf("Pattern Ended");
}

int main()
{
	int i, j, n, m;
	char str[100], ptr[100];
	int prefix[100];
	clrscr();

	printf("Enter the length of String and Pattern:");
	scanf("%d %d", &n, &m);
	printf("Enter the String:");
	scanf("%s", &str);
	printf("Enter the Pattern:");
	scanf("%s", &ptr);

	pref(ptr, m, prefix);
	match(ptr, str, m, n, prefix);


	getch();
	return 0;
}