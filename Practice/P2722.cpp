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
int f[10000050],v[10500],c[10500],n,m;
#undef int 
int main(){
	#define int long long
	m = Read() , n = Read();
	for(int i = 1 ; i <= n ; i ++){
		v[i] = Read();
		c[i] = Read();
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = c[i] ; j <= m ; j++){
			f[j] = max(f[j - c[i]] + v[i],f[j]);
		}
	}
	cout << f[m] << endl;
	return 0;
}
