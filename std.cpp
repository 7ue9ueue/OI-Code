#include"bits/stdc++.h"
using namespace std;

int main () {
    int n;cin>>n;
    int mn = 1e9;
    int mx = 0; 
    for (int i=1;i<=n;i++) {
        int x;cin>>x;
        mn = min(mn,x);
        mx = max(mx,x);
    } 
    cout<<mx-mn<<endl;
}