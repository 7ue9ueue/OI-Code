#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;

int a[150000],b[150000],c[150000],d[150000],e[140000];

void makefile ()
{
    int n;cin>>n;
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(e,0,sizeof(e));
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++)
    {
        b[a[i]] = max(b[a[i]],b[a[i]-1]+1);
        d[i] = b[a[i]];
    }
    for (int i=n-1;i>=0;i--)
    {
        c[a[i]] = max(c[a[i]],c[a[i]-1]+1);
        e[i] = c[a[i]];
    } 
	int ans = 0;
	for (int i=0;i<n;i++)
	{
		ans = max(ans,d[i]+e[i]-1);
	}
	cout<<ans<<endl;
}
int main () 
{
	for (int i=1;i<=20;i++) 
	{
        string inp = "./T4/pyramid"+to_string(i)+".in";
		string out = "./T4/pyramid"+to_string(i)+".out";
		freopen(inp.c_str(),"r",stdin);
        freopen(out.c_str(),"w",stdout);
		makefile();
	}
}