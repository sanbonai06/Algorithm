#include<iostream>
#include<cstring>
#define INF 1000000
using namespace std;
int N;
int price[1001][3];
long long dp[1001][3];
void init() {
    memset(dp, INF, sizeof(dp));
    dp[1][0] = price[1][0];
    dp[1][1] = price[1][1];
    dp[1][2] = price[1][2];
}
void logic() {
    init();
    for(int i=2; i<=N; i++) {
        for(int j=0; j<3; j++) {
            if(j == 0)
                dp[i][j] = min(dp[i][j], min(dp[i-1][1] + price[i][j], dp[i-1][2] + price[i][j]));
            else if(j == 1) 
                dp[i][j] = min(dp[i][j], min(dp[i-1][0] + price[i][j], dp[i-1][2] + price[i][j]));
            else if(j == 2)
                dp[i][j] = min(dp[i][j], min(dp[i-1][0] + price[i][j], dp[i-1][1] + price[i][j]));
        }
    }
}
int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<3; j++) {
            cin>>price[i][j];
        }
    }
    logic();
    long long result;
    result = min(dp[N][0], min(dp[N][1], dp[N][2]));
    cout<<result<<"\n";
}