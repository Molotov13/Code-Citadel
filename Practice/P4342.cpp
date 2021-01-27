#include<bits/stdc++.h>
#define int long long
using namespace std;
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
const int MAXN = 2000;
bool typ[MAXN];
int a[MAXN],dp[2][MAXN][MAXN],n,ans;
vector<int>pos;
#undef int 
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		char c;
		scanf("%c",&c);
		typ[i] = typ[i + n] = (c == 't' ? 0 : 1);
		a[i] = a[i + n] = Read();
	}
	memset(dp[0],128,sizeof(dp[0]));
	memset(dp[1],127,sizeof(dp[1]));
	int m = 2 * n - 1;
	for(int i = 1 ; i <= m ; i ++){
		dp[0][i][i] = dp[1][i][i] = a[i];
	}
	for(int l = 2 ; l <= m  ; l ++){
		for(int i = 1 ; i + l - 1 <= m ; i++){
			int j = i + l - 1;
			//if(typ[j]) dp[i][j][0] = max(dp[i][j][0],dp[i][j - 1][0] * dp[j][j][0]);
			//else  dp[i][j][0] = max(dp[i][j][0],dp[i][j - 1][0] + dp[j][j][0]);
			for(int k = i ; k < j ; k ++){
				if(!typ[k + 1]){
					dp[0][i][j] = max(dp[0][i][j],dp[0][i][k] + dp[0][k + 1][j]);
					dp[1][i][j] = min(dp[1][i][j],dp[1][i][k] + dp[1][k + 1][j]);
				}
				else{
					dp[0][i][j] = max(dp[0][i][j],dp[0][i][k] * dp[0][k + 1][j]);
					dp[0][i][j] = max(dp[0][i][j],dp[1][i][k] * dp[0][k + 1][j]);
					dp[0][i][j] = max(dp[0][i][j],dp[0][i][k] * dp[1][k + 1][j]);
					dp[0][i][j] = max(dp[0][i][j],dp[1][i][k] * dp[1][k + 1][j]);
					
					dp[1][i][j] = min(dp[1][i][j],dp[0][i][k] * dp[0][k + 1][j]);
					dp[1][i][j] = min(dp[1][i][j],dp[1][i][k] * dp[0][k + 1][j]);
					dp[1][i][j] = min(dp[1][i][j],dp[0][i][k] * dp[1][k + 1][j]);
					dp[1][i][j] = min(dp[1][i][j],dp[1][i][k] * dp[1][k + 1][j]);
				}  
			}
			//cout << i << "," << j << ":" << dp[0][i][j] << endl;
			if(l == n) ans = max(ans,dp[0][i][n + i - 1]);
		}
	}
	int ans=-0x3f3f3f3f3f3f3f3f;
	for(int i = 1 ; i <= n ; i++){
		if(dp[0][i][i + n -1] > ans){
			ans = dp[0][i][i + n - 1];
			pos.clear();
			pos.push_back(i);
		}
		else if(dp[0][i][i + n - 1] == ans) pos.push_back(i);
	}
	if(ans == 1){
		cout << 0 << endl << 1;
		return 0;
	}
	printf("%d\n",ans);
	for(int i = 0 ; i < pos.size() ; i++) printf("%d ",pos[i]);
	return 0;
}
