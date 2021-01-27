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
const int MAXN = 4e5 + 50;
int n,m,s,diametr;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],val[MAXN << 1],d[MAXN],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	val[tot] = v;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs1(int now,int f){
	for(int i = head[now] ; i ; i = nxt[i]){
		int v = to[i];
		if(f == v) continue;
		d[v] = d[now] + val[i];
		dfs1(v,now);
		if(d[v] > diametr){
			diametr = d[v];
			s = v;
		}
	}
}
void dfs2(int now,int f){
	for(int i = head[now] ; i ; i = nxt[i]){
		int v = to[i];
		if(f == v) continue;
		d[v] = d[now] + val[i];
		dfs2(v,now);
	}
}
int d2[MAXN],ans;
void dfs3(int now,int f){
	for(int i = head[now] ; i ; i = nxt[i]){
		int v = to[i];
		if(f == v) continue;
		d2[v] = d2[now] + val[i];
		dfs3(v,now);
	}
}
int t,diameter = 0;
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i < n ; i++){
		int x = Read() , y = Read() , v = Read();
		add(x,y,v);
		add(y,x,v);
	}
	dfs1(1,0);
	memset(d,0,sizeof(d));
	dfs2(s,0);
	for(int i = 1 ; i <= n ; i++){
		if(diameter < d[i]){
			diameter = d[i];
			t = i;
		}
	}
	dfs3(t,0);
	for(int i = 1 ; i <= n ; i++){
		ans = max(ans,min(d[i],d2[i]));
	}
	cout << (ans + diameter) << endl;
	return 0;
}
