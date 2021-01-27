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
	return s*w;
}
string a,b;
int main(){
	cin >> a >> b;
	int ans = 0;
	for(int i = 0 ; i < a.size() - 1 ; i++){
		for(int j = 1 ; j < b.size() ; j++){
			if((a[i] == b[j]) && (a[i+1] == b[j-1])){
				ans ++;
			}
		}
	}
	cout << (1 << ans) << endl;
	return 0;
}
