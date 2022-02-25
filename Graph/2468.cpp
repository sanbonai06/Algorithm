#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N;
int cnt = 0;
int map[100][100];
bool visited[100][100];
bool water[100][100];   //false: 침수 true: 이동가능
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
    memset(visited, 0, sizeof(visited));
    memset(water, 1, sizeof(water));
}

// void logic_bfs(int x, int y, int h) {
//     visited[x][y] = 1;
//     queue<pair <int, int> >q;
//     q.push(pair<int,int>(x,y));
//     for(int i=0; i<4; i++) {
//         int tx = q.front().first+dx[i];
//         int ty = q.front().second+dy[i];
//         q.pop();
//         if(tx < N && ty < N && tx >=0 && ty >=0) {
//             if(map[tx][ty] <= N && !visited[tx][ty]) {
//                 visited[tx][ty] = true;
//                 q.push(pair<int,int>(tx,ty));
//             }
//         }
//     }
// }

void rainLand(int h) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] <= h) {
                water[i][j] = false;
            }
        }
    }
}

void logic_dfs(int x, int y) {
    visited[x][y] = true;
    for(int i=0; i<4; i++) {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(tx < N && ty < N && tx >=0 && ty >=0) {
            if(!visited[tx][ty] && water[tx][ty]) {
                visited[tx][ty] = true;
                logic_dfs(tx, ty);
            }
        }
    }
}

int max(int a, int b) {
    if(a>=b) {
        return a;
    }

    return b;
}

int main() {
    init();
    cin>>N;
    int max_num = 0;
    int result = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>map[i][j];
            max_num = max(max_num, map[i][j]);
        }
    }
    for(int i=1; i<max_num; i++) {
        rainLand(i);
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                if(water[j][k]&&!visited[j][k]){
                    logic_dfs(j,k);
                    cnt++;
                }
            }
        }
        result = max(result, cnt);
        cnt = 0;
        init();
    }
    cout<<result<<"\n";
}