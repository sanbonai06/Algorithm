#include<iostream>
#include<cstring>
#define MAX 1000000
using namespace std;
long long dp[MAX];

long long fibo(int n) {
    if(n==1) return 1;
    if(n==2) return 1;

    if(dp[n] != -1) return dp[n];
    else if(dp[n] == -1) {
        return dp[n] = fibo(n-1) + fibo(n-2);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    int a;
    cin>>a;
    cout<<fibo(a)<<endl;
}