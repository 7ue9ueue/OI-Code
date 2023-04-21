#include<iostream>
#define ll long long 
using namespace std;


void exgcd (ll a, ll b, ll& x, ll& y) {
    if (b==0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b,a%b,y,x);
    y -= a/b*x;
}

void solve () {
    ll a,b,d;
    cin>>a>>b>>d;
    int cnt = 0;
    while (d%2==0) {
        d /= 2;
        cnt++;
    }
    if (a%(1ll<<cnt)!=0||b%(1ll<<cnt)!=0) {
        cout<<-1<<endl;
        return;
    }
    ll v = a|b; ll n = 0; ll m = 0;
    exgcd((1ll<<30)%d,d,n,m);
    ll x = (d-v%d)*(n+d)%d;
    x = (1ll<<30)*x;
    cout<<(x|a|b)<<endl;
}

int main () {
	int t;cin>>t;
    while (t-->0) solve();
}