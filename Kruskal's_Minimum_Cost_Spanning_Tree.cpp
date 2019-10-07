#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int source, dest, weight;
};

struct subset
{
    int parent, rank;
};

bool cmp(struct Edge e1, struct Edge e2)
{
    return e1.weight < e2.weight;
}

int find(struct subset *subsets, int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset *subsets, int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;

    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskals(struct Edge *input, int vertice, int edge)
{
    sort(input, input + edge, cmp);

    Edge *output = new Edge[vertice - 1];
    struct subset *subsets = new subset[edge];

    for (int i = 0 ; i < vertice; i++)
    {
        subsets[i].parent = i; 
        subsets[i].rank = 0; 
    }

    int count = 0, i = 0, weight=0;

    while (count != vertice - 1 && i<edge)
    {
        struct Edge currentEdge = input[i];

        int sourceParent = find(subsets, currentEdge.source);
        int destParent = find(subsets, currentEdge.dest);

        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;

            Union(subsets, sourceParent, destParent);
            
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
    cout << "Enter number of vertices: ";
    cin >> vertice;
    cout << "Enter number of edges: ";
    cin >> edge;
    

    struct Edge *input = new Edge[edge];

    for (int i = 0; i < edge; i++)
        cin >> input[i].source >> input[i].dest >> input[i].weight;

    cout << "MST: " << endl;
    kruskals(input, vertice, edge);
    return 0;
}