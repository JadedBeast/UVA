//       In the name of         ****                      God                     ****

/*

Copyright (C)          JadedBeast

                                   Morocco

created : 02/5/2019
    
*/

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define oo 1e8
const int MAX=10050;




void addEdge(int x, int y,int w,vector <pi> front[],vector<pi> back[]){
	front[x].push_back({y,w});
	back[y].push_back({x,w});
}

void dijkstra(int s,vector <pi> adj[],int d[]){
	fill(d,d+MAX,oo);
	d[s]=0;
	set<pi> q;
	q.insert({0,s});
	while(!q.empty()){
		s=(q.begin())->second;
		q.erase(q.begin());
		for(auto x : adj[s]){
			int w= x.second;
			int to = x.first;

			if(d[s]+1ll*w<d[to]){
				q.erase({d[to],to});
				d[to]=d[s]+1ll*w;
				q.insert({d[to],to});
			}
		}
	}
}

inline void JadedBeast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	JadedBeast();
	int t,n,m,s,e,p,x,y,w;
	cin >> t;
	while(t--){	
		cin >>n >>m >>s >>e >>p ;
		vector <pi> front[MAX];
		vector <pi> back[MAX];
		int df[MAX],db[MAX];

		for(int i=0;i<m;i++){
			cin >> x >>y>>w;
			addEdge(x,y,w,front,back);
		}
		dijkstra(s,front,df);
		dijkstra(e,back,db);
		int ans=-1;
		for(int i=1;i<=n;i++)
			for(auto x : front[i]){
				int weight=x.second;
				int to=x.first;
				if(df[i]+db[to]+weight<=p)
					ans=max(ans,weight);

			}	
		cout << ans<<endl;				
	}
	
	return 0 ;

}
