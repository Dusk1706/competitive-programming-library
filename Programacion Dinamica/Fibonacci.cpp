#include <bits/stdc++.h>

using namespace std;

//Fibonacci manera iterativa complejidad O(n)
long long fiboIterativo(int n){
    long long arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}

//Fibonacci de manera recursiva con memoizacion O(n)
long long memo[1001];

long long fiboRecursivo(int n){
    if(memo[n]!=-1)return memo[n];
    if(n<=2) return 1;
    memo[n]=fiboRecursivo(n-1)+fiboRecursivo(n-2);
    return memo[n];
}


int main(){
    memset(memo, -1, sizeof memo);
    // cout<<fiboIterativo(0)<<endl;
    cout<<fiboRecursivo(0)<<endl;

    return 0;
}