#include<bits/stdc++.h>
using namespace std;
vector<int> memo(100,-1);
long long fac(int n){
	if(n==1){
		return 1;
	}
	if(memo[n]!=-1)
		return memo[n];
		
	memo[n] = n*fac(n-1);
	return memo[n];
}

long long btmup(int n){
	memo[1] = 1;
	for(int i=2;i<=n;i++){
		memo[i] = i * memo[i-1];
	}
	return memo[n];
}
int main(){
	int n;
	cin >> n;
	
//	cout << fac(n) << endl;
	cout << btmup(n) << endl;
	return 0;
}
