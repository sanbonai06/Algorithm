#include<iostream>
#include<cstring>
#define INF 10001
using namespace std;

int N,D;
int dp[10001];
struct shortCut{
    int start;
    int end;
    int len;
};

struct shortCut s[12];

void logic() {
    for(int i=0; i<=D; i++) {
        for(int j=0; j<sizeof(s); j++) {
            if(s[j].start == i) {
                int e = s[j].end;
                dp[e] = min(dp[e], dp[i]+s[j].len);
            }
        }
        if(i!=0)
            dp[i] = min(dp[i],dp[i-1]+1);
    }
}

int main() {
    cin>>N>>D;

    for(int i=0; i<N; i++) {
        int a, b, c;
        cin>>s[i].start>>s[i].end>>s[i].len;
    }
    memset(dp, INF, sizeof(dp));
    dp[0]=0;
    logic();
    cout<<dp[D];
}