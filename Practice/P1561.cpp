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
const int MAXN = 5e6;
int n,sumu,sumd,maxu = 19260817 ,maxd = 19260817,up[MAXN],dn[MAXN];
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		up[i] = Read();
		dn[i] = Read();
		sumu += up[i];
		sumd += dn[i];
		maxu = min(maxu,up[i]);
		maxd = min(maxd,dn[i]);
	}
	cout << max(sumu + maxd,sumd + maxu);
	return 0;
}
