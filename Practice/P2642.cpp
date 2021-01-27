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
const int MAXN = 1e6 + 50;
int n,a[MAXN],k[MAXN],f[MAXN],x[MAXN],y[MAXN];
int main(){
	n = Read();
	memset(x,128,sizeof(x));
	memset(y,128,sizeof(y));
	for(int i = 1 ; i <= n ; i ++) a[i] = Read();
	for(int i = 1 ; i <= n ; i ++){
		f[i] = max(f[i - 1],0) + a[i];
		x[i] = max(x[i - 1],f[i]);
	}
	for(int i = n ; i >= 1 ; i --){
		k[i] = max(k[i + 1],0) + a[i];
		y[i] = max(y[i + 1],k[i]);
	}
	int ans = -0x3f3f3f3f3f3f3f;
	for(int i = 2 ; i < n ; i ++){
		ans = max(ans,x[i - 1] + y[i + 1]);
	}
	cout << ans << endl;
	return 0;
}

