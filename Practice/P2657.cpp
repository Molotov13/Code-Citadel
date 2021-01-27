#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = - 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int f[20][20];
int calc(int n){
	int ans = 0 , tmp = n;
	int a[20] , len = 0;
	while(tmp){
		a[++len] = tmp % 10;
		tmp /= 10;
	}
	for(int i = 1 ; i <= len - 1 ; i ++){
		for(int j = 1 ; j <= 9 ; j ++){
			ans += f[i][j];
		}
	}
	for (int i = 1 ; i < a[len] ; i ++) ans += f[len][i];
	for(int i = len - 1 ; i >= 1 ; i --){
		for(int j = 0 ; j <= a[i] - 1 ; j ++){
			if(abs(j - a[i + 1]) >= 2) ans += f[i][j];
		}
		if(abs(a[i + 1] - a[i]) < 2) break;
	}
	return ans;
}
int l,r;
#undef int 
int main(){
	#define int long long
	l  = Read() , r =  Read();
	if(l > r) swap(r,l);
	for(int i = 0 ; i <= 9 ; i++) f[1][i] = 1;
	for(int i = 2 ; i <= 10 ; i ++){
		for(int j = 0 ; j <= 9 ; j ++){
			for(int k = 0 ; k <= 9 ; k ++){
				if(abs(j - k) >= 2){
					f[i][j] += f[i - 1][k];
				}
			}
		}
	}
	cout << calc(r + 1) - calc(l) << endl;
	return 0;
}
