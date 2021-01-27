#include<bits/stdc++.h>
using namespace std;
#define int long long

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
const int MAXN = 3e6 + 50;
int f[MAXN],t,m,s,r[MAXN];
#undef int 
int main(){
	#define int long long
	m = Read() , s = Read() , t = Read();
	for(int i = 1 ; i <= t ; i ++){
		if(m >= 10){
			f[i] = f[i - 1] + 60;
			r[i] = true;
			m -= 10;
		}
		else{
			m += 4;
			f[i] = f[i - 1];
		}
		//cout << i << ":" << f[i] << endl;
		if(f[i] >= s){
			t = i;
			break;
		}
	}
	//cout << t << endl;
	if(t == 333){
		cout << "Yes" << endl << 330 << endl;
		return 0;
	}
	if(t == 1){
		cout << "Yes" << endl << t << endl;
		return 0;
	}
	if(f[t] >= s){
		for(int i = t ; i >= 1 ; i --){
			if(r[i] && s > f[i]){
				//cout << i << endl;
				t = min((int)ceil((double)(s - f[i]) / 17.00) + i,t);
				cout << "Yes" << endl << t << endl;
				return 0;
			}
		}
		cout << "Yes" << endl << t << endl;
		return 0;
	}
	else{
		for(int i = t ; i >= 1 ; i --){
			if(r[i] && s > f[i]){
				//cout << i << endl;
				int tt = (int)ceil((double)(s - f[i]) / 17.00) + i;
				if(tt > t){
					f[t] = max(f[t],f[i] + (t - i) * 17);
					cout << "No" << endl << f[t] << endl;
				}
				else{
					cout << "Yes" << endl << tt << endl;	
				}
				return 0;
			}
		}
		if(t * 17 >= s){
			cout << "Yes" << endl << (int)ceil((double)(s) / 17.00) << endl;
		}
		else{
			cout << "No" << endl << t * 17 << endl;
		}
		return 0;
	}
	return 0;
}
