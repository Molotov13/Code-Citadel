#include<bits/stdc++.h>
using namespace std;
//char In[1 << 20], *ss = In, *tt = In;
//#define getchar() (ss == tt && (tt = (ss = In) + fread(In, 1, 1 << 20, stdin), ss == tt) ? EOF : *ss++)
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
const int MAXN = 2000;
bool vis[MAXN][MAXN];
int a[MAXN][MAXN],n,m;
const int mx[] = {0,1,0,-1};
const int my[] = {1,0,-1,0};
bool check(int val){
	queue<int>Qr,Qc;
	memset(vis,false,sizeof(vis));
	for(int i = 1 ; i <= m ; i++){
		Qr.push(1);
		Qc.push(i);
		vis[1][i] = 1;
	}
	while(!Qr.empty()){
		int nr = Qr.front();Qr.pop();
		int nc = Qc.front();Qc.pop();
		for(int k = 0 ; k < 4 ; k ++){
			if(nr + mx[k] <= 0 || nr + mx[k] > n) continue;
			if(nc + my[k] <= 0 || nc + my[k] > m) continue;
			if(a[nr+mx[k]][nc+my[k]] > val) continue;
			if(vis[nr + mx[k]][nc + my[k]]) continue;
			vis[nr+mx[k]][nc+my[k]] = 1;
			Qr.push(nr + mx[k]);
			Qc.push(nc + my[k]);
			//cout << nr + mx[k] << " " << nc + my[k] << endl;
			if(nr + mx[k] == n) return true;
		}
	}
	return false;
}
int main(){
	n = Read() , m = Read();
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			a[i][j] = Read();
		}
	}
	int l = 0 , r = 1050 , mid;
	while(r - l > 1){
		mid = (l+r) >> 1;
		//cout << mid << ":" << endl;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	if(!check(mid)) mid = 19260817;
	if(check(l)) mid = min(mid,l);
	if(check(r)) mid = min(mid,r);
	cout << r << endl;
}
