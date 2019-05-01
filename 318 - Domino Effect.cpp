//       In the name of         ****                      God                     ****

/*

Copyright (C)          JadedBeast

                                   Morocco

created : 01/5/2019
    
*/

#include <bits/stdc++.h>

using namespace std;
#define pi pair<int,int>
#define oo 1e8

int n,m;
const int MAX=550;
vector <pi> adj[MAX];
int d[MAX];

void addEdge(int x , int y,int w){
	adj[x].push_back({y,w});
	adj[y].push_back({x,w});
}
void dijkstra(int s){
	fill(d,d+MAX,oo);
	d[s]=0;
	set<pi> q;
	q.insert({0,s});
	while(!q.empty()){
		int s=q.begin()->second;
		q.erase(q.begin());
		for(auto x : adj[s]){
			int to=x.first;
			int weight= x.second;
			if(d[s]+weight <d[to]){
				q.erase({d[to],to});
				d[to]=d[s]+weight;
				q.insert({d[to],to});
			}
		}
	}
}
void dominoes(){
	int f=1,s=-1;
	double ans=0;
	for(int i=1 ; i<=n ;i++)
		if(d[i]>ans && d[i]!=oo){
			ans=d[i];
			f=i;
		}

	for(int i=1 ; i<=n ;i++){
			for(auto x: adj[i]){
				if(d[x.first]+x.second+d[i]>2*ans){
					f=i;
					ans=(d[x.first]+d[i]+x.second)/2.0;
					s=x.first;
				}
			}
		}
	if(s==-1)
		printf("The last domino falls after %0.1f seconds, at key domino %d.\n\n",ans,f);
	else
		printf("The last domino falls after %0.1f seconds, between key dominoes %d and %d.\n\n",ans,f,s);
	
}

inline void JadedBeast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	int x,y,w,test=1;
	cin >> n >>m;

	while(n || m){
		
		for(int i=0;i<MAX;i++){
			adj[i].clear();
		}
		for(int i=0 ; i<m;i++){
			cin >> x >>y;
			cin >> w;
			addEdge(x,y,w);
		}

		dijkstra(1);

		printf("System #%d\n",test);
		dominoes();
		test++;
		cin >> n >>m;
	}




	return 0 ;

}
