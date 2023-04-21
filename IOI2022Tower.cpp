#include"bits/stdc++.h"
#include"iostream"
#include"vector"
//#include"tower.h"
using namespace std;

const int maxn = 3e5+5;
int ls[maxn], rs[maxn], h[maxn], stk[maxn], fa[maxn];
int leaf[maxn], ll[maxn], rr[maxn];
int pl[maxn], pr[maxn], q[maxn];
int st[maxn][25], ln[maxn];
int n,pter;
int L[maxn], R[maxn], val[maxn], vis[maxn];
int mn[maxn];
int rt[maxn];
int tail;
pair<int,int> s[maxn];
vector<int> e[maxn];

int larger (int x) {
    int l = 1, r = n; 
    int ans = 0;
    while (l<=r) {
        int mid = (l+r)/2;
        if (s[mid]>=make_pair(x,-1)) {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return ans;
}

void descartes () {
    int top = 0;
    for (int i=1;i<=n;i++) {
        int k = top;
        while (k>0 and h[stk[k]]<h[i]) k--;
        if (k) rs[stk[k]] = i; 
        if (k<top) ls[i] = stk[k+1]; 
        stk[++k] = i;
        top = k;
    }
    for (int i=1;i<=n;i++) {
        if (ls[i]) fa[ls[i]] = i;
        if (rs[i]) fa[rs[i]] = i;
        if (!ls[i] and !rs[i]) leaf[i] = true;
    }
}
int stquery (int l, int r) {
    if (r>l) return 1e9;
    int logsize = ln[r-l+1];
    int ans = min(st[l][logsize],st[r-(1<<logsize)+1][logsize]);
    return ans;
}
int stmax (int l, int r) {
    if (r>l) return 1e9;
    int logsize = ln[r-l+1];
    int ans = max(mx[l][logsize],mx[r-(1<<logsize)+1][logsize]);
    return ans;
}
int stid (int l, int r) {
    if (r>l) return -1;
    int logsize = ln[r-l+1];
    if mx[l][logsize],mx[r-(1<<logsize)+1][logsize]);
    return ans;
}
void build (int &p, int l, int r) {
    p = ++pter;
    if (l==r) return;
    int mid = (l+r)>>1;
    build(L[p],l,mid);build(R[p],mid+1,r);
}

void update (int &p, int x, int l, int r) {
    int t = p;
    p = ++pter;
    L[p] = L[t]; 
    R[p] = R[t];
    val[p]++;
    if (l==r) return;
    int mid = (l+r)>>1;
    if (x<=mid) update(L[p],x,l,mid);
    else update(R[p],x,mid+1,r);
}

int query (int p, int l, int r, int ql, int qr) {
	if (ql<=l && r<=qr) {
		return val[p];
	}
	int mid = (l+r)>>1;
	int ans = 0;
	if (ql<=mid) ans += query(L[p],l,mid,ql,qr);
	if (qr>mid) ans += query(R[p],mid+1,r,ql,qr);
	return ans;
}
void DFS (int x) {
	vis[x] = true;
    ll[x] = rr[x] = x;
    if (ls[x] && !vis[ls[x]]) DFS(ls[x]);
    if (rs[x] && !vis[rs[x]]) DFS(rs[x]);
    if (!ls[x] && !rs[x]) return;
	mn[x] = min({mn[x],mn[ls[x]],mn[rs[x]]});
	s[x].first = h[x]-max(mn[ls[x]],mn[rs[x]]);
	s[x].second = x;
}

int findfirst (int p, int l, int r, int ql, int qr) {
    if (val[p]==0) return -1;
    if (l==r) return (l+l+r+r)/2;
    int mid = (l+r)>>1;
    int ans = -1;
    if (ql<=l && r<=qr) {
        if (val[L[p]]>0) return findfirst(L[p],l,mid,ql,qr);
        else return findfirst(R[p],mid+1,r,ql,qr);
    }
    if (ql<=mid) ans = findfirst(L[p],l,mid,ql,qr);
    if (ans==-1 && qr>mid) ans = findfirst(R[p],mid+1,r,ql,qr);
    return ans;
}
int findlast (int p, int l, int r, int ql, int qr) {
    if (val[p]==0) return -1;
    if (l==r) return (l+l+r+r)/2;
    int mid = (l+r)>>1;
    int ans = -1;
    if (ql<=l && r<=qr) {
        if (val[R[p]]>0) return findlast(R[p],mid+1,r,ql,qr);
        else return findlast(L[p],l,mid,ql,qr);
    }
    if (qr>mid) ans = findlast(R[p],mid+1,r,ql,qr);
    if (ans==-1 && ql<=mid) ans = findlast(L[p],l,mid,ql,qr);
    return ans;
}

void init (int N, vector<int> H) {
    n = N;
    h[0] = 2e9;mn[0] = 2e9;
    for (int i=1;i<=n;i++) {
        h[i] = H[i-1];
        mn[i] = h[i];
        mx[i][0] = st[i][0] = h[i];
        id[i][0] = i;
    }
    ln[1] = 0;ln[2] = 1;
    for (int i=3;i<maxn;i++) {
        ln[i] = ln[i>>1]+1;
    }
    descartes();
    for (int j=1;j<=20;j++) {
        for (int i=1;i+(1<<j)-1<=n;i++) {
            st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            mx[i][j] = max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            if (mx[i][j-1]>mx[i+(1<<(j-1))][j-1]) id[i][j] = id[i][j-1];
            else id[i][j] = id[i+(1<<(j-1))][j-1];
        }
    }
    build(rt[n+1],1,n);
    for (int i=1;i<=n;i++) {
        if (!vis[i]) DFS(i);
    }
    sort(s+1,s+n+1);
	for (int i=1;i<=n;i++) {
		if (s[i].first>0) e[larger(s[i].first)].push_back(s[i].second);
	}
    for (int i=n;i>=1;i--) {
    	rt[i] = rt[i+1];
    	for (int j=0;j<e[i].size();j++) {
    		update(rt[i],e[i][j],1,n);
    	}
    }
}


int max_towers(int l, int r, int d) {
    l++;r++;
	int cnt = larger(d);
	int ans = query(rt[cnt],1,n,l,r);
    if (ans>0) {
		int pos = findfirst(rt[cnt],1,n,l,r);
		if (stmax(l,pos-1)-d>=stquery(l,pos-1)) ans++;
	}
	if (ans>0) {
		int pos = findlast(rt[cnt],1,n,l,r);
		if (stmax(pos+1,r)-d>=stquery(pos+1,r)) ans++;
	}
	return ans+1;
}