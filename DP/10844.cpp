#include<iostream>
#include<cstring>
#define MOD 1000000000
using namespace std;
int N;
long long dp[101][10];

long long max(long long a, long long b) {
    if(a>=b) {
        return a;
    }
    return b;

}

void init() {
    for(int i=1;i<10;i++){
        dp[1][i]=1;
    }
}

long long logic() {
    
    for(int i=2; i<=N; i++) {
        for(int j=0;j<10;j++) {
            if(j == 0) {
                dp[i][j] = dp[i-1][j+1] % MOD;
            }
            else if(j == 9) {
                dp[i][j] = dp[i-1][j-1] % MOD;
            }
            else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
            }
        }
    }

    long long sum=0;
    for(int i=0; i<10; i++) {
        sum += dp[N][i] % MOD;
    }
    return sum%MOD;
}

int main() {
    cin>>N;
    init();
    cout<<logic()<<"\n";
}