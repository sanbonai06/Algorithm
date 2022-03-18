#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
 
struct disJoinSet{
  vector<int>parent,rank;
  disJoinSet(int n): parent(n+1),rank(n+1,1){
    for(int i=0;i<=n;i++)       
    {
      parent[i]=i;
    }
  }
  int find(int u){
    if(u==parent[u]) return u;  //본인이 루트노드일 때, 
    else{
    	parent[u]=find(parent[u]);
    	return parent[u];
    }
  }
  void merge(int u,int v){
    u=find(u); v=find(v);	//루트로
    if(u==v) return;
    if(rank[u]>rank[v]) //트리의 높이 비교
        swap(u,v);
    parent[u]=v;  //노드 연결
    if(rank[u]==rank[v]) rank[v]++;
  }
};
 
int main()
{
  ios::sync_with_stdio(0); 
  cin.tie(NULL);
  int N,M;
  cin>>N>>M;
  disJoinSet set(N);
  int s,a,b;
  for(int i=0;i<M;i++)
  {
    cin>>s>>a>>b;
    if(s==0) set.merge(a,b);
    else if(s==1){
      if(set.find(a)==set.find(b))
      cout<<"YES"<<"\n";
      else
      cout<<"NO"<<"\n";
    }
  }
}