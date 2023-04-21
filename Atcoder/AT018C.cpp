#include"bits/stdc++.h"
#include"queue"
#define int long long
using namespace std;

int X,Y,Z;
const int maxn = 1e5+5;
int a[maxn], b[maxn], c[maxn];
pair<int,int> p[maxn];
int A[maxn], B[maxn];
int ans = 0;int temp = -1e18;

signed main () {
    cin>>X>>Y>>Z;
    for (int i=1;i<=X+Y+Z;i++) cin>>a[i]>>b[i]>>c[i];
    for (int i=1;i<=X+Y+Z;i++) ans += a[i];
    //A = bi-ai| B = ci-ai
    //bi-ai+cj-aj>bj-aj+ci-ai
    //bi+cj>bj+ci
    //bi-ci>bj-cj
    for (int i=1;i<=X+Y+Z;i++) p[i] = {b[i]-c[i],i};
    sort(p+1,p+X+Y+Z+1);
    priority_queue< int,vector<int>,greater<int> > pq;
    for (int i=1;i<=Y;i++) {
        pq.push(b[p[i].second]-a[p[i].second]);
        A[Y] += b[p[i].second]-a[p[i].second];
    }
    for (int i=Y+1;i<=X+Y+Z;i++) {
        pq.push(b[p[i].second]-a[p[i].second]);
        A[i] = A[i-1]+b[p[i].second]-a[p[i].second]-pq.top();pq.pop();
    }
    while (pq.size()) pq.pop();
    for (int i=X+Y+Z;i>X+Y;i--) {
        pq.push(c[p[i].second]-a[p[i].second]);
        B[X+Y+1] += c[p[i].second]-a[p[i].second];
    }
    for (int i=X+Y;i>=1;i--) {
        pq.push(c[p[i].second]-a[p[i].second]);
        B[i] = B[i+1]+c[p[i].second]-a[p[i].second]-pq.top();pq.pop();
    }
    for (int i=Y;i<=X+Y;i++) {
        res = max(res,A[i]+B[i+1]);
    }
    cout<<res+ans<<endl;
}