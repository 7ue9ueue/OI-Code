#include"bits/stdc++.h"
using namespace std;

int maxn = 55+5;
int N,K;
int dp[55][55][5][3];
char f[55][55];
void solve () {
	memset(dp,0,sizeof(dp));
	memset(f,0,sizeof(f));
	cin>>N>>K;
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) {
		cin>>f[i][j];
	}
	dp[1][1][0][0] = 1;
	dp[1][1][0][1] = 1;
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) {
		if (i==1 and j==1) continue;
		if (f[i][j]=='H') continue;
		for (int k=0;k<=K;k++) {	
			f[i][j][k][0] += f[i][j-1][k][0];
			f[i][j][k][1] += f[i-1][j][k][1];
			if (k) f[i][j][k][0] += f[i-1][j][k-1][1];
			if (k) f[i][j][k][1] += f[i][j-1][k-1][0];
		}
	}
	int ans = 0;
	for (int i=0;i<=K;i++) {
		ans += dp[N][N][i][0];
		ans += dp[N][N][i][1];
	}
	cout<<ans<<endl;
}
int main () {
	int t;cin>>t;
	while (t-->0) solve();
}