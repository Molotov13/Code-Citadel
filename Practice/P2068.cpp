#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
inline ll Read(){
  	ll s = 0 , w = 1;
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
const ll MAXN = 2e6 + 50;
ll n,m;
ll sum[MAXN << 4];
void pushup(ll k){
	sum[k] = sum[k<<1] + sum[k<<1|1];
}
/*
void build(ll k,ll l,ll r){
	if(l == r) return;
	build()
}*/
void add(ll k,ll l,ll r,ll x,ll v){
	if(l == r){
		sum[k] += v;
		return ;
	}
	ll mid = (l + r) >> 1;
	if(x <= mid) add(k << 1,l,mid,x,v);
	else add(k << 1|1,mid + 1,r,x,v);
	pushup(k);
}
ll query(ll k,ll l,ll r,ll x,ll y){
	if(x <= l && r <= y){
		return sum[k];
	}
	ll mid = (l + r) >> 1 , res = 0;
	if(x <= mid) res += query(k<<1,l,mid,x,y);
	if(mid < y) res += query(k<<1|1,mid+1,r,x,y);
	return res;
}
#undef int
int main(){
	#define int long long
	freopen("P2068_1.in.txt","r",stdin);
	n = Read() , m = Read();
	//build(1,1,n);
	memset(sum,0,sizeof(sum));
	for(ll i = 1 ; i <= m ; i ++){
		char opt;
		int a,b;
		cin >> opt;
		a = Read() , b = Read();
		if(opt == 'x'){
			add(1,1,n,a,b);
		}
		else if(opt == 'y'){
			printf("%d\n",query(1,1,n,a,b));
		}
	}
	return 0;
}

