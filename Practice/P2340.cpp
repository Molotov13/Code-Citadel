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
int n,eq[410],iq[410],f[800010];
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		iq[i] = Read();
		eq[i] = Read();
	}
	memset(f,-0x3f,sizeof(f));
	f[400000] = 0;
	for(int i = 1 ; i <= n ; i ++){
		cout << "K" << endl;
		if(iq[i] >= 0){
			for(int j = 800000 ; j >= iq[i] ; j --){
				f[j] = max(f[j],f[j - iq[i]] + eq[i]);
			}
		}
		else{
			for(int j = 0 ; j <= iq[i] + 800000 ; j ++){
				f[j] = max(f[j],f[j - iq[i]] + eq[i]);		
			}
		}
	}
	int ans = 0;
	for(int i = 400000 ; i <= 800000 ; i ++){
		if(f[i] < 0) continue;
		ans = max(i + f[i] - 400000,ans);
	}
	cout << ans << endl;
	return 0;
}
