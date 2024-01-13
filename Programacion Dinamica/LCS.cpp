#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define FOR(x, b) for(int x = 0; x <b; x++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const int MAXN=1000 + 5;

int dp[MAXN][MAXN];
string s, t;
int n, m;

int LongestCommonSubsequence(){
  memset(dp, 0, sizeof(dp));
  
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

string pathLCS(){
  string ans="";
	int i=n,j=m;
	while(i!=0 && j!=0){
		if(dp[i-1][j]==dp[i][j]){
			i--;
		}else if(dp[i][j-1]==dp[i][j]){
			j--;
		}else{
			ans=s[i-1]+ans;
			i--;
			j--;
		}
	}
  return ans;
}

int main(){ _
  
  while(cin>>s && s!="#"){
    cin>>t;
    n = s.size(), m = t.size();
    
    cout<< LongestCommonSubsequence() <<ENDL;
    cout<< pathLCS() << ENDL;
  }


  return 0;
}