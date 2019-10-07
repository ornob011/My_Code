#include<bits/stdc++.h>
using namespace std;

struct DisjSet
{
    int *parent, *rank, n;

    DisjSet(int n)
    {
        parent=new int[n];
        rank=new int[n];
        this->n=n;

        makeSet();
    }
    void makeSet()
    {
        for(int i=0; i<n; i++)
            parent[i]=i;
    }

    int find(int i)
    {
        if(parent[i]==i)
            return i;

        else
        {
            int result=find(parent[i]);
            parent[i]=result;

            return result;
        }

    }

    void Union(int x, int y)
    {
        int xRep=find(x);
        int yRep=find(y);

        if(xRep==yRep)
            return;

        int xRank=rank[xRep];
        int yRank=rank[yRep];

        if(xRank<yRank)
            parent[xRep]=yRep;

        else if(xRank>yRank)
            parent[yRep]=xRep;

        else
        {
            parent[xRep]=yRep;
            rank[yRep]++;
        }
    }
};


int main()
{
    // freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
    // freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);

    int n, x;
    int arr[1000];
    cout<<"How many elements:"<<endl;
    cin>>n;

    struct DisjSet obj(n);

    for(unsigned int i=0; i<n; i++)
    {
        cin>>x;
        arr[x]=x;
    }

    obj.Union(arr[0], arr[2]);
    obj.Union(arr[4], arr[2]);
    obj.Union(arr[3], arr[1]);

    if (obj.find(arr[4]) == obj.find(arr[0]))
        cout << "Yes\n";
    else
        cout << "No\n";

    if (obj.find(arr[1]) == obj.find(arr[0]))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}