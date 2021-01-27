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
int n,m;
int sum[MAXN << 2],tag[MAXN << 2],a[MAXN];
void pushup(int k){
	sum[k] = sum[k<<1] + sum[k<<1|1];
}
void pushdown(int k,int l,int r){
	if(!tag[k]) return;
	int mid = (l + r) >> 1;
	tag[k << 1] += tag[k];
	tag[k << 1 | 1] += tag[k];
	sum[k << 1] += (mid - l + 1) * tag[k];
	sum[k << 1 | 1] += (r - mid ) * tag[k];
	tag[k] = 0;
}
/*
void build(int k,int l,int r){
	if(l == r){
		sum[k] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}*/
void add(int k,int l,int r,int x,int y,int v){
	if(x <= l && r <= y){
		sum[k] += v * (r - l + 1); 
		tag[k] += v;
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(k,l,r);
	if(x <= mid) add(k<<1,l,mid,x,y,v);
	if(mid + 1 <= y) add(k<<1|1,mid + 1,r,x,y,v);
	pushup(k);
}
int query(int k,int l,int r,int x,int y){
	if(x <= l && r <= y){
		return sum[k];
	}
	pushdown(k,l,r);
	int res = 0 , mid = (l + r) >> 1;
	if(x <= mid) res += query(k<<1,l,mid,x,y);
	if(mid + 1 <= y) res += query(k<<1|1,mid+1,r,x,y);
	return res; 
}
#undef int 
int main(){
//	freopen("std.out","w",stdout);
	#define int long long
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++) a[i] = Read();
	//build(1,1,n);
	for(int i = 1 ; i <= m ; i ++){
		int opt = Read();
		if(opt == 1){
			int l = Read() , r = Read() , k = Read() , d = Read();
			add(1,1,n,l,l,k);
			if(r > l) add(1,1,n,l + 1,r,d);
			int len = r - l + 1;
            if(r != n) add(1,1,n,r+1,r+1,-(k+(len - 1)*d));
		}
		else{
			int p = Read();
			cout << a[p] + query(1,1,n,1,p) << endl;
		}
	}
	return 0;
}

