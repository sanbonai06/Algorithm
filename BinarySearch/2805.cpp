#include<iostream>
#define MAX 1000000
using namespace std;

long N, M;
long tree[MAX];
long max_num = 0;
long max(long a, long b) {
    if(a>=b) {
        return a;
    }
     return b;
}

bool possibleH(long height) {
    long res = 0;
    for(int i=0; i<N; i++) {
        if(tree[i] > height) {
            res += tree[i]-height;
        }
    }
    if(res >= M) {
        return true;
    }
    return false;
}

long logic() {
    long left = 0;
    long right = max_num;
    long mid = 0;
    long result = 0;
    while(left<=right) {
        mid = (right+left)/2;
        if(possibleH(mid)) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    cin>>N>>M;
    for(long i=0; i<N; i++) {
        cin>>tree[i];
        max_num = max(max_num, tree[i]);
    }
    cout<<logic()<<"\n";
}