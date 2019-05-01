//       In the name of         ****                      God                     ****

/*

Copyright (C)          JadedBeast

                                   Morocco

created : 01/5/2019
    
*/
// if if  if if  if if  if if  if if  if if  if if  if if  if if  KILL ME  if if  if if  if if  if if  if if  if if 
#include <bits/stdc++.h>

using namespace std;
const int MAX=101;
#define oo 1e8

char mat[MAX][MAX];
int x,y;



inline void JadedBeast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void direction(char c){
		if(c=='N')
			x=-1,y=0;
		else if(c=='S')
			x=1,y=0;
		else if(c=='O') //west
			x=0,y=-1;
		else if(c=='L')
			x=0,y=1;	
}

int main(void) {
	JadedBeast();
	int n,m,len,st[2];
	string s;

	cin >> n >> m >>len;

	while(n && m && len){
		for(int i=0 ; i<MAX ;i++)
			for(int j=0 ; j<MAX ;j++)			
				mat[i][j]='\0';

		for(int i=0 ; i<n ;i++)
			for(int j=0 ; j<m ;j++){	
				cin >> mat[i][j];
				if(mat[i][j]!='.' && mat[i][j]!='*' && mat[i][j]!='#'){
					st[0]=i,st[1]=j;
				}
			}
		cin >> s;

		int ans=0;
		direction(mat[st[0]][st[1]]);

		for(int i=0;s[i];i++){

			if(s[i]=='F'){
				if(st[0]+x>=0 && st[1]+y >=0 && st[0]+x<n && st[1]+y<m ){
					if(mat[st[0]+x][st[1]+y]!='#'){
						st[0]=st[0]+x,st[1]=st[1]+y;
						if(mat[st[0]][st[1]]=='*'){
							mat[st[0]][st[1]]='.';
							ans++;
						}
					}
				}
			}
			else if(s[i]=='E'){
				if(x==-1 && y==0)
					x=0,y=-1;
				else if(x==0 && y==-1)
					x=1,y=0;
				else if(x==1 && y==0)
					x=0,y=1;
				else if(x==0 && y==1)
					x=-1,y=0;
			}
			else if (s[i]=='D'){
				if(x==-1 && y==0)
					x=0,y=1;
				else if(x==0 && y==1)
					x=1,y=0;
				else if(x==1 && y==0)
					x=0,y=-1;
				else if(x==0 && y==-1)
					x=-1,y=0;				
			}
		}
		cout << ans <<endl;
		cin >> n >> m >>len;
		//D 90° right   E 90° left    F forward
	}



	return 0 ;

}
