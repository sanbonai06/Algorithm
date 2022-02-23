#include<iostream>
#include<cstring>
using namespace std;

int weight[101];
int value[101];
int dp[101][100001];

int N,K;

int max(int a, int b) {
    if(a>=b) {
        return a;
    }

    return b;
}

int logic() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=K;j++) {
            if(weight[i]<=j) {
                dp[i][j]=max(value[i]+dp[i-1][j-weight[i]], dp[i-1][j]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[N][K];
}

int main() {

    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>weight[i]>>value[i];
    }

    cout<<logic()<<"\n";
}