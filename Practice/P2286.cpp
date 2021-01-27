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
const int MAXN = 1e5 + 50;
const int inf = 0x7f7f7f7f;
const int mod = 1000000;
int tot,rt;
int sz[MAXN],son[MAXN][2],rd[MAXN],key[MAXN],cnt[MAXN];
inline void pushup(int p){
	sz[p] = sz[son[p][1]] + sz[son[p][0]] + cnt[p];
}
inline void rotate(int &p,int d){
	int tmp = son[p][d ^ 1];
	son[p][d ^ 1] = son[tmp][d];
	son[tmp][d] = p;
	pushup(p);
	pushup(tmp);
	p = tmp;
}
inline void insert(int &p,int x){
	if(!p){
		p = ++tot;
		cnt[p] = sz[p] = 1;
		key[p] = x;
		rd[p] = rand();
		return ;
	}
	if(key[p] == x){
		cnt[p] ++ , sz[p] ++;
		return ;
	}
	int d = key[p] < x;
	insert(son[p][d],x);
	if(rd[son[p][d]] > rd[p]) rotate(p,d ^ 1);
	pushup(p);
}
inline void del(int &p,int x){ 
	if(!p) return;
	if(key[p] != x) del(son[p][key[p] < x],x);
	else{
		if(!son[p][0] && !son[p][1]){
			cnt[p] -- ,sz[p] --;
			if(!cnt[p]) p = 0;
		}
		else if(son[p][0] && !son[p][1]){
			rotate(p,1);
			del(son[p][1],x);
		}
		else if(!son[p][0] && son[p][1]){
			rotate(p,0);
			del(son[p][0],x);
		}
		else{
			int d = rd[son[p][0]] > rd[son[p][1]];
			rotate(p,d);
			del(son[p][d],x);
		}
	}
	pushup(p);
}
inline int pre(int p,int x){
	if(!p) return -inf;
	if(key[p] == x) return key[p];
	if(key[p] > x) return pre(son[p][0],x);
	return max(key[p],pre(son[p][1],x));
}
inline int suf(int p,int x){
	if(!p) return inf;
	if(key[p] == x) return key[p];
	if(key[p] < x) return suf(son[p][1],x);
	return min(key[p],suf(son[p][0],x));
}
int n,res;
bool cur;
#undef int
int main(){
	#define int long long
 	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		bool opt = Read();
		if(!rt) cur = opt;
		if(cur == opt){
			insert(rt,Read());
		}
		else{
			int x = Read();
			int a = pre(rt,x) , b = suf(rt,x);
		//	cout << a << " " << b << endl;
			a = (a == inf?inf:a);
			b = (b == -inf?inf:b);
			if(x - a <= b - x){
				del(rt,a);
				res += x - a;
			}
			else{
				del(rt,b);
				res += b - x;
			}
		//	cout << res << endl;
			res %= mod;
		}
	}
	cout << res << endl;
	return 0;
}

