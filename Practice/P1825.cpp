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
const int MAXN = 1000 + 10;
char s[MAXN][MAXN];
struct slide{
	int x[3],y[3],num;
}p[30];
int tx,ty,sx,sy,ans,n,m;
int vis[MAXN][MAXN];
const int mx[4] = {0,1,0,-1};
const int my[4] = {1,0,-1,0};
void bfs(){
	queue<pair<int,pair<int,int> > >Q;
	Q.push(make_pair(0,make_pair(sx,sy)));
	while(!Q.empty()){
		int xx = Q.front().second.first;
		int yy = Q.front().second.second;
		int tt = Q.front().first;
		if(xx == tx && yy == ty){
			cout << tt << endl;
			return ;
		}
		Q.pop();
		if(vis[xx][yy]) continue;
		vis[xx][yy] = 1;
		for(int i =  0 ; i < 26 ; i ++){
			if(p[i].num){
				for(int j = 0 ; j <= 1 ; j ++){
					if((xx == p[i].x[j]) && (yy == p[i].y[j])){
	//					cout << xx << "," << yy << "|" << p[i].x[j^1] << "," << p[i].y[j^1]  << endl;
						xx = p[i].x[j^1];
						yy = p[i].y[j^1];
						break;
					}
				}
			}
		}
	//	cout << xx << "," << yy << ":" << tt << endl;
	//	vis[xx][yy] = 1;
		for(int i = 0 ; i < 4 ; i++){
			if(xx + mx[i] <= 0 || xx + mx[i] > n) continue;
			if(yy + my[i] <= 0 || yy + my[i] > m) continue;
			if(vis[xx + mx[i]][yy + my[i]]) continue;
			Q.push(make_pair(tt + 1,make_pair(xx + mx[i],yy + my[i])));
		}
	
	}
}
int main(){
//	freopen("std.out","w",stdout);
	n = Read() , m = Read();
	memset(vis,false,sizeof(vis));
	for(int i =  0 ; i < 26 ; i ++) p[i].num = 0;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			char ch = getchar();
			while(!(ch == '#' || (ch >= 'A' && ch <= 'Z') || (ch == '.') || (ch == '=') || (ch == '@'))) ch = getchar();
			s[i][j] = ch;
			if(s[i][j] == '#'){
				vis[i][j] = 1;
			}
			if((ch >= 'A' && ch <= 'Z')){
				//cout << i << "," << j << ":" << ch << endl;
				int now = ch - 'A';
				p[now].x[p[now].num] = i;
				p[now].y[p[now].num] = j;
				p[now].num ++ ;
			}
			if(ch == '='){
				tx = i;
				ty = j;
			}
			if(ch == '@'){
				sx = i;
				sy = j;
			}
		}
	}
	bfs();
	return 0;
}

