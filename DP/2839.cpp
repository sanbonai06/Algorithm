#include<iostream>
#include<cstring>
using namespace std;

int N;
int dp[5001];

void init() {
    memset(dp, 0, sizeof(dp));
    dp[3] = 1;
    dp[5] = 1;
}
int min(int a, int b) {
    if(a<=b) {
        return a;
    }
    return b;
}

void logic() {
    for(int i=6; i<=N; i++) {
        if(dp[i-3] != 0 && dp[i-5] != 0) {
            if(dp[i] == 0)
                dp[i] = min(dp[i-3] + 1, dp[i-5] + 1);
            else {
                int tmp = min(dp[i-3] + 1, dp[i-5] + 1);
                dp[i] = min(dp[i], tmp);
            }
        }
        else if(dp[i-3] != 0 && dp[i-5] == 0) {
            if(dp[i] == 0)
                dp[i] = dp[i-3] + 1;
            else {
                dp[i] = min(dp[i], dp[i-3] + 1);
            }
        }
        else if(dp[i-3]==0 && dp[i-5] != 0) {
            if(dp[i] == 0)
                dp[i] = dp[i-5] + 1;
            else {
                dp[i] = min(dp[i], dp[i-5] + 1);
            }
        }
    }
}

int main() {
    cin>>N;
    init();
    logic();
    if(dp[N] == 0) cout<<-1<<"\n";
    else cout<<dp[N]<<"\n";
}