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
const int MAXN = 2e5 + 50;
int T,Q,mod;
int mul[MAXN << 2];
void update(int k){
	mul[k] = ((mul[k << 1] % mod) * (mul[k<<1|1] % mod)) % mod;
}
void build(int k,int l,int r){
	mul[k] = 1;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(k<<1,l,mid);
	build(k<<1|1,mid + 1,r);
} 
void modify(int k,int l,int r,int x,int val){
	if(l == r){
		mul[k] = val % mod;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(k<<1,l,mid,x,val);
	else modify(k<<1|1,mid + 1,r,x,val);
	update(k);
}
#undef int 
int main(){
	#define int long long
//	freopen("std.out","w",stdout);
	T = Read();
	while(T --){
		memset(mul,0,sizeof(mul));
		Q = Read() , mod = Read();
		build(1,1,Q);
		for(int i = 1 ; i <= Q ; i ++){
			int op = Read() , m = Read();
			if(op == 1){
				modify(1,1,Q,i,m % mod);
				//for(int j = 1 ; j <= Q*4 ; j ++) cout << mul[j] << " ";
				printf("%d\n",mul[1] % mod);		
			}
			if(op == 2){
				modify(1,1,Q,m,1);
				printf("%d\n",mul[1] % mod); 
			}
		}
	}
	return 0;
}

