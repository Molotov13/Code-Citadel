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
const int MAXN = 1e5 + 50;
int n,st[MAXN][40],a[MAXN],m;
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		st[i][0] = a[i];
	}
	for(int i = 1 ; i <= log2(n) ; i ++){
		for(int j = 1 ; j + (1 << i) - 1 <= n ; j ++){
			st[j][i] = max(st[j][i - 1],st[j + (1 << (i - 1))][i - 1]);
		}
	}
	for(int i = 1 ; i <= m ; i ++){
		int l = Read() , r = Read();
		int k = log2(r - l + 1);
		printf("%d\n",max(st[l][k],st[r - (1 << k) + 1][k]));
	}
}

