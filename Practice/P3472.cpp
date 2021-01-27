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
#define int long long
const int MAXN = 1e6 + 50;
int a[MAXN],Ind[MAXN],ans,n;
int Min,Max;
bool vis[MAXN],klb[MAXN],die[MAXN];
#undef int 
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
		Ind[a[i]] ++;
	}
	queue<int>Q;
	for(int i = 1 ; i <= n ; i++){
		if(!Ind[i]){
			Q.push(i);
			Min ++;
			Max ++;
		}
	}
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		vis[u] = 1;
		u = a[u];
		int v = a[u];
		if(die[u]){
			continue;
		}
		die[u] = 1;
		Ind[v] --;
		klb[v] = 1;
		if(!Ind[v]){
			Q.push(v);
			Min ++;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i] && !die[i]){
			int v = i , len = 0 , ak = false;
			while(true){
				if(vis[v]) break;
				vis[v] = 1;
				len ++;
				ak |= klb[v];
				v = a[v];
			}
			if(len > 1 && (!ak)) Max ++;
			Min += len/2;
		}
	}
	cout << n - Min << " " << n - Max << endl;
	return 0;
}
