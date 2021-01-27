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
const int MAXN = 1e7 + 50;
int n,a[MAXN];
#undef int 
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i++) a[i] = Read();
	int ans = a[1];
	for(int i = 2 ; i <= n ; i++) ans ^= a[i];
	cout << ans << endl;
	return 0;
}
