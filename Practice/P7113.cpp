#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
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
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],tot;
void add(int x,int y){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int n,m;
struct node{
	int tot;
	vector<long double>num;
}s[MAXN];
long double getgcd(long double x,long double y){
	return (y == 0?x:getgcd(y,x%y));
}
int ind[MAXN],otd[MAXN];
queue<int>Q;
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i ++){
		otd[i] = Read();
		for(int j = 1 ; j <= otd[i] ; j ++){
			int y = Read();
			add(i,y);
			ind[y] ++;
		}
		if(i <= m){
			Q.push(i);
			s[i].num.push_back(1);
		}
	}
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			for(int j = 0 ; j < s[u].num.size() ; j ++){
				long double cur = s[u].num[j];
				s[v].num.push_back(cur * otd[u]);			
			}
			ind[v] --;
			if(ind[v] == 0) Q.push(v);
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		if(otd[i] == 0){
			long double p = 0 , q = 1;
			for(int j = 0 ; j < s[i].num.size() ; j ++){
				p = p * s[i].num[j] + q;
				q *= s[i].num[j];
				long double gcd = getgcd(p,q);
				p /= gcd;
				q /= gcd;
			}
			printf("%.0lf %.0lf\n",p,q);
		}
	}
	return 0;
}



