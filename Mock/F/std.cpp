#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int i) {
    string inp = "market"+to_string(i)+".in";
    string out = "market"+to_string(i)+".out";
    freopen(inp.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);
    priority_queue<int, vector<int>, greater<int> > q;
    int ans = 0;
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        int k;cin>>k;
        if (!q.empty() && q.top() < k) ans += k - q.top(), q.pop(), q.push(k);
        q.push(k);
    }
    printf("%lld\n", ans);
}

signed main () {
    int T = 20;
    for (int i=1;i<=20;i++) solve(i);
}