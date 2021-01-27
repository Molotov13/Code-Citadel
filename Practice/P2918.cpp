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
int f[500050],v[150],c[150],H,n,m;
#undef int 
int main(){
	#define int long long
	n = Read() , H = Read();
	for(int i = 1 ; i <= n ; i ++){
		v[i] = Read();
		c[i] = Read();
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = c[i] ; j <= 500050 ; j ++){
			f[j] = max(f[j],f[j - c[i]] + v[i]);
		}
	}
	for(int i = 1 ; i <= 500050 ; i ++){
		if(f[i] >= H){
			cout << i << endl;
			return 0;
		}
	}
}
