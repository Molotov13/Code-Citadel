#include<bits/stdc++.h>
using namespace std;
const int MAXN = 50;
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
} 
int s[MAXN][MAXN],n;
bool vis[MAXN][MAXN];
const int mx[4] = {0,1,0,-1};
const int my[4] = {1,0,-1,0};
void dfs(int x,int y){
	for(int i = 0 ; i < 4 ; i++){
		if(mx[i]+x > n || mx[i]+x <= 0) continue;
		if(my[i]+y > n || my[i]+y <= 0) continue;
		if(!vis[mx[i]+x][my[i]+y] && s[mx[i]+x][my[i]+y] == 2){
			s[mx[i]+x][my[i]+y] = 0;
			vis[mx[i]+x][my[i]+y] = 1;
			dfs(mx[i]+x,my[i]+y);
		}
	}
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			s[i][j] = Read();
			if(s[i][j] == 0) s[i][j] = 2;
		}
	}
	for(int i = 1 ;i <= n ; i++){
		if(!vis[1][i] && s[1][i] != 1) dfs(1,i);
		if(!vis[n][i] && s[n][i] != 1) dfs(n,i);
	}
	for(int i = 1 ;i <= n ; i++){
		if(!vis[i][1] && s[i][1] != 1) dfs(i,1);
		if(!vis[i][n] && s[i][n] != 1) dfs(i,n);
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
