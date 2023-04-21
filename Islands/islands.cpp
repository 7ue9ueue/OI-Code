#include"bits/stdc++.h"
#include"islands.h"
#include"variant"
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int maxn = 2e5+5;
int n,m;
int sel[maxn];
multiset<P> E[maxn], R[maxn];
vector<int> ans;
vector<int> del;
int cnt = 0;int rt = 1;
bool flag = true;

queue<int> q;
void topo () {
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (P p:R[u]) {
			int v = p.first;
            int i = p.second;
			if (E[v].empty()) continue;
			E[v].erase(mp(u,i));
			if (E[v].empty()) q.push(v);
		}
	}
}

void DFS (int u, int f) {
    if (cnt==0&&f!=-1&&u==rt) {
        flag = true;
        return;
    }
    for (P p:E[u]) {
        int v = p.first;
        int i = p.second;
        if (i==f) continue;

        ans.push_back(i);
        E[u].erase(p);
        E[v].insert(mp(u,i));

        sel[i] ^= 1;
        if (sel[i]) {
            cnt++;
        }
        else {
            cnt--;
        } 
        DFS(v,i);
        return;
    }
}

variant< bool,vector<int> > find_journey (int N, int M, vector<int> U, vector<int> V) {
    n = N; m = M;
    for (int i=0;i<M;i++) {
        int u = U[i]+1;
        int v = V[i]+1;
        E[u].insert(mp(v,i));
        R[v].insert(mp(u,i));
    }
    for (int i=1;i<=n;i++) if(E[i].empty()) {
        q.push(i);
    }
    topo();
    while (E[rt].size()<=1) {
        q.push(rt);topo();
        if (E[rt].empty()) {
            return false;
        }
        P e = *E[rt].begin();
        ans.push_back(e.second);
        del.push_back(e.second);
        rt = e.first;
    }
    for (int i=1;i<=n;i++) {
        if (i!=rt) while (E[i].size()>1) E[i].erase(--E[i].end());
        else while (E[i].size()>2) E[i].erase(--E[i].end());
    }
    DFS(rt,-1);
    reverse(del.begin(),del.end());
    for (int x:del) ans.push_back(x);
    return ans;
}