#include<iostream>
#include<vector>
#include<queue>
#define MAX 20001
#define INF 1e9
using namespace std;
vector<pair<int, int> > adj[MAX];
int V,E,K;

// vector<int> logic(int src,int v)
// {
//   vector<int> dist(v+1,INF);  //정점의 개수,INF로 초기화
//   dist[src]=0;  //시작점 거리 0으로 초기화
//   priority_queue<pair<int,int> > pq;
//   pq.push(make_pair(0,src));  //우선순위 큐에 삽입
//   while(!pq.empty())
//   {
//     int cost=-pq.top().first;
//     int here=pq.top().second;
//     pq.pop();
//     if(dist[here]<cost) continue;   //지금 꺼낸 것 보다 더 작은 경로를 알고 있다면 건너뜀
//     for(int i=0;i<adj[here].size();i++)
//     {
//       int there=adj[here][i].first;
//       int nextDist=cost+adj[here][i].second;
//       if(dist[there]>nextDist){
//         dist[there]=nextDist;
//         pq.push(make_pair(-nextDist,there));
//       }
//     }
//   }
//   return dist;
// }

vector<int> logic(int src, int v) {
    vector<int> dist(v+1, INF);
    dist[src] = 0;
    priority_queue<pair <int, int> > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here]<cost) continue;
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost+adj[here][i].second;
            if(dist[there]>nextDist) {
                dist[there]=nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {

    cin>>V>>E;
    cin>>K;
    vector<int> table;
    for(int i=0; i<E; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
    }
    table = logic(K, V);
    for(int i=1; i<table.size(); i++) {
        if(table[i]==INF) printf("INF");
  	    else printf("%d",table[i]);
  	    printf("\n");
    }
}