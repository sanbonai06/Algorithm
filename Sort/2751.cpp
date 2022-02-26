#include<iostream>
#include<stdlib.h>
#define MAX 1000000
using namespace std;

int N;
int list[MAX];
int sortedList[MAX];
bool min(int a,int b) {
    if(a<=b) {
        return true;
    }
    return false;
}
void myBubbleSort() {
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            if(!min(list[i], list[j])) {
                int tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}

void merge(int left, int mid, int right) {
    int l = left;
    int i = left;
    int m = mid+1;
    while(l <= mid && m <= right) {
        if(list[l] <= list[m]) {
            sortedList[i] = list[l];
            l++;
        }
        else{
            sortedList[i] = list[m];
            m++;
        }
        i++;
    }

    //남은 데이터들 삽입
    if(l > mid) {
        for(int k = m; k<=right; k++) {
            sortedList[i] = list[k];
            i++;
        }
    }
    else {
        for(int k = l; k<=mid; k++) {
            sortedList[i] = list[k];
            i++;
        }
    }

    //정렬된 배열을 삽입
    for(int k = left; k<=right; k++) {
        list[k] = sortedList[k];
    }
}

void myMergesort(int left, int right) {
    if(left<right) {
        int mid = (left + right)/2;
        myMergesort(left, mid);
        myMergesort(mid+1, right);
        merge(left, mid, right);
    }
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>list[i];
    }
    // mySort();
    myMergesort(0, N-1);
    for(int i=0; i<N; i++) {
        cout<<list[i]<<"\n";
    }
}