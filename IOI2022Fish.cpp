#include"bits/stdc++.h"
#include"iostream"
#include"vector"
#include"cstring"
#include"fish.h"
#include"algorithm"
#define ll long long 
#define P pair<long long,long long>
using namespace std;

const int maxm = 3e5+5;
const int maxn = 3e5+5;
const ll inf = 1e18;
vector<P> dp[maxn];
vector<P> fish[maxn];
ll v[10], pter[10];
ll ans;
int n,m;

ll solve (int i, ll val) {
	if (i>n) return 0;
	if (i<=0) return 0;
    int pos = upper_bound(fish[i].begin(),fish[i].end(),make_pair(val,inf))-fish[i].begin()-1;
    //cout<<"solve"<<i<<" "<<val<<" "<<pos<<endl;
    //cout<<"ans"<<fish[i][pos].second<<endl;
    if (pos<0) return 0;
    return fish[i][pos].second;
}

ll max_weights (int N, int M, vector<int> X, vector<int> Y, vector<int> W) {
    n = N; m = M;
    for (int i=0;i<m;i++) {
        fish[X[i]+1].push_back(make_pair(Y[i]+1,W[i]));
        dp[X[i]+1].push_back(make_pair(-inf,-inf));
    }
    for (int i=1;i<=n;i++) {
        fish[i].push_back(make_pair(n+1,0));
        fish[i].push_back(make_pair(0,0));
        dp[i].push_back(make_pair(-inf,-inf));
        dp[i].push_back(make_pair(-inf,-inf));
        sort(fish[i].begin(),fish[i].end());
    }
    for (int i=1;i<=n;i++) for (int j=1;j<fish[i].size();j++) {
        fish[i][j].second += fish[i][j-1].second;
    }
	fish[0].push_back(make_pair(0,0));
    dp[0].push_back(make_pair(0,-inf));
    for (int i=1;i<=n;i++) {
    	for (int j=0;j<=8;j++) pter[j] = v[j] = 0;
        for (int j=3;j<=6;j++) pter[j] = dp[i-2+j%2].size()-1;
        for (int h=0;h<dp[i].size();h++) {
            int pos = fish[i][h].first-1;
            if (pos<0) pos = 0;
            if (i-1>=0) while (pter[1]<dp[i-1].size() and fish[i-1][pter[1]].first-1<=pos) {
                v[1] = max(v[1],dp[i-1][pter[1]].first-solve(i-1,fish[i-1][pter[1]].first-1));
                pter[1]++;
            }

            if (i-2>=0) while (pter[2]<dp[i-2].size() and fish[i-2][pter[2]].first-1<=pos) {
                v[2] = max(v[2],dp[i-2][pter[2]].first-1);
                pter[2]++;
            }

            if (i-3>=0) while (pter[7]<dp[i-3].size() and fish[i-3][pter[7]].first-1<=pos) {
                v[7] = max(v[7],dp[i-3][pter[7]].second+solve(i-2,fish[i-3][pter[7]].first-1));
                pter[7]++;
            }

            if (i-3>=0) while (pter[8]<dp[i-3].size() and fish[i-3][pter[8]].first-1<=pos) {
                v[8] = max(v[8],dp[i-3][pter[8]].first+solve(i-2,fish[i-3][pter[8]].first-1));
                pter[8]++;
            }
            dp[i][h].first = max({dp[i][h].first,v[1]+solve(i-1,pos),v[2]+solve(i-1,pos)});
        }
        for (int h=dp[i].size()-1;h>=0;h--) {
            int pos = fish[i][h].first-1;
            if (i-1>=0) while (pter[3]>=0 and fish[i-1][pter[3]].first-1>=pos) {
                v[3] = max(v[3],dp[i-1][pter[3]].second+solve(i,fish[i-1][pter[3]].first-1));
                pter[3]--;
            }
            if (i-2>=0) while (pter[4]>=0 and fish[i-2][pter[4]].first-1>=pos) {
                v[4] = max(v[4],dp[i-2][pter[4]].second+solve(i-1,fish[i-2][pter[4]].first-1));
                pter[4]--;
            }
            if (i-1>=0) while (pter[5]>=0 and fish[i-1][pter[5]].first-1>=pos) {
                v[5] = max(v[5],dp[i-1][pter[5]].first+solve(i,fish[i-1][pter[5]].first-1));
                pter[5]--;
            }
            if (i-2>=0) while (pter[6]>=0 and fish[i-2][pter[6]].first-1>=pos) {
                v[6] = max(v[6],dp[i-2][pter[6]].first+solve(i-1,fish[i-2][pter[6]].first-1));
                pter[6]--;
            }
            dp[i][h].second = max({dp[i][h].second,v[3]-solve(i,pos),v[4],v[5]-solve(i,pos),v[6]});
        }
        for (int h=0;h<dp[i].size();h++) {
        	int pos = fish[i][h].first-1;
            if (pos<0) pos = 0;
            dp[i][h].first = max({dp[i][h].first,v[7]+solve(i-1,pos),v[8]+solve(i-1,pos)});
        }
    }
    for (int i=1;i<=n;i++) for (int h=0;h<dp[i].size();h++) {
        int pos = fish[i][h].first-1;
        if (pos<0) pos = 0;
        ans = max(ans,dp[i][h].second+solve(i+1,pos));
        ans = max(ans,dp[i][h].first+solve(i+1,pos));
    }
    return ans;
}