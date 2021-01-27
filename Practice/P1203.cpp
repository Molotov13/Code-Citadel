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
string s;
int n,ans;
int main(){
	n = Read();
	cin >> s;
	s += s; 
	for(int i = 0 ; i < n ; i ++){
		int res = 0 , stop;
		if(s[i] != 'w'){
			for(int j = i ; j < i + n ; j ++){
				if(s[j] == s[i] || s[j] == 'w') res ++;
				else{
					stop = j;
					break;
				}
			}
			for(int j = i + n - 1 ; j >= stop ; j --){
				if(s[j] == s[i + n - 1] || s[j] == 'w') res ++;
				else break;
			}
		} 
		else{
			char typ;
			for(int j = i ; j < i + n ; j ++){
				if(s[j] != 'w'){
					typ = s[j];
					break;
				}
			}
			for(int j = i ; j < i + n ; j ++){
				if(s[j] == typ || s[j] == 'w') res ++;
				else{
					stop = j;
					break;
				}
			}
			for(int j = i + n - 1 ; j >= stop ; j --){
				if(s[j] != 'w'){
					typ = s[j];
					break;
				}
			}
			for(int j = i + n - 1 ; j >= stop ; j --){
				if(s[j] == typ || s[j] == 'w') res ++;
				else break;
			}
		}
		ans = max(ans,res);
	}
	cout << ans << endl;
	return 0;
}

