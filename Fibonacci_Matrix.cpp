#include<bits/stdc++.h>
using namespace std;


void power(int F[2][2], int n);
void multiply(int F[2][2], int M[2][2]);

int fibo(int n)
{
	int F[2][2]={{1,1},{1,0}};

	if(n==0)
		return 0;

	power(F, n-1);

	return F[0][0];
}

void power(int F[2][2], int n)
{
	int M[2][2]={{1,1},{1,0}};

	for(int i=2; i<=n; i++)
		multiply(F,M);
}

void multiply(int F[2][2], int M[2][2])
{
	int x, y, z, w;

	x = F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  	y = F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  	z = F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  	w = F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
  	F[0][0] = x; 
  	F[0][1] = y; 
  	F[1][0] = z; 
  	F[1][1] = w; 
}

int main()
{
	freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
	freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);

	int n;
	while(cin>>n)
	{
		cout<<fibo(n)<<endl;
	}
	return 0;
}