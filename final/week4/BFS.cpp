#include<bits/stdc++.h>
using namespace std;
int G[10][10]={0},visited[10]={0},n;
void BFS(int i){
	queue<int> q;
	q.push(i);
	visited[i]=1;
	
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		
		for(int j=0;j<n;j++){
			if(G[temp][j] && !visited[j]){
				q.push(j);
				visited[j] = 1;
			}
			
		}
	}
}
int main(){
	int vertex;
	cin >> n >> vertex;
	for(int i=0;i<vertex;i++){
		int a,b;
		cin >> a >> b;
		G[a][b]=1;
		G[b][a]=1;
	}
	BFS(0);
	
	return 0;
}
/*
8 10
0 1 0 2 0 3 0 4
1 5 2 5 3 6 4 6
5 7 6 7
*/
