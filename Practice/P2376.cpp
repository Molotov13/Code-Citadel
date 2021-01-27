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
#define int long long
struct coin{
	int val,num;
}s[30];
int tot;
int cnt,n,c;
int cmp(coin a,coin b){
	return a.val < b.val;
}
#undef int 
int main(){
	#define int long long
	n = Read() , c = Read();
	for(int i = 1 ; i <= n ; i++){
		int x = Read();
		s[++tot].num = Read();
		s[tot].val = x;
		if(s[tot].val >= c){
			cnt += s[tot].num;
			s[tot].num = 0;
		}
	}
	sort(s+1,s+1+n,cmp);
	while(1){
		int x = c;
		/*cout << cnt << ":";
		for(int i = 1 ; i <= n ; i++){
			cout << s[i].num << " ";
		}*
		cout << endl;*/
		for(int i = n ; i >= 1 ; i--){
			if(!s[i].num) continue;
			int q = min(x/s[i].val,s[i].num);
			x -= q*s[i].val;//cout << x << " " << q << " " << s[i].val << endl;
			s[i].num -= q;
			
		}
		if(x>0){
			for(int j = 1 ; j <= n ; j ++){
				if(s[j].num&&s[j].val>=x){
					x -=  s[j].val;
					s[j].num --;
				break;
				}
			}
		}
		if(x>0)
			break;
		else
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}

