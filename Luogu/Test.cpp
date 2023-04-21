#include<iostream>
using namespace std;

const int maxn = 1e5+5;
int a[maxn];
int p[maxn];

int main () 
{
	int n;cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) p[i] = p[i-1]+a[i];
	int l,r;cin>>l>>r;
	int sum = 0;
	for (int i=l;i<=r;i++) sum += a[i];
	cout<<sum<<endl;
	sum = p[r]-p[l-1];
	cout<<sum<<endl;
}