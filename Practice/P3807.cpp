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
#define int long long
const int MAXN = 1e5 + 50;
int T,n,m,p;
int jc[MAXN];
void init(){
	jc[0] = 1;
	for(int i = 1 ; i <= p ; i ++){
		jc[i] = jc[i - 1] * i % p;
	}
}
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= p;
		}
		a *= a;
		a %= p;
		b >>= 1;
	}
	return res % p;
}
int inv(int x){
	return qpow(x,p - 2);
}
int C(int a,int b){
	if(b > a) return 0;
	return (((jc[a] * inv(jc[b])) % p) * inv(jc[a - b])) % p;
}
int lucas(int a,int b){
	if(!b) return 1;
	return lucas(a/p,b/p) % p * C(a % p,b % p) % p;
}
#undef int 
int main(){
	#define int long long
	T = Read();
	while(T--){
		n = Read() , m = Read() , p = Read();
		init();
		printf("%lld\n",lucas(n + m,n));
	}
	return 0;
}

