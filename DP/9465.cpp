#include<iostream>
#include<cstring>
using namespace std;
int n;
int map[2][100001];
long long dp[2][100001];
long long logic(int N) {
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = map[0][1];
    dp[1][1] = map[1][1];

    for(int i=2; i<=N; i++) {
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + map[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + map[1][i];
    }
    long long result = max(dp[0][N], dp[1][N]);
    return result;
}

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        bzero(map,sizeof(map));
        bzero(dp, sizeof(dp));
        cin>>n;
        for(int j=0; j<2; j++) {
            for(int k=1;k<=n;k++) {
                cin>>map[j][k];
            }
        }
        cout<<logic(n)<<"\n";
    }

}