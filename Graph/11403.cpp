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

void floyd() {
    for (int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            for(int k=1; k<=N; k++) {
                if(adjmat[j][i] && adjmat[i][k]) {
                    adjmat[j][k] = true;
                }
            }
        }
    }
}

int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        for(int j=1;j<=N;j++) {
            cin>>map[i][j];
            if(map[i][j] == 1) {
                adjmat[i][j] = true;
            }
        }
    }
    // for(int i=1; i<=N; i++) {
    //     logic(i, i);
    //     memset(visited, false, sizeof(visited));
    // }
    floyd();
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cout<<adjmat[i][j]<<" ";
        }
        cout<<"\n";
    }
}