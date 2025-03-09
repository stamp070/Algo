#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > memo(100,vector<int>(100,-1));
int binomial(int n,int k){
	if(n==k || k==0)
		return 1;
	
	if(memo[n][k]!=-1)	return memo[n][k];
	memo[n][k] = binomial(n-1,k-1) + binomial(n-1,k);
	
	return memo[n][k];
}

int btmup(int n,int k){
	for(int i=0;i<=n;i++){
		memo[i][i] = 1;
		memo[i][0] = 1;
	}
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<n;j++){
			if(i>j){
				memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
			}
		}
		
	}
	return memo[n][k];
	
}
int main(){
	int n,k;
	cin >> n >> k;
	
//	cout << binomial(n,k) << endl;
	cout << btmup(n,k);
	return 0;
}
