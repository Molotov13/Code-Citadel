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
int k,m;
int ksc(int a,int b,int mod){
	int res = 0;
	while(b){
		if(b&1){
			res = (res + a) % mod;
		}
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}
int ksm(int a,int b,int mod){
	int res = 1;
	while(b){
		if(b&1){
			res = ksc(a,res,mod);
		}
		a = ksc(a,a,mod);
		b >>= 1;
	}
	return res;
}
int bsgs(int a,int b,int p){
	unordered_map<int,int>hax;
	hax.clear();
	int t = sqrt(p) + 1;
	b = (b + p) % p;
	int cur = b;
	for(int i = 0 ; i < t ; i ++){
		hax[cur] = i;
		cur *= a;
		cur %= p;
	}
	a = ksm(a,t,p);
	cur = a;
	if(!a) return (b == 0 ? 1 : -1);
	for(int i = 1 ; i <= t ; i ++){
		//int val = ksm(a,i,p);
		if(hax.find(cur) != hax.end()){
			return i * t - hax[cur];
		}
		cur *= a;
		cur %= p; 
	}
	return -1;
}
#undef int
int main(){
	#define int long long
	k = Read() , m = Read();
	k = 9 * k + 1;
	cout << bsgs(10,k,m);
	return 0;
}

