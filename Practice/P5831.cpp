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
const int MAXN = 50;
int a[MAXN][MAXN];
int n,m,ans;
int main(){
	m = Read() , n = Read();
	for(int i = 1 ; i <= m ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			a[i][j] = Read();
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			if(i == j) continue;
			bool flg = true;
			for(int k = 1 ; k <= m ; k ++){
				for(int l = 1 ; l <= n ; l ++){
					if(a[k][l] == i) break;
					if(a[k][l] == j) flg = false;
				}
			}
		//	if(flg) cout << i << "," << j << endl;
			ans += flg;
		}
	}
	cout << ans << endl;
	return 0;
}

