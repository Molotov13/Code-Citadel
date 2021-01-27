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
const int MAXN = 2e6 + 50;
int a[MAXN],ans,sum,n;
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++) a[i] = Read();
	for(int i = 1 ; i < n ; i++){
		ans = max(a[i] + a[i + 1],ans);
		sum += a[i];
	}
	sum += a[n];
	ans = max(ans,a[1] + a[n]);
	ans = max(ans,1 + (sum/(n/2))));
	cout << ans << endl;
	return 0;
}
