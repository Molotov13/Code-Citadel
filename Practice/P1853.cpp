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
struct ivt{
	int v,c;
	bool abd;
}s[100];
int f[10000050],v[150],c[150],T,n,m;
bool cmp(ivt a,ivt b){
	if(a.abd) return false;
	if(b.abd) return true;
	return a.v > b.v;
}
#undef int 
int main(){
	#define int long long
	m = Read() , T = Read() , n = Read();
	for(int i = 1 ; i <= n ; i ++){
		s[i].c = Read();
		s[i].v = Read();
		s[i].abd = false;
	}
	int num = 0;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = i + 1 ; j <= n ; j ++){
			if(s[i].v >= s[j].v && s[i].c <= s[j].c){
				s[j].abd = true;
				num ++;
			}
		}
	}
	sort(s + 1 , s + 1 + n , cmp);
	n -= num;
	while(T--){
		memset(f,0,sizeof(f));
		for(int i = 1 ; i <= n ; i ++){
			for(int j = s[i].c ; j <= m ; j ++){
				f[j] = max(f[j],f[j - s[i].c] + s[i].v);
			}
		}
		m += f[m];
	}
	cout << m << endl;
	return 0;
}
