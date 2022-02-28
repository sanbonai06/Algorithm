#include<iostream>
#include<cstring>
using namespace std;

double dp[31];
double factorial(int n) {
    dp[1] = 1;
    if(n==0) return 1;
    if(n == 1) {
        return dp[1];
    }
    else if(dp[n] != 0) return dp[n];
    else {
        return dp[n] = n*factorial(n-1);
    }
}
double combination(int n, int m) {
    return factorial(n) / (factorial(n - m)*factorial(m));
}
int main() {
    int N;
    int L,R;
    cin>>N;
    for(int i=0; i<N; i++) {
        long long d = 1;
        cin>>L>>R;
        for(int j=0; j<L; j++) {
            d*=R-j;
            d/=1+j;
        }
        cout<<d<<"\n";
    }
}