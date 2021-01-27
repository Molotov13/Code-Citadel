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
const int MAXN = 10;
const int mod = 1e9 + 7 ;
int T,n;
struct Matrix{
	int a[MAXN][MAXN];
	Matrix(){
		memset(a,0,sizeof(a));
	}
	void inline build(){
		for(int i = 1 ; i <= 3 ; i++) a[i][i] = 1;
	}
	void inline clear(){
		for(int i = 1 ; i <= 3 ; i++){
			for(int j = 1 ; j <= 3 ; j++){
				a[i][j] = 0;
			}
		}
	}
};
Matrix operator*(const Matrix &a , const Matrix &b){
	Matrix c;
	c.clear();
	for(int k = 1 ; k <= 3 ; k++){
		for(int i = 1 ; i <= 3 ; i++){
			for(int j = 1 ; j <= 3 ; j ++){
				c.a[i][j] = (c.a[i][j] + (a.a[i][k] % mod * b.a[k][j] % mod) % mod);
			}
		}
	}
	return c;
}
Matrix MatrixQuickPow(Matrix a,int b){
	Matrix res;res.build();
	while(b){
		if(b%2){
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}
Matrix a,res;
#undef int 
int main(){
	#define int long long
	T = Read();
	while(T--){
		n = Read();
		if(n < 4){
			cout << 1 << endl;
			continue;
		}
		a.clear() , res.clear();
		a.a[1][1] = a.a[1][3] = a.a[2][1] = a.a[3][2] = 1;
		res = MatrixQuickPow(a,n - 3);
		/*for(int i = 1 ; i <= 3 ; i++){
			for(int j = 1 ; j <= 3 ; j++){
				cout << res.a[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << (res.a[1][1] + res.a[1][2] + res.a[1][3]) % mod<< endl;
	}
	return 0;
}
