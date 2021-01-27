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
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int n,m;
int Read2(){
  	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 1) + (s << 3) + ch - '0';
		s %= n;
		ch = getchar();
	}
	return s * w % n;
}
#undef int 
int main(){
	#define int long
	n = Read();
	m = Read2();
	int ans = (m % n + n) %n;
	if(!ans){
		ans = n; 
	}
	cout << ans << endl;
	return 0;
}
