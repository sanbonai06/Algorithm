#include<iostream>
#include<cstring>
#include<math.h>
#define default 100000
using namespace std;

int dp[100001];
int p[default];
int idx = 0;

int min(int a, int b) {
    if(a<=b) {
        return a;
    }
    return b;
}
int logic(int N) {
    for(int i=1; i<=N; i++) {
        double a = sqrt(i); 
        if(a == (int)a) {
            ++idx;
            dp[i]=1;
            p[idx] = i;
        }
        else {
            int b = pow((int)a, 2);
            int result = default;
            for(int j = idx; j>0 ; j--) {
                int c = p[j];
                result = min(result, dp[c] + dp[i-c]);
            } 
            dp[i]=result;
        }
    }
    return dp[N];
}

int main() {
    int N;
    cin>>N;
    
    cout<<logic(N)<<"\n";
}