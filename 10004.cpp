//       In the name of         ****                      God                     ****

/*

Copyright (C)          JadedBeast

                                   Morocco

created : 25/4/2019
    
*/

#include <bits/stdc++.h>

using namespace std;
const int MAX=201;

vector <int> adj[MAX];
int color[MAX];
bool bipartie =true;

void addEdge(int x, int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}

void bfs(int s){
	color[s]=0;	
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		s=q.front();
		q.pop();
		for(int x : adj[s]){
			if(color[x]==color[s]){
				bipartie=false;
				return;
			}
			if(color[x]==-1){
				q.push(x);
				color[x]=1-color[s];
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
	int l,n,x,y;
	cin >> n;
	while(n){
		bipartie=true;
		memset(color,-1,sizeof(color));
		for(int i=0 ;i<MAX;i++)
			adj[i].clear();

		cin >> l;
		for(int i=0;i<l;i++){
			cin >> x >>y;
			addEdge(x,y);
		}
		
		bfs(0);
		cout <<(bipartie?"BICOLORABLE.":"NOT BICOLORABLE.")<<endl;
		cin >>n;
	}
	
	return 0 ;

}
