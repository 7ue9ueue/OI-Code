#include<iostream>
#define int long long 
using namespace std;

int get (int maximum) 
{
	return rand()%maximum+1;
}
void makefile (int i)
{
	int n = 100000;
	if (i<=10) {
        n = 5000;
	}
	cout<<n<<endl;
    int out = 0;
    for (int j=1;j<=n;j++) {
        int bbb = get(10);
        if (bbb==1) cout<<"G";
        else cout<<"H";
    } 
    cout<<endl;
	for (int j=1;j<=n;j++) {
        if (11<=i && i<=15) {
            out = j;
        }
        else {
            int bbb = get(10);
            if (bbb<=5) out = j;
            else out = n-j;
        }
        cout<<out<<" ";
	}
} 
signed main () 
{
	for (int i=1;i<=20;i++) 
	{
		string name = "leader"+to_string(i)+".in";
		freopen(name.c_str(),"w",stdout);
		makefile(i);
	}
    return 0;
}