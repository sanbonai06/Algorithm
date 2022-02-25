#include<iostream>
#define MAX 1000000
using namespace std;

long K,N;
long ran[MAX];
long max_num = 0;
long max(long a, long b){
    if(a>=b) {
        return a;
    }
    return b;
}


int main() {
    cin>>K>>N;
    for(long i=0; i<K; i++) {
        cin>>ran[i];
        max_num = max(max_num, ran[i]);
    }

    long left = 1;
    long right = max_num;
    long result = 0;

    while(left <= right) {
        long tmp = 0;
        long mid = (left+right)/2;
        for(long i=0; i<K; i++) {
            tmp += ran[i]/mid;
        }
        if(tmp >= N) {
            left = mid + 1;
            result = mid;
        }
        else {
            right = mid - 1;
        }
    }
    cout<<result<<"\n";
}