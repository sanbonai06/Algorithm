#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001
#define INF 1e9
using namespace std;
int N,M;
vector<pair <int, int> >adj[MAX];

int logic(int s, int d) {
    vector<int> dist(N+1, INF);
    dist[s] = 0;
    priority_queue<pair<int, int> >pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist[d];
}

int main() {
    int start, dist;
    cin>>N>>M;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
    }
    cin>>start>>dist;
    cout<<logic(start, dist)<<"\n";
}