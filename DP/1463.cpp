#include<iostream>
#include<cstring>
#define MAX 1000001
using namespace std;

long dp[MAX];
void init() {
    memset(dp, 1000000, sizeof(dp));
}
long min(long a, long b) {
    if(a<=b) {
        return a;
    }

    return b;
}

void logic(int N) {
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
}

int main() {
    int N;
    cin>>N;

    init();
    dp[1] = 0;
    logic(N);
    
    cout<<dp[N]<<"\n";
}