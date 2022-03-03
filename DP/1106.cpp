#include<iostream>
#include<cstring>
#define INF 100001
using namespace std;
int C, N;
int cost[21];
int host[21];
int dp[1001];
int result = INF;
int main() {
    cin>>C>>N;
    for(int i=0; i<N; i++) {
        cin>>cost[i]>>host[i];
        if(dp[host[i]] != 0) {
            dp[host[i]] = max(dp[host[i]], cost[i]);
        }
        else dp[host[i]] = cost[i];
    }
    for(int i=1; i<=1000; i++) {
        for(int j=0; j<N; j++) {
            int d = 0;
            while(1){
                d++;
                if(d*host[j]<=i) {
                    if(dp[i] != 0)
                        dp[i] = min(dp[i-d*host[j]] + d*dp[host[j]], dp[i]);
                    else dp[i] = dp[i-d*host[j]] + d*dp[host[j]];
                }
                else break;
            }
        }
        if(i>=C) {
            if(result>dp[i]) cout<<i<<"\n";
            result = min(result, dp[i]);
        }
    }
    cout<<result<<"\n";
}