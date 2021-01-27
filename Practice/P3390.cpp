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

const int mod = 1e9 + 7;
const int MAXN = 100 + 10;
int n,k;
struct Matrix{
	int a[MAXN][MAXN];
	Matrix(){
		memset(a,0,sizeof(a));
	}
	inline void build(){
		for(int i = 1 ; i <= n ; i++) a[i][i] = 1;
	}
}s;
Matrix operator *(const Matrix &a,const Matrix &b){
	Matrix c;
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				c.a[i][j] = (c.a[i][j] + (a.a[i][k] % mod )*(b.a[k][j] % mod))%mod;
			}
		}	
	}
	return c;
}

Matrix MatrixQuickPow(Matrix a,int b){
	Matrix res; res.build();
	while(b){
		if(b%2){
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}
#undef int 
int main(){
	#define int long long
	n = Read() , k = Read();
	
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j++){
			s.a[i][j] = Read();
		}
	}
	Matrix I;
	I = MatrixQuickPow(s,k);
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j++){
			cout << I.a[i][j] % mod << " ";
		}
		cout << endl;
	}
	return 0;
}
