#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
long int mod = 10000000007;

int f(char c){
    return (int)c - (int)'a' + 1;
}

int power(int p){
    int i, ans = 1;
    for(i = 1; i <= p; i++){
	ans = (ans%mod * 10%mod)%mod;
    }
    return ans;
}

int main(){

    char S[100], P[100];
    int n, m, i, j, k;
    int pattern_hash = 0;
    int str_hash = 0;
    int spurious=0;
    printf("Enter the length of String and Pattern: ");
    scanf("%d%d", &n, &m);
    printf("Enter the String: ");
    scanf("%s", &S);
    printf("Enter the Pattern: ");
    scanf("%s", &P);

    for(i = 0; i < m; i++){
	pattern_hash = ((10*pattern_hash)%mod + f(P[i])%mod)%mod;
	str_hash = ((10*str_hash)%mod + f(S[i])%mod)%mod;
    }

    for(i = 0; i <= (n-m); i++){
	if(str_hash == pattern_hash){
	    j=i;
	    k=0;
	    for(j=i; j<m; j++,k++)
	    {
		if(S[j]!=P[k])
		{
		    spurious++;
		    printf("Spurious Hit found: %d",spurious);
		    break;
		}
	    }
	    if(spurious==0)
	    {
		printf("Pattern found at Position: %d", i+1);
	    }
	}

	if(i==n-m)break;

	str_hash = (str_hash - (f(S[i])*power(m-1)))%mod;
	if(str_hash<0)str_hash += mod;

	str_hash *= 10;
	str_hash %= mod;

	str_hash += f(S[i+m]);
	str_hash %= mod;

    }
    getch();
    return 0;

}