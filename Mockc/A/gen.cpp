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
	cout<<n<<endl;
    int out = 0;
	while (n-->0) {
        out = get(100000);
        cout<<out<<" ";
	}
} 
signed main () 
{
	for (int i=1;i<=20;i++) 
	{
		string name = "range"+to_string(i)+".in";
		freopen(name.c_str(),"w",stdout);
		makefile(i);
	}
    return 0;
}