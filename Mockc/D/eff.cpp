#include"bits/stdc++.h"
#define int long long 
using namespace std;
int e[1000005];

void solve (int id) {
    // string inp = "leader"+to_string(id)+".in";
    // string out = "leader"+to_string(id)+".out";
    int n;cin>>n;
    string s;cin>>s;
    s = "#"+s;
    for (int i=1;i<=n;i++) cin>>e[i];
    int G = 0;
    int H = 0;
    for (int i=1;i<=n;i++) {
        if (e[i]==i && s[i]=='G') G++;
        if (e[i]==i && s[i]=='H') H++;
    }
    int ans = 0;
    for (int i=1;i<=n;i++) {
        if (e[i]<=i) continue;
        if (e[e[i]]==i&&s[i]!=s[e[i]]) ans++;
    }
    ans += G*H;
    cout<<ans<<endl;
} 

signed main () {
    for (int i=1;i<=20;i++) solve(i);
}