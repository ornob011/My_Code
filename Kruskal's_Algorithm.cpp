#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int source, dest, weight;
};

bool cmp(struct Edge e1, struct Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
        return v;

    return findParent(parent[v], parent);
}

void kruskals(struct Edge *input, int vertice, int edge)
{
    sort(input, input + edge, cmp);

    Edge *output = new Edge[vertice - 1];
    int *parent = new int[vertice];

    for (int i = 0 ; i < vertice; i++)
        parent[i] = i;

    int count = 0, i = 0, weight=0;

    while (count != vertice - 1 && i<edge)
    {
        struct Edge currentEdge = input[i];

        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;

            parent[sourceParent] = destParent;
            weight+=currentEdge.weight;    
        }
        i++;
    }

    for (int i = 0; i < count; i++)
    {
        if (output[i].source < output[i].dest)
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        else
           cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
   }
   cout<<"Weight: "<<weight<<endl;
}
int main()
{
    freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
    freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);
    
    int vertice, edge;
    // cout << "Enter number of vertices: ";
    cin >> vertice;
    // cout << "Enter number of edges: ";
    cin >> edge;
    

    struct Edge *input = new Edge[edge];

    for (int i = 0; i < edge; i++)
        cin >> input[i].source >> input[i].dest >> input[i].weight;

    cout << "MST: " << endl;
    kruskals(input, vertice, edge);
    return 0;
}