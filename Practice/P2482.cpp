#include <bits/stdc++.h>
using namespace std;
inline int Read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = - 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;	
}
const int MAXN = 3000;
struct Pig{
	int id,kar,num;
	char card[MAXN];
	bool eq,lv,usd[MAXN];
	int hp;
}s[30];
char Heap[MAXN],top;
bool rival(int a,int b){
	if(s[a].kar == 1 && s[b].kar == 3) return true;
	if(s[a].kar == 2 && s[b].kar == 3) return true;
	if(s[a].kar == 3 && s[b].kar == 1) return true;
	if(s[a].kar == 3 && s[b].kar == 2) return true;
	return false;
}
bool ally(int a,int b){
	if(s[a].kar == 1 && s[b].kar == 2) return true;
	if(s[a].kar == 2 && s[b].kar == 1) return true;
	if(s[a].kar == 2 && s[b].kar == 2) return true;
	if(s[a].kar == 3 && s[b].bar == 3) return true; 
}
void Hurt(int u,int v){	
	if(s[v].id == 1 && s[u].kar != 2){
		s[u].kar = 3;
	}
	else display(u);
	s[v].hp --;
	if(s[v].hp == 0) kill(u,v);
}
int HaveDisable(int u){
	for(int i = 1 ; i <= s[u].num ; i++){
		if(s[u].usd[i]) continue;
		if(s[u].card[i] == 'J') return i;
 	}
 	return false;
}
bool Help(int u){
	for(int i = u + 1 ; i <= n ; i++){
		if(ally(i,u) && HaveDisable(i)){
			s[i].usd[HaveDisable(i)] = 1;
			display(i);
			return true;
		}
	}
	return false;
}
void attack(int u,int v){
	bool flg = true;
	for(int i = 1 ; i <= s[v].num ; i++){
		if(s[v].usd[i]) continue;
		if(s[v].card[i] == 'D'){
			s[v].usd[i] = true;
			return ;
		}
	}
	Hurt(u,v);	
}
void battle(int u,int v){
	if(Help(v))
	while(1){
		bool flg = true;
		for(int i = 1 ; i <= s[v].num ; i++){
			if(s[v].usd[i]) continue;
			if(s[v].card[i] == 'K'){
				s[v].usd[i] = true;
				flg = 1;
				break;
			}
		}
		if(!flg){
			Hurt(u,v);	
			return ;
		}
		bool flg = true;
		for(int i = 1 ; i <= s[u].num ; i++){
			if(s[u].usd[i]) continue;
			if(s[u].card[i] == 'K'){
				s[u].usd[i] = true;
				flg = 1;
				break;
			}
		}
		if(!flg){
			Hurt(v,u);
			return 0;
		}
	}
}
void Raid(int u){
	for(int i = u + 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= s[i].num ; j++){
			if(s[i].usd[j]) continue;
			if(s[i].card[j] == 'K'){
				s[i].usd[j] = true;
				flg = 1;
				break;
			}
		}
		if(!flg){
			if(!Help(i)) Hurt(u,i);
		}
	}
	for(int i = 1 ; i < u ; i ++){
		for(int j = 1 ; j <= s[i].num ; j++){
			if(s[i].usd[j]) continue;
			if(s[i].card[j] == 'K'){
				s[i].usd[j] = true;
				flg = 1;
				break;
			}
		}
		if(!flg){
			if(!Help(i)) Hurt(u,i);
		}
	}
}
void Shot(int u){
	for(int i = u + 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= s[i].num ; j++){
			if(s[i].usd[j]) continue;
			if(s[i].card[j] == 'D'){
				s[i].usd[j] = true;
				flg = 1;
				break;
			}
		}
		if(!flg){
			if(!Help(i)) Hurt(u,i);
		}
	}
	for(int i = 1 ; i < u ; i ++){
		for(int j = 1 ; j <= s[i].num ; j++){
			if(s[i].usd[j]) continue;
			if(s[i].card[j] == 'D'){
				s[i].usd[j] = true;
				flg = 1;
				break;
			}
		}
		if(!flg){
			if(!Help(i)) Hurt(u,i);
		}
	}
}
void kill(int u,int v){
	
}
bool check(){
	if(s[1].lv) return false;
	for(int i = 2 ; i <= n ; i++){
		if(s[i].lv && s[i].id == 3) return false;
	}
	return true;
}
int d(int u,int v){
	int res = 0;
	for(int i = u + 1 ; i <= n ; i ++){
		if(s[i].lv) res ++;
		if(i == v) return res;
	}
	for(int i = 1 ; i < u ; i ++){
		if(s[i].lv) res ++;
		if(i == v) return res;	
	}
}
void display(int u){
	s[u].kar = s[u].id;
}
int main(){
	n = ply = Read() , m = top = Read();
	for(int i = 1 ; i <= n ; i ++){
		string x;
		cin >> x;
		s[i].kar = 0;
		if(x == "MP") s[i].id = s[i].kar = 1;//Ö÷¹«
		if(x == "ZP") s[i].id = 2;//ÖÒÖí
		if(x == "FP") s[i].id = 3;//·´Öí   
		for(int j = 1 ; j <= 4 ; j ++){
			char cd;
			cin >> cd; 
			s[i].card[++s[i].num] = cd;
		}
	}
	for(int i = 1 ; i <= m ; i ++){
		cin >> Heap[i];
	}
	while(check()){
		for(int i = 1 ; i <= n ; i++){
			if(!s[i].lv) continue;
			s[++s[i].num].card = Heap[top--];
			s[++s[i].num].card = Heap[top--];
			bool ys = false,yt = false;
			for(int j = 1 ; j <= s[i].num ; j++){
				if(s[i].usd[j]) continue;
				char k = s[i].card[j];
				if(k == 'P'){
					if(yt || s[i].hp == 4) continue;
					s[i].hp ++;
					yt = true;
					s[i].usd[j] = true;
				}
				if(k == 'K'){
					for(int p = 1 ; p <= n ; p ++){
						if(p == i || (ys && !s[i].eq)) continue;
						if(d(p,i) == 1 && rival(i,p)){
							s[i].usd[j] = true;
							ys = true;
							display(i);
							attack(i,p);
							break;
 						}
					}
				}
				if(k == 'F'){
					for(int p = 1 ; p <= n ; p ++){
						if(p == i) continue;
						if(rival(i,p)){
							display(i);
							battle(i,p);
 						}
 						s[i].usd[j] = true;
 						break;
					}
				}
				if(k == 'N'){
					Raid(i);
					s[i].usd[j] = true;
				}
				if(k == 'W'){
					Shot(i);
					s[i].usd[j] = true;
				}
				if(k == 'Z'){
					s[i].usd[j] = true;
					s[i].eq = true;
				}
			}
		}
	}
	return 0;
}
