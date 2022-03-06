#include<iostream>
using namespace std;
int N, M;
int main() {
    cin>>N>>M;
    int map[N][M];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    int res = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            for(int k=1; k<min(N,M); k++) {
                if(i+k < N && j+k < M) {
                    if(map[i][j+k] == map[i][j] && map[i+k][j] == map[i][j] && map[i+k][j+k] == map[i][j]) {
                        res = max(res, (k+1)*(k+1));
                    }
                }
            }
        }
    }
    cout<<res;
}