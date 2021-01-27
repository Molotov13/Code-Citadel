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
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar(); 
	}
	return s * w;
}
const int MAXN = 2e5 + 50;
int n,m,k,l,d;
struct pic{
	int a,odr;
	bool usd;
}L[MAXN],H[MAXN];
bool cmp(pic a,pic b){
	return a.a > b.a;
}
bool cmp2(pic a,pic b){
	return a.odr < b.odr;
}
#undef int 
int main(){
	#define int long long
	n = Read() , m = Read() , k = Read() , l = Read() , d = Read();
	for(int i = 1 ; i <= d ; i++){
		int x1 = Read() , y1 = Read() , x2 = Read() , y2 = Read();
		if(x1 == x2) L[min(y1,y2)].a++;
		else H[min(x1,x2)].a++;
	}
	for(int i = 1 ; i <= max(n,m) ; i++){
		H[i].odr = i;
		H[i].usd = false;
		L[i].odr = i;
		L[i].usd = false;
	}
	sort(H + 1 , H + n ,cmp);
	sort(L + 1 , L + m ,cmp);
	for(int i = 1 ; i <= k ; i ++ ) H[i].usd = true;
	for(int i = 1 ; i <= l ; i ++ ) L[i].usd = true;
	sort(H + 1 , H + n ,cmp2);
	sort(L + 1 , L + m ,cmp2);
	for(int i = 1 ; i <= n ; i++){
		if(H[i].usd) cout << i << " ";
	}
	cout << endl;
	for(int i = 1 ; i <= m ; i++){
		if(L[i].usd) cout << i << " ";
	}
	return 0;
}
