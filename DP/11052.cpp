#include<iostream>
using namespace std;

int N;
int p[10001];
int dp[10001];
int max(int a, int b) {
    if(a>=b) {
        return a;
    }
    return b;
} 

int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>p[i];
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            if(i == 1) dp[i] = p[i];
            else dp[i] = max(dp[i], dp[i-j]+p[j]);
        }
    }
    cout<<dp[N]<<"\n";
}