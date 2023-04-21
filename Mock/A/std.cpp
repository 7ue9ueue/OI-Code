#include<bits/stdc++.h>
using namespace std;

void solve (int id) {
    string inp = "range"+to_string(id)+".in";
    string out = "range"+to_string(id)+".out";
    freopen(inp.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);
    int n;cin>>n;
    int R = 0;
    int L = 1e9;
    for (int i=1;i<=n;i++) {
        int x;cin>>x;
        R = max(R,x);
        L = min(L,x);
    }
    cerr<<R<<" "<<L<<endl;
    cout<<R-L<<endl;
}

int main () {
    int t = 20;
    for (int i=1;i<=20;i++) solve(i);
}

/*

int main () {
    int a[1000005];
    int n;cin>>n;
    int R = 0;
    int L = 1e9;
    for (int i=1;i<=n;i++) {
        int x;cin>>x;
        R = max(R,x);
        L = min(L,x);
    }
    cout<<R-L<<endl;
}
*/