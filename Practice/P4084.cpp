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
#define int long long
const int MAXN = 1e5 + 50;
const int mod = 1e9 + 7;
int n,k;
int head[MAXN],nxt[MAXN],to[MAXN],tot,co[MAXN],f[MAXN][5];
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void DP(int u,int fa){
	if(co[u]) f[u][co[u]] = 1;
	else f[u][1] = f[u][2] = f[u][3] = 1;
	
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == fa) continue;
		DP(v,u);
		if(co[u] == 1 || co[u] == 0){
			f[u][1] *= (f[v][2] + f[v][3]) % mod;
			f[u][1] %= mod;
		}
		if(co[u] == 2 || co[u] == 0){
			f[u][2] *= (f[v][1] + f[v][3]) % mod;
			f[u][2] %= mod;
		}
		if(co[u] == 3 || co[u] == 0){
			f[u][3] *= (f[v][1] + f[v][2]) % mod;
			f[u][3] %= mod;
		}
	}
}
#undef int 
int main(){
	#define int long long
	n = Read() , k = Read();
	for(int i = 1 ; i < n ; i++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	for(int i = 1 ; i <= k ; i++){
		int x = Read();
		co[x] = Read();	
	}
	DP(1,0);
	cout << ((f[1][1] + f[1][2] + f[1][3]) % mod) << endl;
	return 0;
}
