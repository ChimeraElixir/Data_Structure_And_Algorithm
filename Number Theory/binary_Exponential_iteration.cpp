#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;


int binary_expo_iterative(int a, int b){
    int result=1;

    while(b){
        if(b&1){
            result=(result * 1LL * a) % M;
        }
        a=(a * 1LL * a) % M;
        b>>=1;
    }
    return result;
}
int binary_expo_recursive(int a,int b){
    int res=binary_expo_recursive(a,b/2);

    if(b==0){
        return 1;
    }

    if(b&1){
        return (a * ((res * 1LL* res) % M) % M);
    }
    else{
        return (res * 1LL * res) % M ;
    }
}
int main(){
    cout<<binary_expo_iterative(2,5)<<endl;
}