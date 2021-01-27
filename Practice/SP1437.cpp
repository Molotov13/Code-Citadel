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
int n,m,s,dia;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],d[MAXN],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs1(int now,int f){
	for(int i = head[now] ; i ; i = nxt[i]){
		int v = to[i];
		if(f == v) continue;
		d[v] = d[now] + 1;
		dfs1(v,now);
		if(d[v] > dia){
			dia = d[v];
			s = v;
		}
	}
}
void dfs2(int now,int f){
	for(int i = head[now] ; i ; i = nxt[i]){
		int v = to[i];
		if(f == v) continue;
		d[v] = d[now] + 1;
		dfs2(v,now);
	}
}
int t,diameter = 0;
#undef int 
int main(){
	#define int long long
	n = Read() ;
	for(int i = 1 ; i < n ; i++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
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
	cout << diameter << endl;
	return 0;
}
