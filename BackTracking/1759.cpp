#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int L,C;
vector<char> v;
string result;
int cnt_m = 0;
int cnt_z = 0;
void logic(int start, int m, int z, string str) {
    if(str.size() == L && (m >= 1 && z>= 2)) {
        cout<<str<<"\n";
        return;
    }
    for(int i = start; i<v.size(); i++) {
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u'){
            logic(i+1, m+1, z, str + v[i]);
        }
        else {
            logic(i+1, m, z+1, str + v[i]);
        }
    }
}

int main() {
    cin>>L>>C;
    char a;
    for(int i=0; i<C; i++) {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    logic(0, cnt_m, cnt_z, result);
}