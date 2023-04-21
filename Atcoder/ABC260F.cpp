#include"bits/stdc++.h"
#include"vector"
#include"iostream"
using namespace std;

const int maxn = 3e5+5;
const int maxk = 3005;
vector<int> E[maxn];
int G[maxk][maxk];
int s,t,m;

void answer (int a, int b, int c, int d) {
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    exit(0);
}

int main () {
    cin>>s>>t>>m;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        E[u].push_back(v);
    } 
    for (int i=1;i<=s;i++) {
        for (int u:E[i]) for (int v:E[i]) {
            if (u==v) continue;
            if (G[u-s][v-s]) answer(u,v,G[u-s][v-s],i);
            G[u-s][v-s] = i;
        }
    }
    cout<<-1<<endl;
    return 0;
}