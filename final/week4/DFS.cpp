#include<bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int> > G ,int visited[],int n,int i){
	cout << i << " ";
	visited[i] = 1;
	for(int j=0;j<n;j++){
		if(!visited[j] && G[i][j]==1){
			DFS(G,visited,n,j);
			
		}
	}
}
int main(){
	
	int v,e;
	cin >> v >> e;
	vector<vector<int> > G(v, vector<int>(v,0));
	int visited[v]={0};
	
	for(int i=0;i<e;i++){
		int a,b;
		cin >> a >> b;
		G[a][b]=1;
		G[b][a]=1;
	}
	DFS(G,visited,v,0);
	
	return 0;
}
/*
8 10
0 1 0 2 0 3 0 4
1 5 2 5 3 6 4 6
5 7 6 7
*/
