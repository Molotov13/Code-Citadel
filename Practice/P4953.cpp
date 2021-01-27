//20200928 09:25 By Molotov
#include<bits/stdc++.h>
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
int n,e,d,ans = 19260817;
int f[110][110][110];
int main(){
	n = Read() , e = Read() , d = Read();
	memset(f,127,sizeof(f));
	f[n][e][e] = 0;
	for(int i = n ; i >= 1 ; i --){
		for(int j = e ; j >= 0 ; j --){
			for(int k = e ; k >= 0 ; k --){
				int p = 1;
				while(p*p <= j && p <= k){
					f[i][j - p * p][k - p] = min(f[i][j - p * p][k - p] ,f[i][j][k]+1);
					p++;
				}
				p = 1;
				while(p*p <= k){
					f[i-1][k - p * p][k - p] = min(f[i-1][k - p * p][k - p],f[i][j][k] + 1);
					p++;
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= e ; j++){
			ans = min(ans,f[i][j][e-d]);
		}
	}
	cout << ans << endl;
}
