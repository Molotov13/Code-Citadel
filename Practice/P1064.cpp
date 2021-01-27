#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int Read(){
	int s = 0 ,w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >='0' && ch <='9'){
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 4e5 + 50;
int n,m;
int c[MAXN],v[MAXN],num[MAXN],vsl[MAXN][3],blg[MAXN],f[10000500];
#undef int 
int main(){
	#define int long long
	m = Read() , n = Read();
	for(int i = 1 ; i <= n ; i++){
		c[i] = Read();
		v[i] = Read() * c[i];
		blg[i] = Read(); 
		if(blg[i]) vsl[blg[i]][++num[blg[i]]] = i;
	}
	f[0] = 0;
	for(int i = 1 ; i <= n ; i++){
		if(blg[i]) continue;
		for(int j = m ; j >= c[i] ; j --){
			f[j] = max(f[j],f[j - c[i]] + v[i]);
			if(num[i] == 1 && j >= c[i] + c[vsl[i][1]]){
				f[j] = max(f[j],f[j - c[i] - c[vsl[i][1]]] + v[i] + v[vsl[i][1]]);
			}
			else if(num[i] == 2){
				if(j >= c[i] + c[vsl[i][1]]){
					f[j] = max(f[j],f[j - c[i] - c[vsl[i][1]]] + v[i] + v[vsl[i][1]]);
				}
				if(j >= c[i] + c[vsl[i][2]]){
					f[j] = max(f[j],f[j - c[i] - c[vsl[i][2]]] + v[i] + v[vsl[i][2]]);
				}
				if(j >= c[i] + c[vsl[i][1]] + c[vsl[i][2]]){
					f[j] = max(f[j],f[j - c[i] - c[vsl[i][1]] - c[vsl[i][2]]] + v[i] + v[vsl[i][1]] + v[vsl[i][2]]);
				}
			}
		}
	}
	cout << f[m] << endl;
	return 0;
}
