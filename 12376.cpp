//       In the name of         ****                      God                     ****

/*

Copyright (C)          JadedBeast

                                   Morocco

created : 25/4/2019
    
*/

#include <bits/stdc++.h>

using namespace std;
const int MAX=115;

vector <int> adj[MAX];
int weigth[MAX],d[MAX];
bool used[MAX];
int ans,ind;
void addEdge(int x , int y){
	adj[x].push_back(y);
}
void dfs(int s){
	used[s]=true;
	int mmax=0;
	for(int x : adj[s]){
		if(!used[x])
			if(weigth[x]>mmax){
				mmax=weigth[x];
				ind=x;
			}
	}
	if(!used[ind]){
		ans+=mmax;
		dfs(ind);
	}

}

inline void JadedBeast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	JadedBeast();
	int n,m,t,x,y;
	cin >> t;
	 for(int i=1;i<=t;i++){
	 	ans=0;
	 	memset(used,false,sizeof(used));
	 	memset(weigth,0,sizeof(weigth));
	 	
	 	for(int j=0; j<MAX;j++)
	 		adj[j].clear();

	 	cin >> n >>m;

	 	for(int j=0 ; j<n;j++)
	 		cin >> weigth[j];

	 	for(int j=0 ;j<m ;j++){
	 		cin >> x >>y;
	 		addEdge(x , y);
	 	}
	 	dfs(0);
	 	cout <<"Case "<<i<<": "<<ans<<" "<<ind<<endl;
	 }


	return 0 ;

}
