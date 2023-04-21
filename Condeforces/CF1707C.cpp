#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
	static char c;static int f;
	for(c=ch(),f=1;c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>void write(T x){
	static char q[65];int cnt=0;
	if(x<0)pc('-'),x=-x;
	q[++cnt]=x%10,x/=10;
	while(x)
		q[++cnt]=x%10,x/=10;
	while(cnt)pc(q[cnt--]+'0');
}
const int maxn=100005,maxm=200005;
int par[maxn];
int AC(int x){
	return par[x]==x?x:par[x]=AC(par[x]);
}
struct Edge{
	int v,nt;
	Edge(int v=0,int nt=0):
		v(v),nt(nt){}
}e[maxn*2],es[maxm];
int hd[maxn],num;
void qwq(int u,int v){
	e[++num]=Edge(v,hd[u]),hd[u]=num;
}
int dp[maxn];
int pa[maxn][20];
void dfs(int u,int p){
	pa[u][0]=p;
	for(int j=1;(1<<j)<=dp[u];++j)
		pa[u][j]=pa[pa[u][j-1]][j-1];
	for(int i=hd[u];i;i=e[i].nt){
		int v=e[i].v;
		if(v==p)continue;
		dp[v]=dp[u]+1;dfs(v,u);
	}
}
int jump(int x,int t){
	for(int cn=0;t;t>>=1,++cn)
		if(t&1)x=pa[x][cn];
	return x;
}
int lca(int x,int y){
	if(dp[x]>dp[y])x=jump(x,dp[x]-dp[y]);
	if(dp[y]>dp[x])y=jump(y,dp[y]-dp[x]);
	if(x==y)return x;
	for(int t=19;t>=0;--t)
		if(pa[x][t]!=pa[y][t])
			x=pa[x][t],y=pa[y][t];
	return pa[x][0];
}
int vis[maxn];
char s[maxn];
void pushdown(int u,int p){
	if(vis[u]==0)s[u]='1';
	else s[u]='0';
	for(int i=hd[u];i;i=e[i].nt){
		int v=e[i].v;
		if(v==p)continue;
		vis[v]+=vis[u];
		pushdown(v,u);
	}
}
int main(){
	int n,m;
	read(n),read(m);
	for(int i=1;i<=n;++i)
		par[i]=i;
	int tp=0;
	for(int i=1;i<=m;++i){
		int u,v;
		read(u),read(v);
		if(AC(u)==AC(v)){
			es[++tp]=Edge(u,v);
		}
		else{
			par[AC(u)]=AC(v);
			qwq(u,v),qwq(v,u);
		}
	}
	int root=1;
	dfs(root,0);
	for(int i=1;i<=tp;++i){
		int u=es[i].v,v=es[i].nt;
		if(dp[u]>dp[v])u^=v^=u^=v;
		int w=lca(u,v);
		if(u==w){
			--vis[v];
			++vis[jump(v,dp[v]-dp[u]-1)];
		}
		else{
			++vis[root];
			--vis[u];
			--vis[v];
		}
	}
	pushdown(root,0);
	s[n+1]='\0';
	printf("%s\n",s+1);
	return 0;
}