#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int N;
    int man[11];
    cin>>N;
    int s[N+1];
    bzero(s, sizeof(s));
    for(int i=1; i<=N; i++) {
        cin>>man[i];
    }
    for(int i=1; i<=N; i++) {
        int a = man[i];
        int j = 0;
        while(1) {
            if(a==0&&s[j]==0) {
                s[j] = i;
                break;
            }
            if(s[j] == 0) {
                a--;
            }
            j++;
        }
    }
    for(int i=0; i<N; i++) {
        cout<<s[i]<<" ";
    }
}