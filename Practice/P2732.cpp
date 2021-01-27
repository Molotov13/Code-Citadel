#include<bits/stdc++.h>
using namespace std;
inline int Read(){
	int s = 0 ,w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >='0' && ch <='9'){
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
struct dsc{
	int a[1010],c;
}s[200];
int n,b,f[10][10][10][10][10],odr[10000],x[10000];
int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i ++){
		int t = Read();
		for(int j = 1 ; j <= t ; j++){
			int x = Read();
			s[i].a[x] = Read();
		}
		s[i].c = Read();
	}
	b = Read();
	for(int i = 1 ; i <= b ; i ++){
		odr[i] = Read();
		x[i] = Read();
		s[n + i].a[odr[i]] = 1;
		s[n + i].c = Read();
	}
	/*for(int i = 1 ; i <= n + b ; i ++){
		cout << i << ":";
		for(int j = 1 ; j <= n ; j ++){
			cout << s[i].a[odr[j]] << " ";
		}
		cout << "(" << s[i].c << ")" << endl;
	}*/
	memset(f,127,sizeof(f));
	f[0][0][0][0][0] = 0;
	for(int i = 1 ; i <= n + b ; i++){
		for(int a = s[i].a[odr[1]] ; a <= x[1] ; a ++){
			for(int b = s[i].a[odr[2]] ; b <= x[2] ; b ++){
				for(int c = s[i].a[odr[3]] ; c <= x[3] ; c ++){
					for(int d = s[i].a[odr[4]] ; d <= x[4] ; d++){
						for(int e = s[i].a[odr[5]] ; e <= x[5] ; e ++){
							f[a][b][c][d][e] = min(f[a][b][c][d][e],f[a - s[i].a[odr[1]]][b - s[i].a[odr[2]]][c - s[i].a[odr[3]]][d - s[i].a[odr[4]]][e - s[i].a[odr[5]]] + s[i].c);
						}
					}
				}
			}
		}
	}
	cout << f[x[1]][x[2]][x[3]][x[4]][x[5]] << endl;
	return 0;
}
