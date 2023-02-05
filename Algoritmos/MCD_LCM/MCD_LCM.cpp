#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll gcd(ll a,ll b) { return (a % b == 0) ? b : gcd(b, a % b);}

ll lcm(ll a, ll b){//Minimo comun multiplo
    return ((ll)a * b) / gcd(a, b);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);




    return 0;
}