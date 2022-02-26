#include<iostream>
#include<cstring>
#define MOD 10007
using namespace std;

int N;
long dp[1001][10];
int result = 0;
void init() {
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<10; i++) {
        dp[1][i] = 1;
    }

}

void logic() {
    for(int i=2; i<=N; i++) {
        for(int j=0; j<10; j++) {
            if(j==0) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i-1][j]%MOD + dp[i][j-1]%MOD;
            }
        }
    }
}

int main() {
    init();
    cin>>N;
    logic();

    for(int i=0; i<10; i++) {
        result+=dp[N][i]%MOD;
    }
    cout<<result%MOD<<"\n";
}