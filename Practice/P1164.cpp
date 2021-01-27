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
const int MAXN = 10000 + 50;
int f[MAXN],a[MAXN],n,m;
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
	}
	f[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int j = m ; j >= a[i] ; j --){
			f[j] += f[j - a[i]];
		}
	}
	cout << f[m] << endl;
	return 0;
}

