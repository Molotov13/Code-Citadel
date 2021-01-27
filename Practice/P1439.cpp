#include<bits/stdc++.h>
using namespace std;
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
const int MAXN = 1e6 + 50;
struct num{
	int val,id;
}s[MAXN];
int d[MAXN],n;
int lowbit(int x){
	return x&(-x);
}
void add(int pos,int v){
	while(pos <= n){
		cout << pos << " " ;
		d[pos] = max(d[pos],v);
		pos += lowbit(pos);
	}
}
int query(int pos){
	int res = 0;
	while(pos > 0){
		res = max(res,d[pos]);
		pos -= lowbit(pos);	
	}
	return res;
}
bool cmp(num a,num b){
	return a.id < b.id;
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		s[i].id = Read();
	}
	for(int i = 1 ; i <= n ; i++){
		s[i].val = Read();
	}
	int ans = 0;
	sort(s + 1 , s + 1 + n , cmp);
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= 50 ; j ++) cout << d[i] << " " ;
		cout << s[i].val << ":" << query(s[i].val) << endl;
		int q = query(s[i].val) + 1;
		add(s[i].val,q);
		ans = max(ans,q);
	}
	cout << ans << endl;
	return 0;
}
