#include<iostream>
#define int long long 
using namespace std;

int get (int maximum) 
{
	return rand()%maximum+1;
}
void makefile (int i)
{
	int n = 80000;
	if (i<=6) {
        n = 5000;
	}
	cout<<n<<endl;
    int out = 0;
	while (n-->0) {
        if (7<=i && i<=12) {
            out = get(2);
        }
        else if (13<=i && i<=16) {
            out += 1;
            if (get(100)==1) out += 1;
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
		string name = "market"+to_string(i)+".in";
		freopen(name.c_str(),"w",stdout);
		makefile(i);
	}
    return 0;
}