#include"bits/stdc++.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void action (string name, string Nname) {
    
    if (!rename(name.c_str(), Nname.c_str()))
    {
        std::cout << "rename success "<< std::endl;
    }
    else
    {
        std::cout << "rename error "<< std::endl;
    }
}

int main ()
{
    string name, rename;
    for (int i=1;i<=17;i++) {
        name = "distance"+to_string(i)+".in";
        rename = "leader"+to_string(i)+".in";
        action(name,rename);
        name = "distance"+to_string(i)+".out";
        rename = "leader"+to_string(i)+".out";
        action(name,rename);
    }
    return 0;
}