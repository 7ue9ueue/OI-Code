//#include"insects.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 2005;
int ex[maxn];int res[maxn];
int in[maxn];
int big;const int SQR = 40;
int group;
//
int cnt[maxn];
int a[maxn];
//
void inside (int i) {
    in[i] = 1;
    cnt[a[i]]++;
    //move_inside(i);
}
void outside (int i) {
    in[i] = 0;
    cnt[a[i]]--;
    //move_outside(i);
}

int press () {
    int m = 0;
    for (int i=0;i<maxn;i++) {
        m = max(m,cnt[i]);
    }
    return m;
    //return press_button();
}

vector<int> rem;

int check (int mid, int N, int type) {
    int cnt = 0;
    rem.clear();
    for (int i=0;i<N;i++) {
        if (in[i]||ex[i]) continue;
        inside(i);
        int w = press();
        if (w>mid) {
            outside(i);
            rem.push_back(i);
        }
        else cnt++;
    }
    for (int i=0;i<N;i++) {
        if (in[i]) outside(i);
    }
    if (cnt==group*mid) return true;
    else return false;
}

void del () {
    for (int u:rem) ex[u] = 1;
}

int min_cardinality (int N) {
    inside(0); group++;
    for (int i=1;i<N;i++) {
        inside(i);
        if (press()==1) group++;
        else outside(i);
    }
    for (int i=0;i<N;i++) {
        if (in[i]) outside(i);
    }
    if (group==N) return 1;
    int left = 1;int right = N;
    int ans = -1;int type = 1;
    while (left<=right) {
        int mid = (left+right)/2;
        if (check(mid,N,type)) {
            left = mid+1;
            ans = mid;
            type = 1;
        }
        else {
        	right = mid-1;
            del();
            type = 0;
        }
    }
    return ans;
}

int main () { 	
	int N;cin>>N;
	for (int i=0;i<N;i++) cin>>a[i];
	cout<<min_cardinality(N)<<endl;
}