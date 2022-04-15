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

void makeTree(int r_row, int r_col, int k) {
    if(treeCnt >= N) return;
    // if(answer[0][k-2] == 0 && answer[k][N-1] == 0) {
    //     return;
    // }
    if(k==0) return;
    int left = answer[0][k-2];
    answer[0][k-2] = 0;
    int right = answer[k][N-1];
    answer[k][N-1] = 0;
    tree[r_row+1][r_col-1] = left;
    tree[r_row+1][r_col+2] = right;
    treeCnt++;
    makeTree(r_row+1, r_col-1, left);
    makeTree(r_row+1, r_col+1, right);

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
    cout<<"\n";
    cout<<"Need to figure out how to print out BST"<<"\n"<<"\n";
    tree[0][N/2] = answer[0][N-1];
    makeTree(0, (N-1)/2, 3);
    for(int i=0; i<N; i++) {
        for(int j=0; j<2*N; j++) {
            if(tree[i][j]==0) cout<<" ";
            else cout<<tree[i][j]<<" ";
        }
        cout<<"\n";
    }
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<2*N; j++) {
    //         cout<<tree[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}