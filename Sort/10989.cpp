#include<iostream>
using namespace std;
int N;
int list[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    int a;
    for(int i=0; i<N; i++) {
        // scanf("%d", &list[i]);
        cin>>a;
        list[a]++;
    }
    // mergeSort(0, N-1);
    for(int i=1; i<=10000; i++) {
        for(int j = 0; j<list[i]; j++){
            cout<<i<<"\n";
        } 
    }
}   