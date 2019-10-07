#include <bits/stdc++.h>
using namespace std;

#define max 100
static int V;

void dijkstra(int graph[][max], int src);

int minDistance(int dist[], bool set[])
{
    int min = INT_MAX, min_index;

    for (int v = 1; v <= V; v++)
        if (set[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 1; i <= V; i++)
        printf("%d \t\t %d\n", i, dist[i] - 1);
}

void dijkstra(int graph[][max], int src)
{
    int dist[V];

    bool set[V];

    for (int i = 1; i <= V; i++)
    {
        dist[i] = INT_MAX;
        set[i] = false;
    }

    dist[src] = 1;

    for (int count = 1; count <= V - 1; count++)
    {
        int u = minDistance(dist, set);

        set[u] = true;

        for (int v = 1; v <= V; v++)
        {
            if (!set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist);
}

int main()
{
    int src;

    cout << "Enter number of vertices: " << endl;
    cin >> V;

    int graph[max][max];

    cout << "Enter adjacent matrix: " << endl;
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            cin >> graph[i][j];

    cout << "Enter source path: " << endl;
    cin >> src;

    dijkstra(graph, src);

    return 0;
}