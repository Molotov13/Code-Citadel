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
const int MAXN = 5e5 + 50;
int n,m;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],tot;
int a[MAXN];
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int fa[MAXN],sz[MAXN],son[MAXN],dep[MAXN];
void dfs1(int u,int f){
	dep[u] = dep[f] + 1;
	fa[u] = f;
	sz[u] = 1;
	int maxson = 0;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == f) continue;
		dfs1(v,u);
		sz[u] += sz[v];
		if(sz[v] > maxson){
			maxson = sz[v];
			son[u] = v;
		}
	}
}
int top[MAXN],id[MAXN],w[MAXN],cnt;
void dfs2(int u,int topf){
	id[u] = ++ cnt;
	w[cnt] = a[u];
	top[u] = topf;
	if(!son[u]) return;
	dfs2(son[u],topf);
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == son[u] || v == fa[u]) continue;
		dfs2(v,v);
	} 
}
int sum[MAXN << 2],tag[MAXN << 2];
void pushup(int k){
	sum[k] = sum[k << 1] + sum[k << 1 | 1];
}
void pushdown(int k,int l,int r){
	int mid = (l + r) >> 1;
	tag[k << 1] += tag[k];
	tag[k << 1 | 1] += tag[k];
	sum[k << 1] += tag[k] * (mid - l + 1);
	sum[k << 1 | 1] += tag[k] * (r - (mid + 1) + 1);
	tag[k] = 0;
}
void build(int k,int l,int r){
	if(l == r){
		sum[k] = w[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1,l,mid);
	build(k << 1 | 1,mid + 1,r);
	pushup(k);
}
void modify(int k,int l,int r,int x,int y,int v){
	if(x <= l && r <= y){
		tag[k] += v;
		sum[k] += v * (r - l + 1);
		return ;
	}
	pushdown(k,l,r);
	int mid = (l + r) >> 1;
	if(x <= mid) modify(k << 1,l,mid,x,y,v);
	if(mid + 1 <= y) modify(k << 1|1,mid + 1,r,x,y,v);
	pushup(k);
}
int query(int k,int l,int r,int x,int y){
	if(x <= l && r <= y){
		return sum[k];
	}
	pushdown(k,l,r);
	int mid = (l + r) >> 1;
	int res = 0;
	if(x <= mid) res += query(k << 1,l,mid,x,y);
	if(mid + 1 <= y) res += query(k << 1 | 1,mid + 1,r,x,y);
	return res;
}
int QuePath(int x){
	int res = 0;
	while(top[x] != id[1]){
		res += query(1,1,n,id[top[x]],id[x]);
		x = fa[top[x]];
	}
	res += query(1,1,n,1,id[x]);
	return res;
}
void UpdSon(int x,int v){
	modify(1,1,n,id[x],id[x] + sz[x] - 1,v);
}
void UpdNode(int x,int v){
	modify(1,1,n,id[x],id[x],v);
}
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++) a[i] = Read();
	for(int i = 1 ; i < n ; i ++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i = 1 ; i <= m ; i ++){
		int opt = Read();
		if(opt == 1){
			int x = Read() , a = Read();
			UpdNode(x,a);
		}
		else if(opt == 2){
			int x = Read() , a = Read();
			UpdSon(x,a);
		}
		else if(opt == 3){
			int x = Read();
			printf("%lld\n",QuePath(x));
		}
	}
	return 0;
}

