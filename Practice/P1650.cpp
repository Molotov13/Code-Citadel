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
const int MAXN = 2000 + 20;
int a[MAXN],b[MAXN],n;
bool cmp(int x,int y){
	return x > y;
}
int ans = 0;
#undef int 
int main(){
	#define int long long
	n = Read();
	for(int i = 1 ; i <= n ; i++){
		a[i] = Read();
	}
	for(int i = 1 ; i <= n ; i++){
		b[i] = Read();
	}
	sort(b + 1 , b + 1 + n , cmp);
	sort(a + 1 , a + 1 + n , cmp);
	int la = 1 , ra = n , lb = 1 , rb = n;
	while(ra > la){
		if(a[la] > b[lb]){
			la ++;
			lb ++;
			ans ++;
		}
		else if(b[lb] > a[la]){
			ra --;
			lb ++;
			ans --;
		}
		else{
			if(a[ra] > b[rb]){
				ra --;
				rb --;
				ans++;
			}
			else{
				if(a[ra] < b[lb])ans --;
				ra --;
				lb ++;
			}
		}
	}
	if(b[lb] != a[la]) ans += (b[lb] > a[la] ? -1 : 1);
	cout << ans * 200 << endl;
	return 0;
}
