#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define FOR(x, b) for(int x = 0; x <b; x++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const int MAXN=1000 + 5;

int dp[MAXN][MAXN];

int LongestCommonSubsequence(string &s, string &t){
  memset(dp, 0, sizeof(dp));
  int n = s.size(), m = t.size();
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(s[i - 1] == t[j - 1]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }else{
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    } 
  }
  return dp[n][m];
}

int main(){ _
  string s, t;
  while(cin>>s && s!="#"){
    cin>>t;
    
    int lcs = LongestCommonSubsequence(s,t);
    cout<< lcs <<ENDL;
  }


  return 0;
}