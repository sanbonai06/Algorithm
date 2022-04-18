#include<iostream>
#define INF 1e9
using namespace std;

float ipt[11];
float opt[11][11];
int answer[11][11];
int N;
int tree[20][20];
int treeCnt = 0;

// float cal_opt(float r, float k, float c) {
//     return opt[r][c] = ca
// }

float add(int start, int end) {
    float result = 0;
    for(int i= start; i<=end; i++) {
        result+=ipt[i];
    }
    return result;
}

float total_add(int start, int end) {
    float result = 0;
    for(int i=start; i<=end; i++) {
        result+=ipt[i];
    }
    return result;
}

void solve(int r, int c) {
    if(r > c) return;
    
    for(int k = r; k <= c; k++) {
        if(opt[r][k-1] == INF) solve(r, k-1);
        if(opt[k+1][c] == INF) solve(k+1, c);
        if(opt[r][c] > 1 + opt[r][k-1]*add(r, k-1)/total_add(r,c) + opt[k+1][c]*add(k+1, c)/total_add(r,c)) {
            opt[r][c] =1 + opt[r][k-1]*add(r, k-1)/total_add(r,c) + opt[k+1][c]*add(k+1, c)/total_add(r,c);
            answer[r][c] = k+1;
        }
    }
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>ipt[i];
    }
    
    // init
    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            opt[i][j] = INF;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            solve(i,j);
        }
    }
    cout<<"table of opt[i,j]"<<"\n"<<"\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i>j) cout<<" "<<" "<<" "<<" "<<" ";
            else printf("%.2f ", opt[i][j]);
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"table of k[i,j]"<<"\n"<<"\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i>j) cout<<" "<<" ";
            else cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }
}