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
const int MAXN = 1e5 + 50;
const int inf = 1e9 + 7;
int n,m,s,t;
char c[10010];
int ulen,num,sum;
vector <int> req[MAXN];
bool canuse1[MAXN],canuse2[MAXN];
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],tot = 1;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int dis[MAXN],now[MAXN];
bool bfs(){
	for(int i = s ; i <= t ; i++) dis[i] = inf;
	queue<int>Q;
	Q.push(s);
	dis[s] = 0;
	now[s] = head[s];
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(dis[v] == inf && val[i]){
		//		cout << u << "--> " << v << endl;
				Q.push(v);
				now[v] = head[v];
				dis[v] = dis[u] + 1;
				if(v == t) return 1;
			}
		}
	}
	return 0;
}
int dfs(int x,int sum){
	if(x == t) return sum;
	int k,res = 0;
	for(int &i = now[x] ; i && sum ; i = nxt[i]){
		int v = to[i];
		if((dis[v] == dis[x] + 1) && val[i]){
			k = dfs(v,min(sum,val[i]));
			if(!k) dis[v] = inf;
			res += k;
			sum -= k;
			val[i] -= k;
			val[i ^ 1] += k;
		}
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	s = 0 , t = n + m + 2;
    for (int i=1;i<=n;i++){
    	int v;
        scanf("%d",&v);
        sum += v;
        add(s,i,v);
    //    cout << s << "-->" << i << ":" << v << endl;
        add(i,s,0);
        memset(c,0,sizeof(c));
        cin.getline(c,10000);
        ulen=0;
        while(sscanf(c+ulen,"%d",&num)==1){
            add(i,num + n,inf);
    //      cout << i << "-->" << num + n << ": INF" << endl;
            add(num + n,i,0);
            if (num==0) ulen++;
            else while (num){
                num/=10;
                ulen++;
            }
            ulen++;
        }
    }
	for(int i = 1 ; i <= m ; i++){
    	int x = Read();
    	add(i + n,t,x);
    //	cout << i + n << "-->" << t << ":" << x << endl;
    	add(t,i + n,0);
	}
	int ans = 0;
	while(bfs()){
		ans += dfs(s,inf);
	}
	for(int i = 1 ; i <= n ; i ++) if(dis[i] != inf) cout << i << " ";
	cout << endl;
	for(int i = n + 1 ; i <= n + m ; i ++) if(dis[i] != inf) cout << i - n << " ";
	cout << endl;
	cout << sum - ans << endl;
	return 0;
}

