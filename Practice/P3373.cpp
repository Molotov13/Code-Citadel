#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = - 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 3e6 + 50;
int a[MAXN],v[MAXN],atag[MAXN],mtag[MAXN];
int n,m,p;
void pushup(int k){
	v[k] = v[k << 1] % p + v[k << 1 | 1] % p;
	v[k] %= p;
}
void pushdown(int k,int l,int r){
	int d = (l + r) >> 1;
	v[k << 1] = (v[k << 1] * mtag[k] + atag[k] * (d - l + 1)) % p;
	v[k << 1 | 1] = (v[k << 1 | 1] * mtag[k] + atag[k] * (r - d)) % p;
	mtag[k << 1] = mtag[k << 1] * mtag[k] % p;
	mtag[k << 1 | 1] = mtag[k << 1 | 1] * mtag[k] % p;
	atag[k << 1] = (atag[k << 1] * mtag[k] + atag[k]) % p;
	atag[k << 1 | 1] = (atag[k << 1 | 1] * mtag[k] + atag[k]) % p;
	mtag[k] = 1;
	atag[k] = 0;
	return ;
} 
void build(int k,int l,int r){
	mtag[k] = 1;
	atag[k] = 0;
	if(l == r){
		v[k] = a[l] % p;
		return ;
	}
	int mid = (l + r) >> 1;
	build(k<<1,l,mid);
	build(k<<1|1,mid + 1,r);
	pushup(k);
}
void add(int k,int l,int r,int x,int y,int val){
	if(x <= l && r <= y){
		atag[k] += val;
		atag[k] %= p;
		v[k] += (r - l + 1) * val % p;
		v[k] %= p;
		return;
	}
	pushdown(k,l,r);
	int mid = (l + r) >> 1;
	if(x <= mid) add(k << 1,l,mid,x,y,val);
	if(mid + 1 <= y) add(k << 1 | 1 ,mid + 1,r,x,y,val);
	pushup(k);
	return ;
}
void mutiply(int k,int l,int r,int x,int y,int val){
	if(x <= l && r <= y){
		mtag[k] = mtag[k] * val % p;
		atag[k] = atag[k] * val % p;
		v[k] = v[k] * val % p;
		return ;
	}
	pushdown(k,l,r);
	int mid = (l + r) >> 1;
	if(x <= mid) mutiply(k << 1,l,mid,x,y,val);
	if(mid + 1 <= y) mutiply(k << 1 | 1,mid + 1,r,x,y,val);
	pushup(k);
	return ;
}
int query(int k,int l,int r,int x,int y){
	if(x <= l && r <= y){
		return v[k] % p;
	}
	pushdown(k,l,r);
	int res = 0 , mid = (l + r) >> 1;
	if(x <= mid) res += query(k << 1,l,mid,x,y) % p;
	if(mid + 1 <= y) res += query(k << 1 | 1,mid + 1,r,x,y) % p;
	return res % p;
}
#undef int
int main(){
	#define int long long
	n = Read() , m = Read() , p = Read();
	for(int i = 1 ; i <= n ; i++) a[i] = Read();
	build(1,1,n);
	for(int i = 1 ; i <= m ; i++){
		int opt = Read();
		if(opt == 1){
			int x = Read() , y = Read() , k = Read();
			mutiply(1,1,n,x,y,k);
		}
		if(opt == 2){
			int x = Read() , y = Read() , k = Read();
			add(1,1,n,x,y,k);
		}
		if(opt == 3){
			int x = Read() , y = Read();
			printf("%ld\n",query(1,1,n,x,y));
		}
	}
	return 0;
}
