#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

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
    if(n<=1){
        return n;
    } 
    if(memo[n]==0){
        memo[n]=fiboRecursivo(n-1)+fiboRecursivo(n-2);
    }
    return memo[n];
}

long long fiboSinMemo(int n){
    if(n <= 1){
        return n;
    }
    return fiboSinMemo(n - 1) + fiboSinMemo(n - 2);
}


int main(){
    int n;
    cin>>n;
    // cout<<"Fibonacci sin memoizacion: "<<fiboSinMemo(n)<<endl;
    // cout<<"Fibonacci Iterativo: "<<fiboIterativo(n)<<endl;
    cout<<"Fibonacci recursivo con memoizacion: "<<fiboRecursivo(n)<<endl;
    
    return 0;
}