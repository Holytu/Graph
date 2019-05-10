#include <iostream>
#include <stack>
using namespace std;
class Graph
{
	int count;
	stack<int> s1, s2;
public:
	Graph();
	void addEdge(int u, int v);
};
Graph::Graph()
{

}
void Graph::addEdge(int u, int v)
{
	count = 0;
	int c;
	bool former = false, latter = false;

	if(s1.empty() == true && u != v)
	{
		//cout<<"u = "<<u<<", v = "<<v<<endl;
		//s1.push(u);
		//s1.push(v);
	}
	else if(s1.empty() == false && u != v)
	{
		//cout<<"u = "<<u<<", v = "<<v<<endl;

		while(s1.empty() == false)
		{
			c = s1.top();s1.pop();
			s2.push(c);
			//cout<<"c = "<<c<<endl;

			if(c == u)
			{
				count = count + 1;
				former = true;
			}
		}
		while(s2.empty() == false)
		{
			c = s2.top();s2.pop();
			s1.push(c);
		}

		while(s1.empty() == false)
		{
			c = s1.top();s1.pop();
			s2.push(c);
			//cout<<"c = "<<c<<endl;

			if(c == v)
			{
				count = count + 1;
				latter = true;
			}
		}
		while(s2.empty() == false)
		{
			c = s2.top();s2.pop();
			s1.push(c);
		}
	}

	if(count == 2)
		cout<<"Cycle"<<endl;
	else
	{
		if(former == false)
		{
			s1.push(u);
		}
		if(latter == false)
		{
			s1.push(v);
		}
		cout<<"Fine"<<endl;
	}
	//cout<<count<<endl;
}
int main()
{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);

	g.addEdge(1, 2);

	return 0;
}