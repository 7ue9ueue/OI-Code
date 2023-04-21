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
	while (n-->0) {
        if (11<=i && i<=15) {
            out = 1;
        }
        else {
            int rd = get(100);
            if (rd==1) out = 1;
            else out = 0;
        }
        if (n==0) out = 1;
        if (n==4999||n==99999) out = 1;
        cout<<out;
	}
} 
signed main () 
{
	for (int i=1;i<=20;i++) 
	{
		string name = "distance"+to_string(i)+".in";
		freopen(name.c_str(),"w",stdout);
		makefile(i);
	}
    return 0;
}