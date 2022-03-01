#include<iostream>
using namespace std;
int N;
int A[10001];
int result = 0;

// void logic() {
//     int cnt = 0;
//     for(int i=1; i<=N; i++) {
//         if(A[i] == 0) {
//             if(cnt == 1) result+=3;
//             else if(cnt == 2) result+=5;
//             else if(cnt == 3) result+=7;
//             cnt = 0;
//         }
//         else if(i == N && A[i] != 0) {
//             if(A[i] > 1) {
//                 if(cnt == 0) {
//                     result+=(A[i]) * 3;
//                 }
//                 else {
//                     ++cnt;
//                     if(cnt == 3) result+=7;
//                     else if(cnt == 2) result+=5;
//                     cnt = 0;
//                     A[i]--;
//                     i--;
//                 }
//             }
//             else if(A[i] == 1) {
//                 cnt++;
//                 if(cnt == 1) result+=3;
//                 else if(cnt == 2) result+=5;
//                 else if(cnt == 3) result+=7;
//                 cnt = 0;
//             }
//         }
//         else if(A[i] == 1){
//             // if(cnt > 3) {
//             //     result+=7;
//             //     cnt = 1;
//             // }
//             cnt++;
//         }
//         else if(A[i] > 1) {
//             if(cnt == 0)
//             {
//                 result+=(A[i]-1) * 3;
//                 A[i] = 1;
//                 cnt++;
//             }
//             else {
//                 ++cnt;
//                 if(cnt == 3) result+=7;
//                 else if(cnt == 2) result+=5;
//                 cnt = 0;
//                 A[i]--;
//                 i--;
//             }
//         }

//         if(cnt == 3) {
//             result += 7;
//             cnt = 0;
//         }
//     }
// }

void logic() {
    for(int i=1; i<=N; i++) {
        if(A[i+1] < A[i+2]) {
            int m = min(A[i], min(A[i+1], A[i+2])); //라면 3개 사는 경우의 수를 최대한 뽑음
            result+=7*m;
            A[i] -= m;
            A[i+1] -= m;
            A[i+2] -= m;
            m = min(A[i], A[i+1]);
            result+=5*m;
            A[i] -= m;
            A[i+1] -= m;
        }
        else {
            int m =min(A[i], A[i+1] - A[i+2]);
            result+=5*m;
            A[i] -= m;
            A[i+1] -= m;
            m = min(A[i], min(A[i+1], A[i+2]));
            result+=7*m;
            A[i] -=m;
            A[i+1] -=m;
            A[i+2] -=m;
        }
        result+=3*A[i];
    }
}

int main() {
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>A[i];
    }
    logic();
    cout<<result<<"\n";
}