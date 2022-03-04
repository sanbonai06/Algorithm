#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
int main() {
    cin>>N;
    int t[N+1];
    memset(t, 0, sizeof(t));
    for(int i=1; i<=N; i++) {
        cin>>t[i];
    }
    sort(t+1, t+N+1);
    int i;
    for(i=N; i>=2; i--)
    {
        if(t[i] < t[i-1] + t[i-2]) {
            cout<<t[i] + t[i-1] + t[i-2]<<"\n";
            return 0;
        }

    }
    cout<<-1<<"\n";
}   