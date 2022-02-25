#include<iostream>
#include<cstring>
using namespace std;

int day[16];
int price[16];
int dp[16];
int N;

int max(int a, int b) {
    if(a>=b) {
        return a;
    }
    
    return b;
}

void init() {
    bzero(day,sizeof(day));
    bzero(price, sizeof(price));
    bzero(dp, sizeof(dp));
}

int logic() {

    for(int i=2; i<=N;i++) {
        for(int j=1;j<i;j++){
            if(i - j >= day[j]) {
                dp[i]=max(dp[i], price[i] + dp[j]);
            }
        }   
    }

    int result = 0;
    for(int i = 1; i<=N; i++) {
        if(i+day[i] <= N+1)
            result = max(result, dp[i]);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T,P;

    cin>>N;
    init();
    for(int i=1; i<=N; i++) {
        cin>>day[i]>>price[i];
        dp[i]=price[i];
    }

    cout<<logic()<<"\n";

}