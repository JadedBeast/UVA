//       In the name of         ****                      God                     ****

/*

Copyright (C)          JadedBeast

                                   Morocco

created : 02/5/2019
    
*/

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define oo 1e15
const int MAX=22222;

vector <pi> adj[MAX];
long long d[MAX];


void addEdge(int x, int y,int w){
	adj[x].push_back({y,w});
	adj[y].push_back({x,w});
}

void dijkstra(int s){
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
	int t,n,m,s,f,x,y,w;
	cin >> t;
	for(int k=1;k<=t;k++){	
		for(int i=0 ;i<MAX;i++)
			adj[i].clear();

		cin >>n>>m>>s>>f;
		for(int i=0;i<m;i++){
			cin >> x >>y>>w;
			addEdge(x,y,w);
		}
		dijkstra(s);
		if(d[f]!=oo)
			cout <<"Case #"<<k<<": "<<d[f]<<"\n";
		else
			cout <<"Case #"<<k<<": unreachable\n";

	}
	
	return 0 ;

}
