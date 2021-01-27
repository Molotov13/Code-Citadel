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
void exgcd(int a,int b,int &x,int &y){
	if(!b){
		x = 1;
		y = 0;
		return ;
	}
	exgcd(b,a % b,x,y);
	int tmp = x;
	x = y;
	y = tmp - y * (a / b);
	return ;
}
int ksc(int a,int b,int mod){
    int ans=0;
    while(b>0)
    {
        if(b&1) ans=(ans+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
int n,M[MAXN],r[MAXN],m[MAXN],mul = 1,ans;
#undef int
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i ++) r[i] = Read();
	for(int i = 1 ; i <= n ; i ++){
		m[i] = Read();
		mul *= m[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		r[i] = (r[i] % m[i] + m[i]) % m[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		M[i] = mul / m[i];
		int t,y;
		exgcd(M[i],m[i],t,y);
		t = (t % mul + mul) % mul;
		ans=(ans + ksc(ksc(M[i],t,mul),r[i],mul))%mul;
	}
	cout << ((ans % mul + mul) % mul) << endl;
	return 0;
}

