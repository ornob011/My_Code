#include<bits/stdc++.h>
using namespace std;


int getways(int set[], int amount, int total)
{
    int ways[amount+1][total+1];
    int i, j;

    for(i=0; i<=amount; i++)
        ways[i][0] = 1;

    for(i=1; i<=total; i++)
        ways[0][i] = 0;

    for(i=1; i<=amount; i++)
    {
        for(j=1; j<=total; j++)
        {
            if(set[i-1]>j)
                ways[i][j]=ways[i-1][j];

            else
                ways[i][j]=ways[i-1][j]+ways[i][j-set[i-1]];
        }
    }

    cout<<"Matrix:"<<endl;
    for(i=0; i<=amount; i++)
    {
        for(j=0; j<=total; j++)
            cout<<ways[i][j]<<" ";

        cout<<endl;
    }

    return ways[amount][total];
}

void print(int result)
{
    cout<<"Solution:"<<endl<<result<<endl;
}


void input()
{
    freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
    freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);

    int amount, i, total;

    cout<<"Enter total number of coins:"<<endl;
    cin>>amount;

    int set[amount];

    cout<<"Enter set of coins:"<<endl;
    for(i=0; i<amount; i++)
        cin>>set[i];

    cout<<"Enter total to make:"<<endl;
    cin>>total;

    print(getways(set, amount, total));

}

int main()
{
    input();

    return 0;
}
