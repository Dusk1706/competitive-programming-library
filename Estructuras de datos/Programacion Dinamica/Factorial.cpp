#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
map<ull,ull> m;

ull f(int n){
    if(m[n]!=0)
        return m[n];
    if(n<0)
        return 0;
    if(n==0||n==1)
        return 1;
    return m[n]=n*f(n-1);
}

int main(){
    ull n;
    cin>>n;
    cout<<f(n);
}