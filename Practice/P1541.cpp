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
int dp[50][50][50][50],a[400],n,m,num[10];
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++) a[i] = Read();
	for(int i = 1 ; i <= m ; i ++){
		int x = Read();
		num[x] ++;
	}
	dp[0][0][0][0] = a[1];
	for(int i = 0 ; i <= num[1] ; i ++){
		for(int j = 0 ; j <= num[2] ; j ++){
			for(int k = 0 ; k <= num[3] ; k ++){
				for(int l = 0 ; l <= num[4] ; l++){
					if(i > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i - 1][j][k][l] + a[i * 1 + j * 2 + k * 3 + l * 4 + 1]);
					if(j > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j - 1][k][l] + a[i * 1 + j * 2 + k * 3 + l * 4 + 1]);
					if(k > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k - 1][l] + a[i * 1 + j * 2 + k * 3 + l * 4 + 1]);
					if(l > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k][l - 1] + a[i * 1 + j * 2 + k * 3 + l * 4 + 1]);
				}
			}
		}
	}
	cout << dp[num[1]][num[2]][num[3]][num[4]] << endl;
	return 0;
}

