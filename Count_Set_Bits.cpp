#include<bits/stdc++.h>
using namespace std;

int countbits(int n)
{
	int count=0;
	while(n>0)
	{
		n=n & (n-1);
		count++;
	}
	return count;
}

int main()
{
	freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
	freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);

	int a;

	cin>>a;

	cout<<countbits(a)<<endl;
	
	return 0;
}