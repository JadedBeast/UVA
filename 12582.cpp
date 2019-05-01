//       In the name of         ****                      God                     ****

/*

Copyright (C)          JadedBeast

                                   Morocco

created : 25/4/2019
    
*/

#include <bits/stdc++.h>

using namespace std;
const int MAX=27;

vector <char> child[MAX];
char parent[MAX];
bool used[MAX];
int occ[MAX];

inline void JadedBeast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	JadedBeast();
	int t;
	string s;
	cin >> t;
	for(int i=1 ; i<=t ;i++){

		memset(occ,0,sizeof(occ));
		memset(used,false,sizeof(used));
		for(int j=0;j<MAX;j++){
			child[j].clear();
			parent[j]='\0';
		}

		cin >> s;
		char tmp=s[0];
		used[s[0]-'A']=true;
		for(int j=1; s[j]; j++){
			if(!used[s[j]-'A']){	
				used[s[j]-'A']=true;	
				child[tmp-'A'].push_back(s[j]);
				parent[s[j]-'A']=tmp;
				tmp=s[j];
			}
			else
				tmp=parent[s[j]-'A'];
		}

	for(char x : parent)
			occ[x-'A']++;
	for(int j=0 ; j<MAX;j++)
		for(char x : child[j])
			occ[x-'A']++;

	cout <<"Case "<<i<<endl;
	for(int j=0 ; j<MAX;j++)
		if(occ[j]){
			cout <<char(j+'A')<<" = "<<occ[j]<<endl;
		}
	}
	return 0 ;

}
