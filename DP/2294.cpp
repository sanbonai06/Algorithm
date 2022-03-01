#include<iostream>
#include<cstring>
#define INF 100001
using namespace std;
int n, k;
int coin[101];
int dp[100001];

// void logic() {
//     dp[0] = 1;
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<=k; j++) {
//             if(coin[i]<=j) {
//                 dp[j] = dp[j] + dp[j-coin[i]];
//             }
//         }
//     }
// }
void init() {
    for(int i=0; i<=k; i++) {
        dp[i] = INF;
    }
}

void logic() {
    init();
    dp[0] = 0;
    for(int i=0; i<=k; i++) {
        for(int j=0; j<n; j++) {
            if(coin[j] <= i) {
                dp[i] = min(dp[i], dp[i-coin[j]] + 1);
            }
        }
    }
}

int main() {
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cin>>coin[i];
        dp[coin[i]] = 1;
    }
    logic();
    if(dp[k] == INF) cout<<-1<<"\n";
    else cout<<dp[k]<<"\n";
    // for(int i=0; i<=k; i++) {
    //     cout<<dp[i]<<" ";
    // }
}