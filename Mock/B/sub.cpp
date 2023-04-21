#include"bits/stdc++.h"
using namespace std;


void solve () {
    string inp = "hand.in";
    string out = "hand.out";
    freopen(inp.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);
    int n;cin>>n;
    int ans = 0;
    string s;cin>>s;
    for (int i=0;i<n;i++) {
        char c = s[i];
        if (c!='R') ans++;
    }
    cout<<ans<<endl;    
}

int main () {
    solve();
}