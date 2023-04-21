#include<iostream>
#define int long long 
using namespace std;

int get (int maximum) 
{
	return rand()%maximum;
}
void makefile (int i)
{
	int n = 100000;
	cout<<n<<endl;
	while (n-->0) {
        int iii = get(3);
        if (i<=14) iii = get(2);
        if (iii==0) cout<<'H';
        if (iii==1) cout<<'S';
        if (iii==2) cout<<'R';
	}
    cout<<endl;
} 
signed main () 
{
	for (int i=1;i<=20;i++) 
	{
		string name = "hand"+to_string(i)+".in";
		freopen(name.c_str(),"w",stdout);
		makefile(i);
	}
    return 0;
}