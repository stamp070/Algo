#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,find;
	cin >> n >> find;
	vector<int> arry(n);
	
	for(int i=0;i<n;i++){
		cin >> arry[i];
	}
	sort(arry.begin(),arry.end());
	int diff = 10000;
	int left = 0, right = n-1;
	while(left<=right){
		int sum = arry[left]+arry[right];
		if(sum == find){
			if(abs(arry[left]-arry[right]) < diff){
				diff = abs(arry[left]-arry[right]);
				left++;
				right--;
			}
		}else if(sum < find){
			left++;
		}else{
			right--;
		}
	}
	cout << diff;
}
