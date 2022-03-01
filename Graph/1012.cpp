#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int map[51][51];
bool visited[51][51];
int c=0;
void init() {
    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));
}

void logic(int x, int y, int n, int m) {
    visited[x][y] = true;
    queue<pair <int, int> > q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int tx = cx+dx[i];
            int ty = cy+dy[i];
            if(tx>=0 && ty>=0 && tx<n && ty<m) {
                if(map[tx][ty] == 1 && !visited[tx][ty]) {
                    visited[tx][ty] = true;
                    q.push(make_pair(tx,ty));
                }
            }
        }
    }
}

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        int M,N,K;
        int cnt = 0;
        cin>>M>>N>>K;
        for(int j=0; j<K; j++) {
            int a, b;
            cin>>b>>a;
            map[a][b] = 1;
        }
        for(int j=0; j<N; j++) {
            for(int d=0; d<M; d++) {
                if(map[j][d] == 1 && !visited[j][d]) {
                    logic(j,d,N,M);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
        init();
    }
}