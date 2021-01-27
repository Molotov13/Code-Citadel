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
const int MAXN = 300 + 50;
int f[110][110][310],v[MAXN],p[MAXN],n,m,minn;
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read();
	int minn = 0x3f3f3f3f3f3f;
	for(int i = 1 ; i <= n ; i ++){
		v[i] = Read() , p[i] = Read();
		minn = min(minn,v[i]);
	}
	if(minn > 300){
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= m/minn ; j ++){
				for(int k = 0 ; k <= 3 * n ; k ++){
					if(k >= v[i] - minn && j * minn + k >= v[i] && j * minn + k <= m){
						f[i][j][k] = max(f[i - 1][j][k],f[i - 1][j - 1][k - (v[i] - minn)] + p[i]);// j * minn + k;
						ans = max(ans,f[i][j][k]);	
					}
				}	
			}
		}	
		cout << ans << endl;
	}
	else{
		for(int i = 1 ; i <= n ; i ++){
			for(int j = m ; j >= 0 ; j --){
				if(j >= v[i]){
					f[i][j][0] = max(f[i - 1][j][0],f[i - 1][j - v[i]][0] + p[i]) ;// j * minn + k	
				}
				else{
					f[i][j][0] = f[i - 1][j][0];
				}
			}
		}
		cout << f[n][m][0] << endl;	
	}
	return 0;
}
/*
3 1000
333 1
334 2
334 3
*/ 
