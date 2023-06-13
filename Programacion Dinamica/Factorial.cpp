#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
long long memo[MAX];

long long factorial(int n){
    if(memo[n]!=0){
        return memo[n];
    }
    if(n<0){
        return 0;
    }
    if(n==0 || n==1){
        return 1;
    }
    return memo[n] = n * factorial(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<factorial(n);
}