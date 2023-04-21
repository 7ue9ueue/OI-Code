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
	if (i>=10) {
		
	}
	while (n-->0) {
		cout<<get(100000)<<" ";
	}
} 
int main () 
{
	for (int i=1;i<=20;i++) 
	{
		string name = "./A/market"+to_string(i)+".in";
		freopen(name.c_str(),"w",stdout);
		makefile(i);
	}
}