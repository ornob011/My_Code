#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nth, count=9, temp, num, i, rev;

    cin>>nth;

    if(nth>=1 && nth<=9)
    {
        cout<<nth<<"th palindrome = "<<nth<<endl;
        return 0;
    }
    for(i=10; ; i++)
    {
        rev=0;
        temp=i;
        num=temp;

        while(temp>0)
        {
            rev=rev*10+temp%10;
            temp=temp/10;
        }
        
        if(rev==num)
        {
            count++;
            if(count==nth)
            {
                cout<<nth<<"th palindrome = "<<num<<endl;
                break;
            }        
        }
    }

    return 0;
}