#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int N;
int dp[31];
void logic() {
    dp[2] = 3;
    dp[4] = 11;
    for(int i=6; i<=N; i++) {
        if(i%2 == 1) dp[i] = 0;
        else {
            dp[i] = dp[i-2] * 3 + 2;
            for(int j=i-4; j>=2; j-=2)
                dp[i] += dp[j] * 2;
        }
    }
}
int main() {
    cin>>N;
    logic();
    cout<<dp[N]<<"\n";
}