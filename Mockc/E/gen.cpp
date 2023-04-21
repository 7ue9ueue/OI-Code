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
	if (i<=6) {
        n = 5000;
	}
	cout<<n<<endl;
    int out = 0;
    int fff = get(1000);
	while (n-->0) {
        if (7<=i && i<=12) {
            out = fff;
        }
        else if (13<=i && i<=16) {
            if (n%2) out = 0;
            else out = get(100000);
        }
        else {
            out = get(100000);
        }
        cout<<out<<" ";
	}
} 
signed main () 
{
	for (int i=1;i<=20;i++) 
	{
		string name = "select"+to_string(i)+".in";
		freopen(name.c_str(),"w",stdout);
		makefile(i);
	}
    return 0;
}