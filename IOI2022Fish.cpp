#include <iostream>
using namespace std;

int main() {
    freopen("phonecall.in","r",stdin);
    freopen("phonecall.out","w",stdout);
    int N, D;
    cin>>N>>D;
    int FS = 0;
    int arr[N]{};
    for (int i = 0; i < N; i++){
        cin>>arr[i];
    }
    for (int i = 0; i < N; i+=D){
        if (arr[i] == 1){
            FS = FS+=1;
        }
    }
    cout<<FS;
}
