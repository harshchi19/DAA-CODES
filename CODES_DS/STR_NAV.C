#include<stdio.h>
#include<conio.h>



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

	for(i=0; i <= n-m; i++)
	{
		for(j=0; j<m; j++)
		{
			if(str[i+j]!=ptr[j])
			{
				break;
			}
		}

		if(j==m)
		{
			printf("Pattern found at index: %d",i+1);
		}
	}

	getch();
	return 0;
}