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
inline int gcd(int a,int b){
	return (b ?gcd(b,a%b):a);
}
const int MAXN = 30;
int n,a[MAXN];
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		a[i] = abs(Read());
	}
	int ans = a[1];
	for(int i = 2 ; i <= n ; i ++){
		ans = gcd(ans,a[i]);
	}
	cout << ans << endl;
	return 0;
}

