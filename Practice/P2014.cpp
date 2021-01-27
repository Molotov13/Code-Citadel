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
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 1000;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],tot;
int n,m;
int f[MAXN][MAXN];
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int DP(int u){
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		DP(v);
		for(int j = m + 1 ; j >= 1 ; j --){
			for(int k = 1 ; k < j ; k ++){
				f[u][j] = max(f[u][j],f[v][k] + f[u][j - k]); 
			}	
		}
	}
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		int u = Read();
		f[i][1] = Read();
		add(u,i);
	}
	DP(0);
	cout << f[0][m + 1] << endl;
	return 0;
}
