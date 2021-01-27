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
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],val[MAXN << 1],tot,HafDia;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int T,n,k,maxl,s,d[MAXN],fa[MAXN],dia,t;
void dfs1(int u,int f){
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == f) continue;
		d[v] = d[u] + val[i];
		dfs1(v,u);
		if(maxl < d[v]){
			maxl = d[v];
			s = v;
		}
	}
}
void dfs2(int u,int f){
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == f) continue;
		d[v] = d[u] + val[i];
		fa[v] = u;
		dfs2(v,u);
		if(dia < d[v]){
			dia = d[v];
			t = v;
		}
	}
}
bool OnDia[MAXN];
bool dfs3(int u,int f){
	bool res = false;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == f) continue;
		d[v] = d[u] + 1;
		//cout << v << ":" << d[v] << " " << dia << " " << dia /2 << " " << OnDia[v] <<endl;
		if(!OnDia[v] && d[v] + max((dia - HafDia),HafDia) >= k){
			return true;
		}
		if(OnDia[v] && (((d[v] + (dia - HafDia) >= k)&&(HafDia - d[v] >= k)) || ((d[v] + HafDia >= k)&&((dia - HafDia) - d[v]) >= k))){
			return true;
		}
		res |= dfs3(v,u);
	}
	return res;
}
#undef int 
int main(){
	#define int long long
	T = Read();
	while(T --){
		//cout << T <<"W";
		n = Read() , k = Read();
		memset(head,0,sizeof(head));
		memset(fa,0,sizeof(fa));
		tot = 0;
		for(int i = 1 ; i < n ; i++){
			int x = Read() , y = Read() , v = Read();
			add(x,y,v);
			add(y,x,v);
		}
		d[0] = 1;
		maxl = s = 0;
		dfs1(1,0);
		dia = d[s] = 0;
		dfs2(s,0);
		if(dia < k){
			cout << "Yes" << endl;
			continue;
		}
		int tmp = t;
		OnDia[s] = true;
		while(tmp != s){
			OnDia[tmp] = true;
			tmp = fa[tmp];
		}
		int now = t,DpS = 0;
		while(abs(d[now] - (dia+1)/2) > abs(d[fa[now]] - (dia+1)/2)){
			now = fa[now];
			DpS ++;
		}
		HafDia = dia - d[now];
		now = t;
		for(int i = 1 ; i <= DpS ; i++){
			now = fa[now];
		}
		cout << HafDia << " DD " << now << " DD " << dia<< endl;
		d[now] = 0;
		if((dia - HafDia >= k)&&(HafDia >= k)) cout << "Baka Chino" << endl;
		else if(dfs3(now,0)) cout << "Baka Chino" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
