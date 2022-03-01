#include<iostream>
#include<cstring>
#define MOD 9901
using namespace std;

int N;
long long dp[100001][3];

void logic() {
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i = 2; i<=N; i++) {
        dp[i][0] = dp[i-1][1]%MOD + dp[i-1][2]%MOD;
        dp[i][1] = dp[i-1][0]%MOD + dp[i-1][2]%MOD;
        dp[i][2] = dp[i-1][0]%MOD + dp[i-1][1]%MOD + dp[i-1][2]%MOD;
    }

}

int main() {
    cin>>N;
    logic();
    long long result = 0;
    result = dp[N][0]%MOD + dp[N][1]%MOD + dp[N][2]%MOD;
    cout<<result%MOD<<"\n";
}