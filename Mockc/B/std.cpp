#include"bits/stdc++.h"
using namespace std;


void solve (int id) {
    string inp = "hand"+to_string(id)+".in";
    string out = "hand"+to_string(id)+".out";
    freopen(inp.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);
    int n;cin>>n;
    int ans = 0;
    for (int i=0;i<n;i++) {
        char c;cin>>c;
        if (c!='R') ans++;
    }
    cout<<ans<<endl;    
    fclose(stdout);
    fclose(stdin);
}

int main () {
    int t = 20;
    for (int i=2;i<=t;i++) solve(i);
}