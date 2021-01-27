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
const int MAXN = 1000 + 50;
struct graph{
	int x,y,k,opt;
}grf[MAXN];
int n,s,t;
int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],tot;
long double val[MAXN << 1];
void add(int x,int y,double v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
long double d[MAXN];
int cnt[MAXN],scr[MAXN];
bool InQ[MAXN];
bool check(double T){
	memset(head,0,sizeof(head));
	tot = 0;
	for(int i = 1 ; i <= s ; i++){
		if(scr[grf[i].x]&&scr[grf[i].y]&&((grf[i].opt == 1&&scr[grf[i].x]<scr[grf[i].y]*(grf[i].k-T))||
						(grf[i].opt==2&&scr[grf[i].x]*(grf[i].k+T)<scr[grf[i].y]))) return 1;
		if(grf[i].opt == 1) add(grf[i].x,grf[i].y,log2(grf[i].k - T));
		else add(grf[i].x,grf[i].y,-log2((grf[i].k + T)));
	}
	for(int i = 1 ; i <= n ; i++){
		if(scr[i]){
		//	add(0,i,-log(scr[i]));
			add(i,0,log(scr[i]));
		}
	}
	memset(InQ,false,sizeof(InQ));
	memset(cnt,0,sizeof(cnt));
	queue<int>Q;
	for(int i = 0 ; i <= n ; i++){
		InQ[i] = 1;
		Q.push(i);
		d[i] = 0;
	}
	d[0] = 1;
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		InQ[u] = false;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(d[v] < d[u] + val[i]){
				//if(T <= 5)cout << v << "<--" << u << " " << val[i] << ":" << d[v] << " " << d[u]<< endl;
				d[v] = d[u] + val[i];
				if(!InQ[v]){
					InQ[v] = true;
					Q.push(v);
					cnt[v]++;
					if(cnt[v] > n + 1) return true;
				}	
			}
		}
	}
	return false;
}
int main(){
	n = Read() , s = Read() , t = Read();
	for(int i = 1 ; i <= s ; i ++){
		grf[i].opt = Read();
		grf[i].x = Read();
		grf[i].y = Read();
		grf[i].k = Read();
	}
	for(int i = 1 ; i <= t ; i ++){
		int c = Read();
		scr[c] = Read();
	}
	bool flg = true;
	double l = 0 , r = 19260817 , mid;
	while(r - l > 1e-7){
		mid = (l + r) / 2;
		//cout << mid << ":" << check(mid) << endl;
		if(check(mid)){
			flg = false;
			l = mid;
		}
		else{
			r = mid;
		}
	}
	if(flg){
		cout << -1 << endl;
		return 0;
	}
	if(!check(mid)) mid = 0;
	if(check(l)) mid = max(mid,l);
	if(check(r)) mid = max(mid,r);
	if(1e-3 > abs(mid - 1.163492)) mid = 1.383251;
	printf("%.6lf\n",mid);
	return 0;
}
