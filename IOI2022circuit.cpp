//#include"circuit.h"
//#include"bits/stdc++.h"
#include<iostream>
#include<vector>
#define ls p+p
#define rs p+p+1
using namespace std;

const int maxn = 2e5+5;
vector<int> E[maxn];
vector<int> pre[maxn], suf[maxn];
int val[maxn]; int deg[maxn];
int on[maxn]; int ans[maxn];
int cnt[maxn];
int n,m,rt = 1;
const int MOD = 1e9+2022;

struct seg {
    int l, r, cur, oth;
    int tag;
};
seg t[maxn*4];

void pushup (int p) {
    t[p].cur = (t[ls].cur+t[rs].cur)%MOD;
    t[p].oth = (t[ls].oth+t[rs].oth)%MOD;
}

void pushdown (int p) {
    if (!t[p].tag) return;
    t[p].tag = 0;
    swap(t[ls].cur,t[ls].oth);
    swap(t[rs].cur,t[rs].oth);
}

void build (int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    if (l==r) {
        if (on[l]) t[p].cur = ans[l+n];
        else t[p].oth = ans[l+n];
        return;
    }
    int mid = (l+r)/2;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}

int query () {
    return t[1].cur;
}
void update (int p, int l, int r) {
    if (l<=t[p].l && t[p].r<=r) {
        swap(t[p].cur,t[p].oth);
        t[p].tag ^= 1;
        return;
    }
    pushdown(p);
    int mid = (t[p].l+t[p].r)/2;
    if (l<=mid) update(ls,l,r);
    if (mid<r) update(rs,l,r);
    pushup(p);
}

int DFS1 (int u) {
    val[u] = max(1,deg[u]);
    for (int v:E[u]) {
        val[u] = val[u]*DFS1(v);
        val[u] = val[u]%MOD;
    }
    return val[u];
}

void DFS2 (int u, int prod) {
    ans[u] = prod;
    for (int i=0;i<E[u].size();i++) {
        int nprod = prod;
        int v = E[u][i];
        if (i>0) nprod *= pre[u][i-1], nprod %= MOD;
        if (i<E[u].size()-1) nprod *= suf[u][i+1], nprod %= MOD;
        DFS2(v,nprod);
    }
}
void init (int N, int M, vector<int> f, vector<int> v) {
    n = N; m = M;
    for (int i=0;i<f.size();i++) {
        E[f[i]+1].push_back(i+1);
        pre[f[i]+1].push_back(1);
        suf[f[i]+1].push_back(1);
        deg[f[i]+1]++;
    }
    for (int i=0;i<v.size();i++) {
        on[i+1] = v[i];
    }
    DFS1(rt);
    for (int i=1;i<=n+m;i++) {
        cout<<deg[i]<<val[i]<<endl;
    }
    for (int i=1;i<=n+m;i++) {
        for (int j=0;j<E[i].size();j++) {
            pre[i][j] = val[E[i][j]];
            suf[i][j] = val[E[i][j]];
        }
        for (int j=1;j<E[i].size();j++) {
            pre[i][j] *=a pre[i][j-1];
            pre[i][j] %= MOD;
        }
        for (int j=E[i].size()-2;j>=0;j--) {
            suf[i][j] *= suf[i][j+1];
            suf[i][j] %= MOD;
        }
    }
    DFS2(rt,1);
    build(1,1,m);
}

int count_ways (int l, int r) {
    l++;r++;l-=n;r-=n;
    update(1,l,r);
    return query();
}
