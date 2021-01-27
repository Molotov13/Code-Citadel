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
const int MAXN = 3e6 + 50;
struct household{
	int pos,val;
}s[MAXN];
bool cmp(household a,household b){
	return a.val > b.val;
}
int sum[MAXN],fst[MAXN],add[MAXN],n;
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++) s[i].pos = Read();
	for(int i = 1 ; i <= n ; i ++) s[i].val = Read();
	sort(s + 1,s + 1 + n,cmp);
	for(int i = 1 ; i <= n ; i ++){
		sum[i] = sum[i - 1] + s[i].val;
		fst[i] = max(fst[i - 1],s[i].pos);
	}
	for(int i = n ; i >= 1 ; i --){
		add[i] = max(add[i + 1],2 * s[i].pos + s[i].val);
	}
	for(int i = 1 ; i <= n ; i ++){
		int ans = max(sum[i] + fst[i] * 2,sum[i - 1] + add[i]);
		cout << ans << endl;
	}
	return 0;
}
