//       In the name of         ****                      God                     ****

/*

Copyright (C)          JadedBeast

                                   Morocco

created : 01/5/2019
    
*/

#include <bits/stdc++.h>

using namespace std;
const int MAX=1001;
#define pi pair<int,int>
#define pii pair<int,pi>
#define oo 1e8

int n,m;
vector <pi> adj[MAX][MAX];
int d[MAX][MAX],mat[MAX][MAX];
int xc[]={0,1};
int yc[]={1,0};

void addEdge(int x , int y){
	for(int i=0;i<2;i++)
		if(x+xc[i]>=0 && x+xc[i]<n && y+yc[i]>=0 && y+yc[i]<m){
			adj[x][y].push_back({x+xc[i],y+yc[i]});	
			adj[x+xc[i]][y+yc[i]].push_back({x,y});
		}
}
void dijkstra(pi s){
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			d[i][j]=oo;

	d[s.first][s.second]=0;
	set<pii> q;
	q.insert({0,s});

	while(!q.empty()){
		pi s=(q.begin()->second);
		q.erase(q.begin());
		for(auto x : adj[s.first][s.second]){
			int i=x.first,j=x.second;
			int weight= mat[i][j];
			if(d[s.first][s.second]+weight<d[i][j] ){
				q.erase({d[i][j],{i,j}});
				d[i][j]=d[s.first][s.second]+weight;
				q.insert({d[i][j],{i,j}});
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
	int t;
	cin >> t;

	while(t--){
		cin >> n >>m;
		memset(mat,0,sizeof(mat));
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
				adj[i][j].clear();
			
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin >> mat[i][j];
				addEdge(i,j);
			}
	

		dijkstra({0,0});
		cout <<mat[0][0]+d[n-1][m-1]<<endl;
	}




	return 0 ;

}
