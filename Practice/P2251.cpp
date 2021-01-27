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
const int MAXN = 2e6 + 50;
int st[MAXN][20],n,m,s[MAXN];
int main(){
	n = Read() , m = Read();
	s[0] = 19260817;
	for(int i = 1 ; i <= n ; i++){
		st[i][0] = Read();
		s[i] = min(s[i - 1],st[i][0]);
	}
	for(int i = 1 ; i <= log2(n) ; i++){
		for(int j = 1 ; j + (1 << i) - 1 <= n ; j ++){
			st[j][i] = min(st[j][i - 1],st[j + (1 << (i - 1))][i - 1]);
		}
	}
	int k = log2(m);
	cout << 0 << endl;
	for(int i = 1 ; i < n ; i ++){
		if(i - (1 << k) + 1 <= 0){
			printf("%d\n",s[i]);
		}
		else printf("%d\n",min(st[max(i - m + 1,1)][k],st[i - (1 << k) + 1][k]));
	}
	return 0;
}

