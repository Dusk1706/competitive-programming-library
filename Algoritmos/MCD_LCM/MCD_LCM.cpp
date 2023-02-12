#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll gcd(ll a, ll b){return (b?gcd(b,a%b):a);}
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);




    return 0;
}