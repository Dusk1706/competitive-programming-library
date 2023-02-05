#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin>>s;
    string m=s;
    reverse(m.begin(),m.end());
    if(s==m){
        cout<<"Si";
    }else{
        cout<<"No";
    }
    return 0;
}