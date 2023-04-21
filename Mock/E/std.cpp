#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn = 1e5+5;
int f[maxn];
int a[maxn];
int n;

void solve(int i) {
    string inp = "select"+to_string(i)+".in";
    string out = "select"+to_string(i)+".out";
    freopen(inp.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    f[1] = a[1];
    for (int i=2;i<=n;i++) {
        f[i] = max(f[i-1],f[i-2]+a[i]);
    }
    cout<<f[n]<<endl;
}

signed main () {
    int T = 20;
    for (int i=1;i<=20;i++) solve(i);
}