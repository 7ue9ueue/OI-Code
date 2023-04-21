#include<iostream>
#define int long long
using namespace std;
const int maxn = 4e5+5;

void prep () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct tree {
    int l,r;
    int info;
    int lazy;
}t[4*maxn+2];

void pushup () {

}

void pushdown (int p) {
    if(t[p].lazy) {
        t[p*2].lazy += t[p].lazy;
        t[p*2+1].lazy += t[p].lazy;
        t[p*2].info += (t[2*p].r-t[2*p].l+1)*t[p].lazy;
        t[p*2+1].info += (t[2*p+1].r-t[2*p+1].l+1)*t[p].lazy;
        t[p].lazy = 0;
    }
}

void bulid (int p,int l,int r) {
    t[p].l = l;
    t[p].r = r;
    if(l==r){
        return;
    }
    int mid = (l+r)/2;
    bulid(p*2,l,mid);
    bulid(p*2+1,mid+1,r);
	pushup(p);
} 

void change(int p,int x,int y,int z) {
    if (x<=t[p].l && y>=t[p].r) {
        t[p].info += (t[p].r-t[p].l+1)*z;
        t[p].lazy += z;
        return;
    }
    pushdown(p);
    int mid = (t[p].l+t[p].r)>>1;
    if(x<=mid) change(p*2,x,y,z);
    if(y>mid) change(p*2+1,x,y,z);
    pushup(p);
}

int query(int p,int x,int y) {
    if (x<=t[p].l && y>=t[p].r) return t[p].info;
    spread(p);
    int mid=(t[p].l+t[p].r)>>1;
    int ans=0;
    if(x<=mid) ans+=query(p*2,x,y);
    if(y>mid) ans+=query(p*2+1,x,y);
    return ans;
}

int a[maxn];

void Print (int p) {
    int lson = p+p;
    int rson = 2*p+1;
    if (t[p].l==t[p].r) {
        cout<<t[p].info<<" ";
        return;
    }
    spread(p);
    Print(lson);
    Print(rson);
}

signed main () {
    prep();
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    bulid(1,1,n);
    for (int i=1;i<=m;i++) {
        int op;
        cin>>op;
        if (op==1) {
            int l,r,k,d;
            cin>>l>>r>>k>>d;
            if (l==r) {
                change(1,l,r,k);
                if (r!=n) change(1,r+1,r+1,-k);
                continue;
            }
            change(1,l+1,r,d);
            change(1,l,l,k);
            if (r!=n) change(1,r+1,r+1,-1*(k+(r-l)*d));
        }
        else {
            int x;
            cin>>x;
            cout<<query(1,1,x)+a[x]<<endl;
        }
        // cout<<"-----"<<endl;
        // Print(1);
        // cout<<endl;
    }
    return 0;
}