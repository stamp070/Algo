#include<bits/stdc++.h>
using namespace std;
int memo[10] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int help(int n){
	if(n==0)
		return 1;
	if(memo[n]!=-1) return memo[n];
	memo[n] = n* help(n-1);
	
	return memo[n];
}
int binomial(int n,int k){
	return help(n) / (help(n-k) * help(k));	
}
int main(){
	int n,k;
	cin >> n >> k;
	cout << binomial(n,k);
	return 0;
}
