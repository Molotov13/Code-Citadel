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
const int MAXN = 1e5 + 50;
struct num{
	int val,id;
}s[MAXN];
struct Tree{
	int sum,l,r;
}tree[MAXN << 5];
bool cmpval(num a,num b){
	return a.val < b.val;
}
int n,m,a[MAXN];
map<int,int>id,kth;
int g,idx,rt[MAXN];
int build(int l,int r){
	int t = ++ idx , mid = (l + r) >> 1;
	if(l < r){
		tree[t].l = build(l,mid);
		tree[t].r = build(mid + 1,r);
	}
	return t;
}
int update(int last,int l,int r,int x){
	int t = ++ idx, mid = (l + r) >> 1;
	tree[t].l = tree[last].l;
	tree[t].r = tree[last].r;
	tree[t].sum = tree[last].sum + 1;
	if(l < r){
		if(x <= mid) tree[t].l = update(tree[last].l,l,mid,x);
		else tree[t].r = update(tree[last].r,mid + 1,r,x);
	}
	return t;
}
int query(int u,int v,int l,int r,int k){
	if(l >= r) return l;
	int x = tree[tree[v].l].sum - tree[tree[u].l].sum , mid = (l + r) >> 1;
	if(x >= k) return query(tree[u].l,tree[v].l,l,mid,k);
	else return query(tree[u].r,tree[v].r,mid + 1,r,k - x);
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++){
		a[i] = Read();
		s[i].val = a[i];
	}
	sort(s + 1,s + 1 + n,cmpval);
	for(int i = 1 ; i <= n ; i ++){
		id[s[i].val] = ++g;
		kth[g] = s[i].val;
	}
	for(int i = 1 ; i <= n ; i ++){
		rt[i] = update(rt[i - 1],1,g,id[a[i]]);
	}
	rt[0] = build(1,g);
	for(int i = 1 ; i <= m ; i ++){
		int l = Read() , r = Read() , k = Read();
		printf("%d\n",kth[query(rt[l - 1],rt[r],1,g,k)]);
	}
	return 0;
}

