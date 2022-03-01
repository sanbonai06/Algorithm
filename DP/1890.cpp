#include<iostream>
#include<cstring>
using namespace std;
int N;
int map[101][101];
long long dp[101][101];

// void logic(int x, int y) {

//     if(map[x][y] == 0) {
//         result++;
//         return;
//     }
//     dp[x][y]++;
//     int dx = x+map[x][y];
//     int dy = y+map[x][y];
//     if(dx >= N && dy >= N)  return;
//     else if(dx >= N && dy < N) {
//         if(dp[x][dy] == 0)
//             logic(x,dy);
//     }
//     else if(dx < N && dy >= N) {
//         if(dp[dx][y] == 0)
//             logic(dx,y);
//     }
//     else {
//         if(dp[dx][y] == 0)
//             logic(dx, y);
//         if(dp[x][dy] == 0)
//             logic(x, dy);
//     }
// }

void logic() {
    dp[0][0] = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(dp[i][j] != 0) {
                if(i == N-1 && j == N-1) continue; 
                else{
                    int d = map[i][j];
                    if(i+d < N)
                        dp[i+d][j] = dp[i][j] +dp[i+d][j];
                    if(j+d < N)
                        dp[i][j+d] = dp[i][j] +dp[i][j+d];
                }
            }
        }
    }
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>map[i][j];
        }
    }
    dp[0][0] = 1;
    logic();
    cout<<dp[N-1][N-1]<<"\n";
}