#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {
    return b<a;
}

int main() {
    int S;
    cin>>S;
    int a[S];
    int b[S];
    for(int i=0; i<S; i++) {
        cin>>a[i];
    }
    for(int i=0; i<S; i++) {
        cin>>b[i];
    }

    sort(a,a+S);
    sort(b, b+S, compare);
    int res = 0;
    for(int i=0; i<S; i++) {
        res += a[i]*b[i];
    }
    cout<<res;
}