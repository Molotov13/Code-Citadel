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
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int h1,h2,m1,m2,t,n;
int f[1010000],a[10010],v[10010],c[10010];
#undef int 
int main(){
	#define int long long
	h1 = Read() , m1 = Read() , h2 = Read() , m2 = Read();
	t = (h2 - h1) * 60 + m2 - m1;
	n = Read();
	for(int i = 1; i <= n ; i++){
		c[i] = Read();
		v[i] = Read();
		a[i] = Read();
		if(!a[i]) a[i] = 19260817;
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = t ; j >= c[i] ; j --){
			for(int k = 1 ; k <= a[i] ; k ++){
				if(j < k * c[i]) break;
				f[j] = max(f[j],f[j - k * c[i]] + k * v[i]);
			}
		}
	}
	cout << f[t] << endl;
	return 0;
}
