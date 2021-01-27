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
int f[30][30500],v[30],c[30],n,m;
#undef int 
int main(){
	#define int long long
	m = Read() , n = Read();
	for(int i = 1 ; i <= n ; i ++){
		c[i] = Read();
		v[i] = Read() * c[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = m ; j >= 0 ; j --){
			if(j >= c[i]){
				f[i][j] = max(f[i - 1][j],f[i - 1][j - c[i]] + v[i]);
			}
			else{
				f[i][j] = f[i - 1][j];
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
