#include"bits/stdc++.h"
#define int long long 
using namespace std;
//AIO Term2 
const int maxn = 1e5+5;
int a[maxn];
int p[maxn];
int pos[maxn];
int n,m,d;

//p = [5,1,4,3,2]
//pos[2] = 5
//p[5] = 2
//pos[1] = 2 

//pos[2] = 5
//pos[p[5]] = 5 
void solve ()
{
	cin>>n>>m>>d;
	int answer = n;
	for (int i=1;i<=n;i++) cin>>p[i];
	for (int i=1;i<=m;i++) cin>>a[i];
	for (int i=1;i<=n;i++) pos[p[i]] = i;
	for (int i=1;i<m;i++)
	{
		if (!(pos[i]<pos[i+1]&&pos[i+1]<=pos[i]+d)) 
		{
			cout<<0<<endl;
			return;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int x = pos[a[i]];
		int y = pos[a[i+1]];
		//x--y--x+d
		//y--x--x+d
		int case1 = y-x;
		//x--y--x+d
		//x--x+d--y
		int case2 = x+d-y+1;
		answer = min(answer,case1);
		if (n-y+x-1>=case2) answer = min(answer,case2);
	}
	cout<<answer<<endl;
} 
signed main ()
{
	int t;cin>>t;
	while (t-->0) solve();
}