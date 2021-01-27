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
int a[250],dp[250][250],n;
#undef int 
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i ++) a[i] = Read();
	memset(dp,0,sizeof(dp));
	for(int i = 1 ; i <= n ; i ++) dp[i][i] = a[i];
	for(int l = 1 ; l <= n ; l ++){
		for(int i = 1 ; i + l - 1 <= n ; i ++){
			int j = i + l - 1;
			if(a[i] == dp[i + 1][j]) dp[i][j] = max(dp[i][j],a[i] + 1);
			for(int k = i ; k < j ; k ++){
				if(dp[i][k] == dp[k + 1][j]) dp[i][j] = max(dp[i][j],dp[i][k] + 1);
			}
		}
	}
	int ans = 0;
	for(int l = 1 ; l <= n ; l ++){
		for(int i = 1 ; i + l - 1 <= n ; i ++){
			int j = i + l - 1;
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}

