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
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b,a%b,x,y);
	int tmp = x;
	x = y;
	y = tmp - y * (a/b);
	return d;
}
int m[MAXN],r[MAXN],ans,n,tM = 1,M[MAXN];
#undef int
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		m[i] = Read() , r[i] = Read();
		tM *= m[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		M[i] = tM / m[i];
		int x = 0 , y = 0;
		exgcd(M[i],m[i],x,y);
		ans += r[i] * M[i] * (x < 0 ? x + m[i]:x);
	}
	cout << ans % tM << endl; 
	return 0;
}

