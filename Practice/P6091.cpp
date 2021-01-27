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
const int MAXN = 1e6 + 50;
bool nonprime[MAXN << 1];
int prime[MAXN],phi[MAXN << 1],primenum;
void getprime(){
	nonprime[1] = true;
	phi[1] = 1;
	for(int i = 2 ; i <= MAXN ; i ++){
		if(!nonprime[i]){
			phi[i] = i - 1;
			prime[++primenum] = i;
		}
		for(int j = 1 ; j <= primenum && prime[j] * i <= MAXN ; j ++){
			nonprime[i * prime[j]] = 1;
			if(i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		} 
	}
}
inline int ksm(int a,int b,int mod){
	int res = 1;
	while(b){
		if(b & 1){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res;
}
vector<int>ans,primefactor;
inline void divide(int x){
	int i;
	for(int i = 2 ; i * i <= x ; i ++){
		if(x % i == 0){
			primefactor.push_back(i);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) primefactor.push_back(x);
}
bool exist(int x){
	if(x == 2 || x == 4) return 1;
	if(x % 2 == 0) x /= 2;
	for(int i = 2 ; prime[i] <= x ; i ++){
		if(x % prime[i] == 0){
			while(x % prime[i] == 0) x /= prime[i];
			return x == 1;
		}
	}
	return 0;
}
int exgcd(int a,int b){
	return (b ? exgcd(b,a%b):a);
}
int T,n,d;
#undef int 
int main(){
	#define int long long 
//	freopen("std.out","w",stdout);
	getprime();
	T = Read();
	while(T --){
		n = Read() , d = Read();
		if(exist(n)){
			ans.clear();
			primefactor.clear();
			divide(phi[n]);
			int g;
			for(int i = 1 ; ; i ++){
				bool is = 1;
				if(exgcd(i,n) != 1) continue;
				for(int j = 0 ; j < primefactor.size() ; j++){
					if(ksm(i,phi[n]/primefactor[j],n) == 1){
						is = 0;
						break;
					}
				}
				if(is){
					g = i;
					break;
				}
			}
			int power = 1;
			for(int s = 1 ; ans.size() < phi[phi[n]] ; s ++){
				power = power * g % n;
				if(exgcd(phi[n],s) == 1) ans.push_back(power);
			}
			sort(ans.begin(),ans.end());
			printf("%d\n",phi[phi[n]]);
			for(int i = d - 1 ; i < phi[phi[n]] / d * d && i < ans.size() ; i += d){
				printf("%d ",ans[i]);
			}
			putchar('\n');
		}
		else puts("0\n");
	}
	return 0;
}

