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
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 1e5 + 50;
int head[MAXN],val[MAXN],to[MAXN << 1],nxt[MAXN << 1],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int Inde[MAXN],f[MAXN],n;
queue<int>Q;
void bfs(){
	while(!Q.empty()){
		int now = Q.front();Q.pop();
		f[now] = max(f[now],val[now]);
		for(int i = head[now] ; i ; i = nxt[i]){
			int v = to[i];
			f[v] = max(f[v],f[now] + val[v]);
			Inde[v]--;
			if(!Inde[v]) Q.push(v);
		}
	}
}
#undef int 
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		int x = Read();
		val[i] = Read();
		while(x = Read()){
			add(i,x);
			Inde[x] ++;	
		}
	}
	for(int i = 1 ; i <= n ; i++){
		if(Inde[i] == 0){
			Q.push(i);
		}
	}
	bfs();
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
	return 0;
}
