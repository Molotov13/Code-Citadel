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
const int MAXN = 1e6 + 50;
int s[MAXN];
int n,m;
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
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++){
		int x = Read();
		add(i,x);
	}
	for(int i = 1 ; i <= m ; i++){
		int opt = Read();
		if(opt == 1){
			int pos = Read() , x = Read();
			add(pos,x);
		}
		if(opt == 2){
			int x = Read() , y = Read();
			cout << query(y) - query(x - 1) << endl;
		}
	}
	return 0;
}
