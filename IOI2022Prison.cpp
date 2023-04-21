#include"bits/stdc++.h"
#include"vector"
#include"prison.h"
using namespace std;

vector< vector<int> > ans;

void calculate (int pid, int rep, int c, int loth, int roth, int l, int r) {
    int cid = rep+rep+rep+c;
    for (int i=l;i<=r;i++) ans[pid][i] = cid; 
    for (int i=loth;i<=l;i++) ans[cid][i] = -1-ans[cid][0];
    for (int i=r;i<=roth;i++) ans[cid][i] = -2+ans[cid][0];
    if (l+1>r-1) return;
    if (l+1+2>r-1) {
        calculate(u,rep+1,1,l,r,l+1,r-1);
        return;
    }
    if (l+1+4>r-1) {
        calculate(u,rep+1,1,l,r,l+1,(l+r) / 2);
        calculate(u,rep+1,2,l,r,(l+r)/2+1,r-1);
    }
    int m1 = (l+l+r+1+1-1)/3;
    int m2 = (l+r+r+1-1-1)/3;
    calculate(cid,rep+1,1,l,r,l+1,m1);
    calculate(cid,rep+1,2,l,r,m1+1,m2);
    calculate(cid,rep+1,3,l,r,m2+1,r-1);
}
 
void initialize (int len, int n) {
    for (int i=0;i<=len;i++) ans.push_back(vector<int>(n+1,0));
    for (int i=0;i<=len;i++) {
        if ((i+2)%6<3) ans[i][0] = 1;
    }
}
vector< vector<int> > devise_strategy(int n) {
    initialize(24,n);
    calculate(0,-1,3,1,n,1,n);
    return ans;
}