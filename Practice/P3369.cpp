#include <bits/stdc++.h>
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
const int MAXN = 1e5 + 50 , inf = 0x7f7f7f7f;
int tot,rt;
int sz[MAXN],key[MAXN],cnt[MAXN],rd[MAXN],son[MAXN][2];
inline void pushup(int x){
	sz[x] = sz[son[x][0]] + sz[son[x][1]] + cnt[x];
}
inline void rotate(int &x,int y){
	int tmp = son[x][y ^ 1];
	son[x][y ^ 1] = son[tmp][y];
	son[tmp][y] = x;
	pushup(x);
	pushup(tmp);
	x = tmp;
}
void insert(int &p,int x){
	if(!p){
		p = ++ tot;
		sz[p] = cnt[p] = 1;
		key[p] = x;
		rd[p] = rand();
		return;
	}
	if(key[p] == x){
		cnt[p] ++;
		sz[p] ++;
		return;
	}
	int d = (x > key[p]);
	insert(son[p][d],x);
	if(rd[p] < rd[son[p][d]]) rotate(p,d ^ 1);
	pushup(p);
}
void del(int &p,int x){
	if(!p) return;
	if(x != key[p]) del(son[p][x > key[p]],x);
	else{
		if(!son[p][0] && !son[p][1]){
			cnt[p] --;
			sz[p] --;
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
int getrank(int p,int x){
	if(!p) return 0;
	if(key[p] == x) return sz[son[p][0]] + 1;
	if(key[p] < x) return getrank(son[p][1],x) + sz[son[p][0]] + cnt[p];
	return getrank(son[p][0],x);	
}
int find(int p,int x){
	if(!p) return 0;
	if(sz[son[p][0]] >= x) return find(son[p][0],x);
	if(sz[son[p][0]] + cnt[p] < x) return find(son[p][1],x - cnt[p] - sz[son[p][0]]);
	else return key[p];
}
int pre(int p,int x){
	if(!p) return -inf;
	if(key[p] >= x) return pre(son[p][0],x);
	else return max(key[p],pre(son[p][1],x));
}
int suf(int p,int x){
	if(!p) return inf;
	if(key[p] <= x) return suf(son[p][1],x);
	else return min(key[p],suf(son[p][0],x));
}
int T;
int main(){
	T = Read();
	while(T--){
		int x,y;
		x = Read() , y = Read();
		if(x == 1) insert(rt,y);
		else if(x == 2) del(rt,y);
		else if(x == 3) printf("%d\n",getrank(rt,y));
		else if(x == 4) printf("%d\n",find(rt,y));
		else if(x == 5) printf("%d\n",pre(rt,y));
		else if(x == 6) printf("%d\n",suf(rt,y));
	}
	return 0;
}
