#include"bits/stdc++.h"
#include"testlib.h"
using namespace std;

const int maxn = 1e6+5;
int a[maxn];int b[maxn];
map<int,int> m;

int n,k, answer;

int main(int argc, char *argv[])
{
    n = inf.readInt();
    k = inf.readInt();
    answer = ans.readInt();
    for (int i=1;i<=n;i++) {
        a[i] = inf.readInt();
        m[a[i]]++;
    }
    for (int i=1;i<=n;i++) {
        b[i] = ouf.readInt();
        if (b[i]==-1) 
        {
            if (answer==-1) quitf(_ok,"Accepted");
            else quitf(_wa,"Hint: There is an arrangement!");
        }
        m[b[i]]--;
    }
    for (auto it=m.begin();it!=m.end();it++) {
        if (it->second) quitf(_fail,"invalid arrangement :(");
    }
    int count = 0;
    for (int i=n;i>=1;i--) 
    {
        if (count>b[i]) count++;
    }
    if (count==k) quitf(_ok,"Accepted");
    else quitf(_wa,"Hint: your K is incorrect!");
}
