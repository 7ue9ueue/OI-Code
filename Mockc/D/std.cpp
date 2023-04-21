#include"bits/stdc++.h"
using namespace std;
int e[1000005];

void solve (int id) {
    string inp = "leader"+to_string(id)+".in";
    string out = "leader"+to_string(id)+".out";
    ifstream fin (inp);
    ofstream fout (out);
    int n;fin>>n;
    string s;fin>>s;
    s = "#"+s;
    for (int i=1;i<=n;i++) fin>>e[i];
    int ans = 0;
    for (int i=1;i<=n;i++) {for (int j=i+1;j<=n;j++) {
        if ((i==e[i] || s[e[i]]==s[j]) && (e[j]==j || s[e[j]]==s[i]) && (s[i]!=s[j])) ans++;
    }}
    fout<<ans<<endl;
} 

signed main () {
    for (int i=1;i<=20;i++) solve(i);
}