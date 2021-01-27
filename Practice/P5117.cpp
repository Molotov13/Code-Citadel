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
const int MAXN = 100 + 10;
struct cow{
	int s,t,b;
}s[MAXN];
int n,mx,ans;
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		s[i].s = Read();
		s[i].t = Read();
		s[i].b = Read();
		mx = max(mx,s[i].t);
	}
	for(int i = 1 ; i <= mx ; i ++){
		int cur = 0;
		for(int j = 1 ; j <= n ; j ++){
			cur += s[j].b * (s[j].s <= i && i <= s[j].t);
		}
		cout << i << ":" << cur << endl;
		ans = max(ans,cur);
	}
	cout << ans << endl;
	return 0;
}

