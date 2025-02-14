#include<iostream>
#include<algorithm>
using namespace std;
int min_v = 1000;
int check(int a[],int x[],int n){
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		if(x[i]==1)
			sum1+=a[i-1];
		else
			sum2+=a[i-1];
	}
	int val = abs(sum1-sum2);
		if(val<min_v){
			min_v = val;
		for(int i=1;i<=n;i++)
			cout << x[i] << " ";
		cout << endl;
	}
}
int subset1(int a[],int x[],int l,int r){
	if(l==r){
		check(a,x,r);
	}
	else{
		x[l+1] = 1;
		subset1(a,x,l+1,r);
		x[l+1] = 0;
		subset1(a,x,l+1,r);
	}
}
int main(){
	int n;
	cin >> n;
	int a[n], x[n+1];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	subset1(a,x,0,n);
	cout << min_v;
	return 0;
}
/*
7
4 12 13 29 31 32 50
*/
