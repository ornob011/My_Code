#include<bits/stdc++.h>
using namespace std;

#define ll long long

void remainder(string number, ll m)
{
    ll i, mod=0, digit;

    for(i=0; i<number.size(); i++)
    {
        digit=number[i]-'0';
        mod=mod*10+digit;

        mod=mod%m;
    }
    cout<<"Mod: "<<mod<<endl;
}

int main()
{
    string number;
    ll m;
    cout<<"Enter number & denominator:"<<endl;
    cin>>number>>m; 
    remainder(number, m);
    return 0; 
}