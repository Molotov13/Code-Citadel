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
const int MAXN = 150 + 50;
const int MAXM = 1e7 + 10;
int n,ans,sum;
int d[MAXN],jc[MAXM];
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		d[i] = Read();
		if(d[i] == 0 && n != 1){cout << 0 << endl;return 0;};
		sum += d[i] - 1;
	}
	jc[0] = 1;
	for(int i = 1 ; i <= n ; i ++) jc[i] = jc[i - 1] * i; 
	if(sum != n - 2){cout << 0 << endl;return 0;};
	ans = 1;
	int j = 1;
	for(int i = 1 ; i <= n - 2; i ++){
		ans *= i;
		cout << ans << endl;
		if(j > n) continue;
		if(ans % jc[d[j] - 1] == 0){
			ans /= jc[d[j] - 1];
			j ++;
		}
	}
	cout << ans << endl;
	return 0;
}

