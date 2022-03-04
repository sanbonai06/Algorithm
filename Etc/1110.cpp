#include<iostream>
using namespace std;

int logic(int a) {
    int first = a/10;
    int second = a%10;

    int tmp = first + second;
    int t = tmp % 10;
    int result = second*10 + t;

    return result;
}

int main() {
    int M;
    int i = 0;
    cin>>M;
    int a = M;
    while(1) {
        ++i;
        a = logic(a);
        if(a==M) {
            break;
        }
    }

    cout<<i<<"\n";
}