#include<iostream>
#include<queue>
using namespace std;

int N,M;
bool adjmat[1001][1001];
bool visited_DFS[1001];
bool visited_BFS[1001];
void BFS(int v) {
	visited_BFS[v]=true;
	queue <int> q;
	q.push(v);
	while(!q.empty()){
		v=q.front();
		cout<<v<<" ";
		q.pop();
		for(int i=0;i<1001;i++){
		if(adjmat[v][i]&&!visited_BFS[i])
		{
			q.push(i);
			visited_BFS[i]=true;
		}
	}
	}
}

void DFS(int v)
{
	visited_DFS[v]=true;
	cout<<v<<" ";
	for(int j=0;j<1001;j++)
	{
		if(adjmat[v][j]&& !visited_DFS[j])
		{
			DFS(j);
		}
	}
}

int main()
{
	int V,a,b;
	cin>>N>>M>>V;
	for(int i=0;i<M;i++)
	{
		cin>>a>>b;
		adjmat[a][b]=adjmat[b][a]=true;
	}
	DFS(V); cout<<endl;
	BFS(V); cout<<endl;
}