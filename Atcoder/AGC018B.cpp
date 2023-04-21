#include"bits/stdc++.h"
using namespace std;

const int maxn = 305;
int n,m;
int p[maxn][maxn];
int del[maxn];
int ptr[maxn],cnt[maxn];
int Fans = maxn;

int solve () {
    int t = 0;int r = 0;
    for (int i=1;i<=m;i++) {
        if (cnt[i]>t) {
            t = cnt[i];
            r = i;
        }
    }
    Fans = min(Fans,t);
    return r;
} 
void remove (int event) {
    del[event] = true;
    for (int i=1;i<=n;i++) {
        cnt[p[i][ptr[i]]]--;
        while (del[[p[i][ptr[i]]) ptr[i]++;
        cnt[p[i][ptr[i]]]++;
    }
}
int main () { 
    cin>>n>>m;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>p[i][j];
    for (int i=1;i<=n;i++) {
        ptr[i] = 1;
        cnt[p[i][ptr[i]]]++;
    }
    for (int i=1;i<=n;i++) {
        int e = solve();
        removes(e);
    }
    cout<<Fans<<endl;
}