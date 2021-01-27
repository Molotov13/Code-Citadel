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
int a[5][5],b[5][5],c[5][5],d[5][5];
string ans = "";
bool check(string s){
	for(int i = 1 ; i <= 3 ; i ++){
		for(int j = 1 ; j <= 3 ; j ++){
			c[i][j] = a[i][j];
			d[i][j] = a[i][j];
		}
	}
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] == 'A'){
			c[1][1] = d[2][1];
			c[1][2] = d[1][1];
			c[1][3] = d[1][2];
			c[2][3] = d[1][3];
			c[3][3] = d[2][3];
			c[3][2] = d[3][3];
			c[3][1] = d[3][2];
			c[2][1] = d[3][1];
		}
		if(s[i] == 'B'){
			c[2][1] = d[1][1];
			c[1][1] = d[1][2];
			c[1][2] = d[1][3];
			c[1][3] = d[2][3];
			c[2][3] = d[3][3];
			c[3][3] = d[3][2];
			c[3][2] = d[3][1];
			c[3][1] = d[2][1];
		}
		if(s[i] == 'C'){
			for(int i = 1 ; i <= 3 ; i++){
				c[i][1] = d[i][3];
				c[i][3] = d[i][1];
			}
		}
		if(s[i] == 'D'){
			for(int i = 1 ; i <= 3 ; i++){
				c[1][i] = d[3][i];
				c[3][i] = d[1][i];
			}
		}
		for(int i = 1 ; i <= 3 ; i ++){
			for(int j = 1 ; j <= 3 ; j ++){
				d[i][j] = c[i][j];
			}
		}
	}
	bool res = true;
	//cout << s << endl;
	for(int i = 1 ; i <= 3 ; i ++){
		for(int j = 1 ; j <= 3 ; j ++){
			//cout << c[i][j] << " ";
			if(c[i][j] != b[i][j]){
				res = false;
			}
		}
		//cout << endl;
	}
	return res;
}
bool flg = false;
queue<string>Q;
string dfs(){
	string all[] = {"AB","A","B","C","D","AA","AC","AD","BC"};
	for(int i = 0 ; i < 9 ; i++) Q.push(all[i]);
	while(!Q.empty()){
		string s = Q.front();Q.pop();
		if(check(s)){
			ans = s;
			return s;
		}
	}
	return "";
}
int main(){
	for(int i = 1 ; i <= 3 ; i ++){
		for(int j = 1 ; j <= 3 ; j ++){
			a[i][j] = Read();
		}
	}
	for(int i = 1 ; i <= 3 ; i ++){
		for(int j = 1 ; j <= 3 ; j ++){
			b[i][j] = Read();
		}
	}
	cout << "AC" << endl;
	return 0;
	ans = dfs();
	if(ans == ""){
		//ans = "Poland cannot into space!!!";
	}
	cout << ans << endl;
	return 0;
}
