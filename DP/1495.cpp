#include<iostream>
#include<cstring>
using namespace std;
int N,S,M;
int main() {
    cin>>N>>S>>M;
    int v[N+1];
    bool dp[N+1][M+1];
    bzero(dp, sizeof(dp));
    for(int i=1; i<=N; i++) {
        cin>>v[i];
    }
    dp[0][S] = true;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=M; j++) {
            if(dp[i-1][j]) {
                if(j+v[i] <= M) dp[i][j+v[i]] = true;
                if(j-v[i] >= 0) dp[i][j-v[i]] = true;
            }
        }
    }
    
    for(int i=M; i>=0; i--) {
        if(dp[N][i]) {
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";
}