#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string.h>
#include<memory.h>
using namespace std;
#define N 210 //The 1000th Fibonacci number has 209 decimal digits.
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
//    while(aa[i++]==0)  // after loop, i is the first "non-zero" place
//   {
  for(j=N-1;j>=0;j--) { // the sum can have non-zero at (i-1)th place
    if( (s=carry+aa[j]+bb[j])>9 ) {
      bb[j]=s-10;
      carry=1;
    } 
    else {
        bb[j]=s;
        carry=0; 
    }
  }
//} 
}

int main()
{
// Write Your Progam Here!
    char aa[N];
    char bb[N];
    char cc[N];
    bzero(aa, sizeof(aa));
    bzero(bb, sizeof(bb));
    bzero(cc, sizeof(cc));
    int i=1;
    bb[N-1] = 1;
    aa[N-1] = 1;   //n-1 fib(1)
    int d;
    cin>>d;
    for(i=3;i<=d;i++) {
        memcpy(cc, aa, sizeof(aa));     //cc에 fib(n-1) 저장
        // print_digits(cc);
        // printf("\n");
        add_digits(aa, bb);     //bb에 fib(n) 저장
        if(i == d) break;
        memcpy(aa, bb, sizeof(bb));         //aa에 fib(n-1)이 되는 것 저장
        memcpy(bb, cc, sizeof(cc));         //bb에 fib(n-2)이 되는 것 저장
        // printf("aa: ");
        // print_digits(aa);
        // printf("\n");
        // printf("bb: ");
        // print_digits(bb);
        // printf("\n");
        // printf("cc: ");
        // print_digits(cc);
        // printf("\n");
    }
    print_digits(bb);
}