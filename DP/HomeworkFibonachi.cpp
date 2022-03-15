// #include<iostream>
// #include<cstring>
// #define MAX 1000000
// using namespace std;
// long long dp[MAX];

// long long fibo(int n) {
//     if(n==1) return 1;
//     if(n==2) return 1;

//     if(dp[n] != -1) return dp[n];
//     else if(dp[n] == -1) {
//         return dp[n] = fibo(n-1) + fibo(n-2);
//     }
// }

// long long fib_t(int n) {
//     if(n==0) return 1;
//     if(n==1) return 1;

//     if(dp[n] != -1) return dp[n];
//     else if(dp[n] == -1) {
//         return dp[n]= fib_t(n-1) + fib_t(n-2) + 1;
//     }
// }

// int main() {
//     memset(dp, -1, sizeof(dp));
//     int a;
//     cin>>a;
//     cout<<fib_t(a)<<endl;
// }

#include<stdio.h>
#include<string.h>
#include<memory.h>
#define N 209 //The 1000th Fibonacci number has 209 decimal digits.
void print_digits(char d[N])
{
  int i=0;
  while(d[i++]==0)
  while(i<N)
    printf("%d", d[i++]);  // "%d" instead of "%c"
}
// Add aa and bb and store the result in bb.
// aa is assumed to be always larger.
void add_digits(char aa[N], char bb[N])
{
  int i=0;
  int carry=0;
  int j, s;
  while(aa[i++]==0){  // after loop, i is the first "non-zero" place
  printf("%d\n", i);
  for(j=N-1;j>=i-1;j--) { // the sum can have non-zero at (i-1)th place
    if( (s=carry+aa[j]+bb[j])>9 ) {         // 올림수 + aa + bb 가 10이 넘어가면
      bb[j]=s-10;
      carry=1;
    } else {
        bb[j]=s;
        carry=0; 
    }
    }
  } 
}
int main()
{
// Write Your Progam Here!
    char a[N];
    char b[N];
    char c[N];
    bzero(a, sizeof(a));
    bzero(b, sizeof(b));
    bzero(c, sizeof(c));
    int i=1;
    a[0] = 0;   //n-2
    b[0] = 1;   //n-1
    for(i=2;i<N;i++) {
        strcpy(c, a);
        add_digits(b, a);
        if(i == N-1) break;
        strcpy(b, a);
        strcpy(a, c);
    }
    print_digits(a);
}