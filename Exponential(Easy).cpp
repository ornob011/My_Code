#include<bits/stdc++.h>
using namespace std;

#define llu unsigned long long

llu solve(llu base, llu power)
{
    llu res;
    if(power==0)
        return 1;
    else if(power&1)
    {
        res=solve(base, power-1);
        return res*base;
    }
    else
    {
        res=solve(base, power>>1);
        return res*res;
    }
}
int main()
{
    llu base, power;
    while(cin>>base>>power)
    {
        cout<<solve(base, power)<<endl;
    }
    return 0;
}