#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N;
int map[101][101];
bool adjmat[101][101];
bool result[101][101];
bool visited[101];

void init() {
    memset(map, -1, sizeof(map));
    memset(adjmat, false, sizeof(adjmat));
    memset(result, false, sizeof(result));
    memset(visited, false, sizeof(visited));
}

void logic(int v, int n) {
    for(int i=1; i<=N; i++) {
        if(adjmat[n][i] && !visited[i]) {
            visited[i] = true;
            result[v][i] = true;
            result[n][i] = true;
            logic(v, i);
            // for(int j=i; j<=N; j++) {
            //     if(result[i][j]){
            //         result[v][j] = true;
            //     }
            //     if(result[v][j]) {
            //         result[v][i] = true;
            //     }
            // }
        }
    }
}

int main() {
    init();
    cin>>N;
    for(int i=1; i<=N; i++) {
        for(int j=1;j<=N;j++) {
            cin>>map[i][j];
            if(map[i][j] == 1) {
                adjmat[i][j] = true;
            }
        }
    }
    for(int i=1; i<=N; i++) {
        logic(i, i);
        memset(visited, false, sizeof(visited));
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}