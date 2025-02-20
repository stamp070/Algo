#include<iostream>
#include<algorithm>
using namespace std;
int min_v = 1000;

int greedy(int a[],int x[],int r){
	int sum1=0,sum2=0;
	for(int i=1;i<=r;i++){
		if(sum1<=sum2){
			sum1+=a[i-1];
			x[i]=1;
		}else{
			sum2+=a[i-1];
			x[i]=0;
		}
	}
	return abs(sum1-sum2);
}
bool comp(int a,int b){
	return a>b;
}
int main(){
	int n;
	cin >> n;
	int a[n], x[n+1]={0};
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,comp);
	cout << greedy(a,x,0,n);
	
	return 0;
}
