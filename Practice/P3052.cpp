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
const int MAXN = 21;
int c[MAXN],f[1<<21],g[1 << 21],n,w;
#undef int 
int main(){
	#define int long long
	n = Read() , w = Read();
	for(int i = 1 ; i <= n ; i ++) c[i] = Read();
	memset(f,0x3f3f,sizeof(f));
	f[0] = 0;
	for(int i = 0 ; i < (1 << n) ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			if(i & (1 << (j - 1))) continue;
			if(g[i] >= c[j] && f[i|(1 << (j - 1))] >= f[i]){ //Notice
				f[i|(1 << (j - 1))] = f[i];
				g[i|(1 << (j - 1))] = max(g[i|(1 << (j - 1))],g[i] - c[j]);
			}
			else if(g[i] < c[j] && f[i|(1 << (j - 1))] >= f[i] + 1){
				f[i|(1 << (j - 1))] = f[i] + 1;
				g[i|(1 << (j - 1))] = max(g[i|(1 << (j - 1))],w - c[j]);
			}
		}
	}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}

