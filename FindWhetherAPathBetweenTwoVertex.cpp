#include <iostream>
#include <list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isReachable(int s, int d);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}
bool Graph::isReachable(int s, int d)
{
	int u;
	int *visited = new int[this->V];
	list<int> queue;
	list<int>::iterator iter;

	if(s == d)
		return true;
	else
	{
		for (int i = 0; i < this->V; i++)
		visited[i] = false;

		u = s;
		queue.push_back(u);
		visited[u] = true;

		while(queue.empty() == false)
		{
			u = queue.front();
			queue.pop_front();
			for( iter = adj[u].begin() ; iter != adj[u].end() ; iter++ )
			{
				if( !visited[*iter] )
				{
					queue.push_back(*iter);
					visited[*iter] = true;
				}
			}
		}

		for (int i = 0; i < this->V; i++)
		{
			if(visited[i] == false)
				return false;
		}	

		return true;
	}	
}
int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	int u = 1, v = 3;
	cout<<g.isReachable(u,v);
	u = 3; v = 1;
	cout<<"\n"<<g.isReachable(u,v)<<"\n";
	return 0;
}