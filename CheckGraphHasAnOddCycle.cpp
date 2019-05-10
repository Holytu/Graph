#include <iostream>
#include <queue>
#define V 4
using namespace std;
bool containOddPath(int G[][V], int src)
{
	int *visited = new int[V];
	queue<int> q;

	for (int i = 0; i < V; i++)
		visited[i] = -1;//

	q.push(src);
	visited[src] = 1;

	int x;
	while(q.empty() != true)
	{
		x = q.front();
		q.pop();

		if(G[x][x] == 1)
			return true;

		for (int j = 0; j < V; j++)
		{
			if(G[x][j] == 1 && visited[j] == -1)
			{
				q.push(j);
				visited[j] = 1 - visited[x];	//
			}
			else if(G[x][j] == 1 && visited[j] == visited[x])//
			{
				return true;
			}
		}
	}
	return false;

}
int main(int argc, char const *argv[])
{
	int G[][V] = {
		{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
   	cout<<containOddPath(G, 0)<<endl;
    //containOddPath(G, 0) ? cout << "Yes" : cout << "No"; 
    return 0; 
}