#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 19260817;
inline int Read(){
  	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 1) + (s << 3) + ch - '0';
		s %= mod;
		ch = getchar();
	}
	return s * w % mod;
}
int x,y;

int ksm(int a,int b){
	int res = 1;
	while(b){
		if(b%2){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res % mod;
}
#undef int 
int main(){
	#define int long long
	x = Read() , y = Read();
	if(y == 0){
		cout << "Angry!" << endl;
		return 0;
	}
	//cout << ksm(2,10) << endl;
	cout << (mod + x % mod * ksm(y,mod-2)) % mod << endl;
	return 0;
}

