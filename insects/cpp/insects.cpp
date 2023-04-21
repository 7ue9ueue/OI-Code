#include"insects.h"
#include"bits/stdc++.h"
#include"random"
using namespace std;

const int maxn = 2005;
int ex[maxn];int ix[maxn];
int in[maxn];
int group;

void inside (int i) {
    in[i] = 1;
    move_inside(i);
}
void outside (int i) {
    in[i] = 0;
    move_outside(i);
}

int press () {
    return press_button();
}

vector<int> rem,sel;
int cnt;

int check (int mid, int N, bool flag) {
    rem.clear();
    if (!flag) sel.clear();
    for (int i=0;i<N;i++) {
        if (cnt==group*mid) break;
        if (in[i]||ex[i]) continue;
        inside(i);
        int w = press();
        if (w>mid) {
            outside(i);
            rem.push_back(i);
        }
        else {
            cnt++;
            sel.push_back(i);
        }
    }
    if (cnt==group*mid) return true;
    else return false;
}

void del (int N) {
    for (int i=0;i<N;i++) {
        if (in[i]&&!ix[i]) {
            outside(i);
            cnt--;
        }
    }
    for (int u:rem) ex[u] = 1;
}

void upd (int N) {
    for (int u:sel) ix[u] = 1;
}

int min_cardinality (int N) {
    srand(time(0));
    sel.push_back(0);
    inside(0); group++;cnt++;
    for (int i=1;i<N;i++) {
        inside(i);
        int w = press();
        if (w==1) {
            group++;
            cnt++;
            sel.push_back(i);
        }
        else outside(i);
    }
    if (group==N) return 1;
    int left = 1;int right = N/group;
    int ans = -1;
    while (left<=right) {
        int mid = (left+right+rand()%2)/2;
        if (check(mid,N,(left==1)&&(right==N/group))) {
            left = mid+1;
            ans = mid;
            upd(N);
        }
        else {
        	  right = mid-1;
            del(N);
        }
    }
    return ans;
}