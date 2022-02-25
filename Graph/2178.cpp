#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int map[100][100];
int visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// void init() {
//     memset(map, -1, sizeof(map));
//     memset(visited, 0, sizeof(visited));
// }

int logic() {
    visited[0][0]=1;
    queue<pair <int,int> > q;
    q.push(pair<int,int>(0,0));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            if(x+dx[i]>=0 && y+dy[i]>=0 && x+dx[i]<N && y+dy[i]<M && visited[x+dx[i]][y+dy[i]] == -1) {
                if(map[x+dx[i]][y+dy[i]] == 1) {
                    visited[x+dx[i]][y+dy[i]] = visited[x][y] + 1;
                    q.push(pair<int,int>(x+dx[i],y+dy[i]));
                }
            }
        }
    }

    return visited[N-1][M-1];
}

int main() {

    //init();
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            visited[i][j]=-1;
            scanf("%1d", &map[i][j]);
        }
    }
    
    cout<<logic()<<"\n";
}