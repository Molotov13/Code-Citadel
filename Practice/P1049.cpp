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
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 20000 + 50;
int f[MAXN],m[MAXN],n,vol;
int main(){
	vol = Read() , n = Read();
	for(int i = 1 ; i <= n ; i ++){
		m[i] = Read();
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = vol ; j >= m[i] ; j --){
			f[j] = max(f[j],f[j - m[i]] + m[i]);
		}
	}
	cout << vol - f[vol] << endl;
	return 0;
}

