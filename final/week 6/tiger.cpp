#include<bits/stdc++.h>
using namespace std;
vector<int> memo(100);
int tiger(int n,int k){
	if(n==1||k==1){
		return 1;
	}
	return tiger(n,k-1) + tiger(n-1,k);
}
int main(){
	int i,j;
	cin >> i >> j;
	cout << tiger(i,j);
	return 0;
}
