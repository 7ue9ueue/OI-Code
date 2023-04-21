#include"bits/stdc++.h"
#include"vector"
#include"iostream"
#define int long long 
using namespace std;

int n,m;
const int maxn = 1e5+5;
int a[maxn], b[maxn];
vector<int> inva[maxn];
vector<int> invb[maxn];
int cnt;
int vis[maxn];
int ans[maxn];

signed main () {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        inva[a[i]].push_back(i);
        invb[b[i]].push_back(i);
    }
    int l = 0;int r = 0;
    for (l=1;l<=m;l++) {
        //左端点固定
        while (cnt<n&&r<=m) {
            r++;
            for (int e:inva[r]) {
                if (vis[e]==0) cnt++;
                vis[e]++;
            }
            for (int e:invb[r]) {
                if (vis[e]==0) cnt++;
                vis[e]++;
            }
        }
        ans[r-l+1]++;
        ans[m+1-l+1]--;
        for (int e:inva[l]) {
            vis[e]--;
            if (vis[e]==0) cnt--;
        }
        for (int e:invb[l]) {
            vis[e]--;
            if (vis[e]==0) cnt--;
        }
    }
    for (int i=1;i<=m;i++) {
        ans[i] += ans[i-1];
        cout<<ans[i]<<" ";
    }
}