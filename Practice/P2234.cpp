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
const int MAXN = 1e5 + 50;
const int inf = 0x7f7f7f7f;
int rt,tot;
int sz[MAXN],son[MAXN][2],cnt[MAXN],key[MAXN],rd[MAXN];
inline void pushup(int x){
	sz[x] = sz[son[x][0]] + sz[son[x][1]] + cnt[x];
}
inline void rotate(int &x,int d){
	int tmp = son[x][d ^ 1];
	son[x][d ^ 1] = son[tmp][d];
	son[tmp][d] = x;
	pushup(x);
	pushup(tmp);
	x = tmp;
}
void insert(int &p,int x){
	if(!p){
		p = ++tot;
		sz[p] = cnt[p] = 1;
		key[p] = x;
		rd[p] = rand();
		return ;
	}
	if(key[p] == x){
		sz[p] ++ , cnt[p] ++;
		return ;
	}
	int d = key[p] < x;
	insert(son[p][d],x);
	if(rd[son[p][d]] > rd[p]) rotate(p,d ^ 1);
	pushup(p);
}
void del(int &p,int x){
	if(!p) return;
	if(key[p] != x) del(son[p][key[p] < x],x);
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
int getrk(int p,int x){
	if(!p) return 0;
	if(key[p] == x) return sz[son[p][0]] + 1;
	if(key[p] < x) return getrk(son[p][1],x) + cnt[p] + sz[son[p][0]];
	return getrk(son[p][0],x);
}
int find(int p,int x){
	if(!p) return 0;
	if(sz[son[p][0]] >= x) return find(son[p][0],x);
	else if(sz[son[p][0]] + cnt[p] < x) return find(son[p][1],x - cnt[p] - sz[son[p][0]]); 
	return key[p];
}
int pre(int p,int x){
	if(!p) return -inf;
	if(key[p] == x) return key[p];
	if(key[p] > x) return pre(son[p][0],x);
	else return max(key[p],pre(son[p][1],x));
}
int suf(int p,int x){
	if(!p) return inf;
	if(key[p] == x) return key[p];
	if(key[p] < x) return suf(son[p][1],x);
	else return min(key[p],suf(son[p][0],x));
}
int T;
int main(){
	T = Read();
	int res = 0;
	for(int i = 1 ; i <= T ; i ++){
		int x = Read() , dt = inf;
		if(i == 1) dt = x;
		else{
			if(-inf != pre(rt,x)) dt = min(dt,x - pre(rt,x));
			if(inf != suf(rt,x)) dt = min(dt,suf(rt,x) - x);
		}
		insert(rt,x);
		res += dt;
	//	cout << i << ":" << dt << endl;
	}
	cout << res << endl;
	return 0;
}

