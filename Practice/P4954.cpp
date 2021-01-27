#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 50;
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
int g[MAXN],f[MAXN],q[MAXN << 1],l,r,sum[MAXN],a[MAXN],n;
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		a[n - i + 1] = Read();
	}
	for(int i = 1 ; i <= n ; i++){
		sum[i] = sum[i-1] + a[i];
 	}
	f[0] = 0;
	g[0] = 0;
 	for(int i = 1 ; i <= n ; i++){
 		while(l < r && g[q[l+1]] + sum[q[l+1]] <= sum[i]) l++;
 		f[i] = f[q[l]] + 1;
 		g[i] = sum[i] - sum[q[l]];
 		while(l < r && g[q[r]] + sum[q[r]] >= g[i] + sum[i]) r--;
 		q[++r] = i; 
	}
	cout << f[n] << endl;
}
