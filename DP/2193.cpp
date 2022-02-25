#include<iostream>
#include<cstring>
using namespace std;

long d[91];

long logic(int a) {
    d[1] = 1;
    d[2] = 1;
    
    if (d[a] == 0) {
        return d[a] = logic(a-1) + logic(a-2);
    }

    return d[a];
}

int main() {

    bzero(d, sizeof(d));

    int a;
    cin>>a;
    long result = logic(a);
    cout<<result<<"\n";
}