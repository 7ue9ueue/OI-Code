#include"bits/stdc++.h"
#define int long long 
using namespace std;
 
int n;
const int maxn = 1e6+5;
int a[maxn];
int answer = 1e18;
 
int solve (int idx)
{
    int result = 0;
    int tot = 0;
    for (int i=idx;i<idx+n;i++) 
    {
        int cnt = abs(a[i]);
        if (a[i]<0) 
        {
            if (tot<=0) 
            {
                result -= cnt*i;
                tot -= cnt;
            }
            if (tot>0)
            {
                result += min(abs(tot),cnt)*i;
                tot -= cnt;
                if (tot<=0) result -= abs(tot)*i;
            }
        }
        if (a[i]>0) 
        {
            if (tot>=0) 
            {
                result -= cnt*i;
                tot += cnt;
            }
            if (tot<0)
            {
                result += min(abs(tot),cnt)*i;
                tot += cnt;
                if (tot>=0) result -= abs(tot)*i;
            }
        }
    }
    //cout<<result<<endl;
    return result;
}
 
signed main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("spacein.txt","r",stdin);
    freopen("spaceout.txt","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        int x;cin>>x;
        a[i] += x;
    }
    for (int i=1;i<=n;i++) 
    {
        int x;cin>>x;
        a[i] -= x;
    }
    for (int i=n+1;i<=n+n;i++) 
    {
        a[i] = a[i-n];
    }
    for (int i=1;i<=n;i++) 
    {
        answer = min(answer,solve(i)); 
        //cout<<answer<<endl;
    }
    cout<<answer;
    return 0;
}
/*
6
5 2 1 6 5 1
3 3 2 7 3 2
*/