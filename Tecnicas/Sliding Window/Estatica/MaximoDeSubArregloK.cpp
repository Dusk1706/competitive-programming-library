#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define FOR(x, b) for(int x = 0; x <b; x++)
typedef long long ll;
typedef vector<int> vi;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
ll n, m, q, k, l, r, x, y, z, ans=0;

/*
    https://omegaup.com/arena/problem/maximo-en-subarreglo-1/#problems
    Dado un arreglo de N enteros y un entero K escribe un programa que 
    obtenga el maximo valor de cada subarreglo de tamaño K
    Input:
    5 2
    1 5 3 2 4
    Output:
    5 5 3 4
*/

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
	multiset<int> s;
	vector<int> ret;
	for (int i = 0; i < k; i++) { s.insert(nums[i]); }
  
	for (int i = k; i < nums.size(); i++) {
		ret.push_back(*s.rbegin());
		s.erase(s.find(nums[i - k]));
		s.insert(nums[i]);
	}
	ret.push_back(*s.rbegin());
  return ret;
}

int main(){ _
    
  cin>>n>>k;
  vi a(n);
  FOR(i,n) cin>>a[i];
  vi ans=maxSlidingWindow(a,k);
  for(auto x:ans) cout<<x<<" ";
  return 0;
}