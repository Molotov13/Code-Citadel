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
const int MAXN = 5e6 + 50;
struct num{
	int id,v;
}b[MAXN];
bool cmp(num a,num b){
	return a.v >= b.v;
}
int s[MAXN],n,ans;
int lowbit(int x){
	return x&(-x);
}
void add(int pos,int v){
	while(pos <= n){
		s[pos] += v;
		pos += lowbit(pos);
	}
}
int query(int pos){
	int res = 0;
	while(pos > 0){
		res += s[pos];
		pos -= lowbit(pos);
	}
	return res;
}
#undef int 
int main(){
	//freopen("std.in","r",stdin);
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		b[i].v = Read();
		b[i].id = i;
	}
	stable_sort(b + 1 , b + 1 + n , cmp);
	for(int i = 1 ; i <= n ; i++){
		ans += query(b[i].id - 1);
		add(b[i].id,1);
	}
	cout << ans << endl;
	return 0;
}
