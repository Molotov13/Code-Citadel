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
const int MAXN = 1000;
/*
int t,n,f[MAXN][MAXN],c[MAXN],v[MAXN];
int main(){
	t = Read() , n = Read();
	for(int i = 1 ; i <= n ; i ++){
		c[i] = Read() , v[i] = Read();
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j =  ; j >= 0 ; j--){
			if(j >= c[i]){
				f[i][j] = max(f[i - 1][j],f[i - 1][j - c[i]] + v[i]);	
			}
			else{
				f[i][j] = f[i - 1][j];	
			}
		}
	}
	cout << f[n][t] << endl;
	return 0;
}
*/
int t,n,f[MAXN],c[MAXN],v[MAXN];
int main(){
	t = Read() , n = Read();
	for(int i = 1 ; i <= n ; i ++){
		c[i] = Read() , v[i] = Read();
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = t ; j >= c[i] ; j --){
			f[j] = max(f[j],f[j - c[i]] + v[i]);
		}
	}
	cout << f[t] << endl;
	return 0;
}

