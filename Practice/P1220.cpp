#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100;
inline int Read(){
	int s = 0 ,w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int n,c;
int f[MAXN][MAXN][3];
int a[MAXN],b[MAXN],sum[MAXN]; 
int main(){
	n = Read() , c = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read() , b[i] = Read();
		sum[i] = sum[i-1] + b[i];
	}
	memset(f,127,sizeof(f));
	f[c][c][1] = f[c][c][0] = 0;
	for(int l = 2 ; l <= n ; l++){
		for(int i = 1 ; i + l - 1 <= n ; i++){
			int j = i + l - 1;
			f[i][j][0] = min(f[i+1][j][1] + (a[j] - a[i]) * (sum[n] - sum[j] + sum[i]),f[i+1][j][0] + (a[i+1] - a[i]) * (sum[n] - sum[j] + sum[i]));
			f[i][j][1] = min(f[i][j-1][0] + (a[j] - a[i]) * (sum[n] - sum[j-1] + sum[i-1]),f[i][j-1][1] + (a[j] - a[j-1]) * (sum[n] - sum[j - 1] + sum[i-1]));
		}
	}
	cout << min(f[1][n][0],f[1][n][1]) << endl;
	return 0;
}
