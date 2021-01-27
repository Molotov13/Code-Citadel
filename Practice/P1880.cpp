#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int dp[220][220],dp2[220][220],a[220],n,m,s[220];
#undef int 
int main(){
	#define int long long
	n = Read();
	int ans1 = 192608170 , ans2 = 0;
	for(int i = 1 ; i <= n ; i ++) a[i] = Read();
	for(int i = 1 ; i <= n ; i ++) a[i + n] = a[i];
	for(int i = 1 ; i <= n * 2 ; i ++) s[i] = s[i - 1] + a[i];
	memset(dp,0,sizeof(dp));
	memset(dp2,127,sizeof(dp2));
	for(int i = 1 ; i <= 2 * n ; i ++) dp2[i][i] = 0;
	for(int p = 1 ; p < n ; p ++){
		for(int i = 1 , j = i + p ; (i <= 2 * n) && (i + p <= 2 * n) ; i ++ , j = i + p){
			for(int k = i ; k < j ; k ++){
				dp[i][j] = max(dp[i][j],dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
				dp2[i][j] = min(dp2[i][j],dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
			}
		}
		//cout << dp2[p][p + n - 1] << endl;
		
	}
	for(int p = 1 ; p <= n ; p ++){
		ans1 = min(ans1,dp2[p][p + n - 1]);
		ans2 = max(ans2,dp[p][p + n - 1]);
	}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}

