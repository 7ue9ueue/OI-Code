#include"bits/stdc++.h"
#include"iostream"
#include"cstring"
#include"vector"
#include"map"
using namespace std;


const int maxn = 2e5+5;
int p[maxn];
int sz[maxn], val[maxn], pter;
vector<int> card[maxn];
map<int,int> v;
int ans[maxn];
int n,k;

int main () {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>p[i];
    if (k==1) {
    	for (int i=1;i<=n;i++) cout<<p[i]<<endl;
    	return 0;
    }
    pter = 1;
    v.insert(make_pair(p[1],1));
    sz[pter] = 1;
    card[pter].push_back(p[1]);
    memset(ans,-1,sizeof(ans));
    for (int i=2;i<=n;i++) {
        if (v.lower_bound(p[i])==v.end()) {
        	pter++;
            v.insert(make_pair(p[i],pter));
            sz[pter] = 1;
            card[pter].push_back(p[i]);
        }
        else {
        	int vvv = v.lower_bound(p[i])->first;
        	int pos = v.lower_bound(p[i])->second;
            v.erase(vvv);
            sz[pos]++;
            card[pos].push_back(p[i]);
            if (sz[pos]==k) {
                for (int j=0;j<k;j++) {
                    ans[card[pos][j]] = i;
                }
            }
            else v[p[i]] = pos;
        }
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
}