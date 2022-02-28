#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

int N;
char arr[50][51];
int max(int a, int b) {
    if(a>=b) {
        return a;
    }
    return b;
}
void sort() {
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            if(strlen(arr[i]) > strlen(arr[j])) {
                char a[51];
                strcpy(a, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], a);
            }
        }
    }
}
void logic() {
    int max_num = 0;
    for(int i=N-1; i>=0; i--) {
        for(int j=0; j<i; j++) {
            if(strlen(arr[j])&&strncmp(arr[i], arr[j], strlen(arr[j])) == 0)
                strcpy(arr[j], "");
        }
    }
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }
    // sort(arr, arr+N);
    sort();
    int cnt = 0;
    logic();
     for(int i=0; i<N; i++) {
        if(strlen(arr[i])!=0) cnt++;
    }
    cout<<cnt<<"\n";
}