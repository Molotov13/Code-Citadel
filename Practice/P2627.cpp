#include <bits/stdc++.h>
using namespace std;
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 1e5 + 50;
#define int long long 
int n,k,a[MAXN],ans,sum,dp[MAXN],l,r,q[MAXN*2];
#undef int 
int main(){
	n = Read() , k = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		sum += a[i];
	}
	dp[0] = 0;
	q[1] = 0;
	l = 0 , r = 0;
	for(int i = 1 ; i <= n + 1 ; i++){
		/*cout << "Q1:";
		for(int j = l ; j <= r ; j++) cout << q[j] << " ";
		cout << endl;*/
		while(l < r && q[l] + k + 1 < i) l++;
		/*cout << "Q2:";
		for(int j = l ; j <= r ; j++) cout << q[j] << " ";
		cout << endl;*/
		//cout << i << endl;
		dp[i] = dp[q[l]] + a[i];
		//cout << dp[i] << " " << q[l] << endl;
		while(l < r && dp[i] <= dp[q[r]]) r--;
		q[++r] = i; 
	}
	cout << sum - dp[n+1] << endl;
	return 0;
}
