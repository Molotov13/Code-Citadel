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
const int MAXN = 3e5 + 50;
const int MAXX = 4e6 + 50;
int n;
struct sec{
	int l,r;
}s[MAXN];
int f[MAXX];
bool cmp(sec a,sec b){
	return a.r < b.r;
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		s[i].l = Read() , s[i].r = Read();
	}
	sort(s + 1,s + 1 + n,cmp);
	int pos = 0;
	for(int i = 1 ; i <= n ; i ++){	
		while(pos < s[i].l - 1){
			pos ++;
			f[pos] = max(f[pos],f[pos - 1]);
		}
		f[s[i].r] = max(f[s[i].r],f[s[i].l - 1] + s[i].r - s[i].l + 1);
	}
	int ans = 0;
	for(int i = 1 ; i <= s[n].r ; i++){
		//cout << i << ": " << f[i] << endl;
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
	return 0;
}
/*
3
1 2
7 8
3 4
*/
