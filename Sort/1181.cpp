#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
    if(a.size() != b.size())
        return a.size()<b.size();
    else {
        return a.compare(b)<0;
    }
}

int main() {
    int N;
    cin>>N;
    string a[N];
    for(int i=0; i<N; i++) 
    {
        cin>>a[i];
    }
    // sort(a, a+N, cmp2);  
    sort(a, a+N, cmp);

    for(int i=0; i<N; i++) 
    {
        if(a[i].compare(a[i-1]) != 0) 
            cout<<a[i]<<"\n";
    }
}