#include<bits/stdc++.h>
using namespace std;

int power(int a, int n)
{
    if(n==0)
        return 1;
    
    int res=power(a, n/2);

    if(n & 1)
        return a*res*res;
    
    return res*res;
}


int main()
{

	//freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
	//freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);
    
	int a, n, choice, res;

    while(1)
    {
		cout<<"Enter choice:\n1.Recursion\n2.Iterative"<<endl;
		cin>>choice;

		cout<<"Input base and power"<<endl;
   		cin>>a>>n;

    	switch(choice)
    	{
    		case 1: cout<<power(a, n)<<endl<<endl;
    				break;

    		case 2: res=1;
    				while(n>0)
    				{
    					if(n&1)
    						res=res*a;
    					a=a*a;
    					n=n>>1;
    				}
    				cout<<res<<endl<<endl;
    				break;

    		default: cout<<"Invalid choice"<<endl;
    				 break;
    	}
    }
    return 0;
}
