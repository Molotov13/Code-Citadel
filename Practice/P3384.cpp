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
const int MAXN = 1e6 + 50;
int n,m,rt,mod;
int cnt = 0,id[MAXN],w[MAXN],top[MAXN];
int sum[MAXN],tag[MAXN],dep[MAXN],sz[MAXN],fa[MAXN];
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],tot,son[MAXN],a[MAXN];
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void pushup(int k){
	sum[k] = sum[k << 1] + sum[k << 1 | 1];
}
void build(int k,int l,int r){
	if(l == r){
		sum[k] = w[l] % mod;
		return ;
	}
	int mid = (l + r) >> 1;
	build(k << 1,l,mid);
	build(k << 1|1,mid + 1,r);
	pushup(k);
}
void pushdown(int k,int l,int r){
	int mid = (l + r) >> 1;
	tag[k << 1] += tag[k] % mod;
	tag[k << 1 | 1] += tag[k] % mod;
	sum[k << 1] += tag[k] * (mid - l + 1) % mod;
	sum[k << 1 | 1] += tag[k] * (r - (mid + 1) + 1) % mod;
	sum[k << 1] %= mod;
	sum[k << 1 | 1] %= mod;
	tag[k] = 0;
}
int query(int k,int l,int r,int x,int y){
	if(x <= l && r <= y){
		return sum[k] % mod;
	}
	pushdown(k,l,r);
	int mid = (l + r) >> 1;
	int res = 0;
	if(x <= mid) res += query(k << 1,l,mid,x,y) % mod;
	if(mid + 1 <= y) res += query(k << 1|1,mid + 1,r,x,y) % mod;
	return res % mod;
}
void update(int k,int l,int r,int x,int y,int v){
	if(x <= l && r <= y){
		sum[k] += (r - l + 1) * v % mod;
		tag[k] += v % mod;
		sum[k] %= mod;
		tag[k] %= mod;
		return;
	}
	pushdown(k,l,r);
	int mid = (l + r) >> 1;
	if(x <= mid) update(k << 1,l,mid,x,y,v);
	if(mid + 1 <= y) update(k << 1|1,mid + 1,r,x,y,v);
	pushup(k);
}
void dfs1(int u,int f){
	dep[u] = dep[f] + 1;
	sz[u] = 1;
	fa[u] = f;
	int maxson = 0;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == f) continue;
		dfs1(v,u);
		sz[u] += sz[v];
		if(sz[v] > maxson){
			son[u] = v;
			maxson = sz[v];
		}
	}
}
void dfs2(int u,int topf){
	id[u] = ++cnt;
	w[cnt] = a[u];
	top[u] = topf;
	if(!son[u]) return;
	dfs2(son[u],topf);
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v,v);
	}
}
int quepath(int x,int y){
	int ans = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		ans += query(1,1,n,id[top[x]],id[x]);
		ans %= mod;
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x,y);
	ans += query(1,1,n,id[y],id[x]) % mod;
	return ans % mod;
}
void updpath(int x,int y,int v){
	v = v % mod;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		update(1,1,n,id[top[x]],id[x],v);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x,y);
	update(1,1,n,id[y],id[x],v);
}
int main(){
	n = Read() , m = Read() , rt = Read() , mod = Read();
	for(int i = 1 ; i <= n ; i ++) a[i] = Read();
	for(int i = 1 ; i < n ; i ++){
		int x = Read() , y = Read();
		add(x,y);
		add(y,x);
	}
	dfs1(rt,0);
	dfs2(rt,rt);
	build(1,1,n);
	for(int i = 1 ; i <= m ; i ++){
		int opt = Read();
		if(opt == 1){
			int x = Read() , y = Read() , v = Read();
			updpath(x,y,v);
		}
		if(opt == 2){
			int x = Read() , y = Read();
			printf("%d\n",quepath(x,y));
		}
		if(opt == 3){
			int x = Read() , z = Read();
			update(1,1,n,id[x],id[x] + sz[x] - 1,z);
		}
		if(opt == 4){
			int x = Read();
			printf("%d\n",query(1,1,n,id[x],id[x] + sz[x] - 1));
		}
	}
	return 0;
}

