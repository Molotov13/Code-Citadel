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
const int MAXN = 300;
int f[MAXN][MAXN],mc[MAXN],tc[MAXN],n,m,t;
int main(){
	n = Read() , m = Read() , t = Read();
	for(int i = 1 ; i <= n ; i ++){
		mc[i] = Read();
		tc[i] = Read();
	}
	/*
	for(int i = 1 ; i <= n ; i ++){
		for(int j = m ; j >= 0 ; j --){
			for(int k = t ; k >= 0 ; k --){
				if(j >= mc[i] && k >= tc[i]){
					f[i][j][k] = max(f[i - 1][j][k],f[i - 1][j - mc[i]][k - tc[i]] + 1);	
				}
				else{
					f[i][j][k] = f[i - 1][j][k];
				}
				//cout << i << "," << j << "," << k << ":" << f[i][j][k] << endl;
			}
		}
	}
	cout << f[n][m][t] << endl;*/
	for(int i = 1 ; i <= n ; i ++){
		for(int j = m ; j >= mc[i] ; j--){
			for(int k = t ; k >= tc[i] ; k --){
				f[j][k] = max(f[j][k],f[j - mc[i]][k - tc[i]] + 1);
			}
		}
	}
	cout << f[m][t] << endl;
	return 0;
}

