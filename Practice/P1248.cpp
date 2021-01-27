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
int n,sumu,sumd,maxu = 19260817 ,maxd = 19260817,up[MAXN],dn[MAXN],s[MAXN];
bool cmp(int a,int b){
	return dn[a] + up[b] + max(up[a],dn[b]) > dn[b] + up[a] + max(up[b],dn[a]);
}
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		s[i] = i;
		up[i] = Read();
		sumu += up[i];
		maxu = min(maxu,up[i]);
	}
	for(int i = 1 ; i <= n ; i++){
		dn[i] = Read();
		sumd += dn[i];
		maxd = min(maxd,dn[i]);
	}
	sort(s + 1 , s + 1 + n ,cmp);
	cout << max(sumu + maxd,sumd + maxu) << endl;
	for(int i = 1 ; i <= n ; i++){
		cout << s[i] << " ";
	}
	return 0;
}
