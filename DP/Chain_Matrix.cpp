#include<iostream>
#define INF 1e9
using namespace std;

int dimension[11];
int opt[11][11];
int answer[11][11];
int N;

// int cal_opt(int r, int k, int c) {
//     return opt[r][c] = ca
// }

void solve(int r, int c) {
    if(r >= c) return;
    
    for(int k = r; k <= c; k++) {
        if(opt[r][k] == INF) solve(r, k);
        if(opt[k+1][c] == INF) solve(k+1, c);
        if(opt[r][c] > opt[r][k] + opt[k+1][c] + dimension[r-1]*dimension[k]*dimension[c]) {
            opt[r][c] = opt[r][k] + opt[k+1][c] + dimension[r-1]*dimension[k]*dimension[c];
            answer[r][c] = k;
        }
    }
}

void order(int i,int j) {
	if(i == j) {
		cout << "A" << i;
		return;
	}	
    int k = answer[i][j]; // k번째 위치에서 잘림.
    if(i == 1 && j == N-1) {
        order(i, k);
        order(k+1, j);
    }
    else {
        cout << "(";
	    order(i, k);
	    order(k + 1, j);
	    cout << ")";
    }
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>dimension[i];
    }
    
    // init
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            opt[i][j] = INF;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            solve(i,j);
        }
    }
    cout<<"table of opt[i,j]"<<"\n"<<"\n";
    for(int i=1; i<N; i++) {
        for(int j=1; j<N; j++) {
            if(i>j) cout<<" "<<" "<<" ";
            else cout<<opt[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"table of k[i,j]"<<"\n"<<"\n";
    for(int i=1; i<N; i++) {
        for(int j=1; j<N; j++) {
            if(i>j) cout<<" "<<" ";
            else cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"optimal chained matrix multiplication"<<"\n"<<"\n";
    order(1,N-1);
}