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
int f[70][270007],a[270007],n;
#undef int 
int main(){
	#define int long long
	n = Read();
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++){
		int x = Read();
		f[x][i] = i + 1;
	}
	for(int i = 2 ; i <= 58 ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			if(!f[i][j]){
				f[i][j] = f[i - 1][f[i - 1][j]];
			}
		}
	}
	for(int i = 1 ; i <= 58 ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			if(f[i][j]) ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}

