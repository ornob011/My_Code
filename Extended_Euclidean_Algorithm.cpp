#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
	if(a==0)
	{
		x=0;
		y=1;

		return b;
	}

	int x1, y1;
	int d=gcd(b%a, a, x1, y1);
	x=y1-(b/a)*x1;

	y=x1;

	return d;
}

int main()
{
	int a=12, b=8, x, y;

	int d=gcd(a, b, x, y);

	printf("%d * %d + %d * %d = %d\n", x,a,y,b,d);

	return 0;
}
