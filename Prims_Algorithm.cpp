#include<bits/stdc++.h>
using namespace std;
#define inf 999

void print(int source, int dest, int weight)
{
	cout << source <<  " - " << dest << " :  " << weight;
	cout << endl;
}

void prim(int **graph, int V)
{
	int no_edge=0;
	bool selected[V];
	int i, j;

	memset(selected, false, sizeof(selected));

	selected[0]=true;

	int source, dest;

	cout << "Edge" << "  : " << "Weight";
	cout << endl;
	while (no_edge < V - 1)
	{
		int min=9999;
		source=0;
		dest=0;

		for(i=0; i<V; i++)
		{
			if(selected[i])
			{
				for(j=0; j<V; j++)
				{
					if(selected[j]==false && graph[i][j])
					{
						if(graph[i][j]<min)
						{
							min=graph[i][j];
							source=i;
							dest=j;

						}
					}
				}
			}
		}
		print(source, dest, graph[source][dest]);
		selected[dest]=true;
		no_edge++;
	}

}

int main()
{
	freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
	freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);

	int V, i, j;

	cout<<"Enter number of vertices:"<<endl;
	cin>>V;
	cout<<"Enter the graph:"<<endl;
	int **graph=new int*[V];

	for(i=0; i<V; i++)
		graph[i]=new int[V];

	for(i=0; i<V; i++)
	{
		for(j=0; j<V; j++)
			cin>>graph[i][j];
	}

	prim(graph, V);
	
	return 0;
}



