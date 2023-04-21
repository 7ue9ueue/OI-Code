#include"bits/stdc++.h"
#define int long long 
#define fin cin
#define fout cout
using namespace std;
int e[1000005];

void solve (int id) {
    string inp = "leader.in";
    string out = "leader.out";
    ifstream fin (inp);
    ofstream fout (out);
    int n;fin>>n;
    string s;fin>>s;
    s = "#"+s;
    for (int i=1;i<=n;i++) fin>>e[i];
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
    fout<<ans<<endl;
} 

signed main () {
solve(114514);
}