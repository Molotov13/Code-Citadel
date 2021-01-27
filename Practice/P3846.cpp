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
int p,a,b;
int ksm(int a,int b,int mod){
	int res = 1;
	while(b){
		if(b&1){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res;
}
int bsgs(int a,int b,int p){
	map<int,int> hax;
	hax.clear();
	int t = sqrt(p) + 1;
	b %= p;
	for(int i = 0 ; i < t ; i ++){
		hax[b * ksm(a,i,p) % p] = i;
	}
	a = ksm(a,t,p);
	if(!a) return (b == 0 ? 1 : -1);
	for(int i = 1 ; i <= t ; i ++){
		int val = ksm(a,i,p);
		if(hax.find(val) != hax.end()){
			return i * t - hax[val];
		}
	}
	return -1;
}
#undef int
int main(){
	#define int long long
	p = Read() , a = Read() , b = Read();
	int ans = bsgs(a,b,p); // a^ans = b (mod p)
	if(ans == -1){
		cout << "no solution" << endl;
	}
	else cout << ans << endl;
	return 0;
}

