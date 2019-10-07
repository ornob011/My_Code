#include<stdio.h>
#include<math.h>
int main()
{
	int i, j, n;

	scanf("%d", &n);

	int primes[n+1];

	for(i=2; i<n; i++)
		primes[i]=i;

	for(i=2; i*i<=n; i++)
	{
		if(primes[i])
		{
			for(j=i; i*j<n; j++)
			{
				primes[i*j]=0;
			}
		}
	}
	for(i=2; i<n; i++)
	{
		if(primes[i])
			printf("%d ", i);
	}
	printf("\n");

	return 0;
}
