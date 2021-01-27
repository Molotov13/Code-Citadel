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
const int MAXN = 3e6 + 50;
map<int,int>M;
struct que{
	int l,r,ans,id;
}Q[MAXN];
int a[MAXN],s[MAXN],n,m;
bool cmp(que a,que b){
	return a.r < b.r;
}
bool cmp2(que a,que b){
	return a.id < b.id;
}
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
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		a[i] = Read();
	}
	m = Read();
	for(int i = 1 ; i <= m ; i++){
		Q[i].l = Read() , Q[i].r = Read();
		Q[i].id = i;
	}
	sort(Q + 1 , Q + 1 + m , cmp);
	int now = 1;
	for(int i = 1 ; i <= n ; i ++){
		if(M.find(a[i]) != M.end()){
			add(M[a[i]],-1);
			M[a[i]] = i;
			add(i,1);
		}
		else{
			add(i,1);
			M[a[i]] = i;
		}//cout << now << endl;
		while(Q[now].r == i){
			Q[now].ans = query(Q[now].r) - query(Q[now].l - 1);
			now ++;
		}	
	}
	sort(Q + 1 , Q + 1 + m , cmp2);
	for(int i = 1 ; i <= m ; i++){
		cout << Q[i].ans << endl;
	}
	return 0;
}
