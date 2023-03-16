#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll gcd(ll a, ll b){return (b?gcd(b,a%b):a);}
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }

pair<int, int> gcdExtended(int a, int b){
    int r, y = 0, x1 = 0, y1 = 1, tx, ty;
    int x = 1;
    while(b > 0){
        r= a % b;
        tx = x1, ty = y1;
        x1 = x - (a / b) * x1;
        x = tx;
        y1 = y - (a / b) * y1;
        y = ty;
        a = b;
        b = r;
    }
    return {x, y};
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);




    return 0;
}