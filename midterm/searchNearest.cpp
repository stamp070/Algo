#include <bits/stdc++.h>
using namespace std;

int linearsearch(vector<int> &A,int target){
    int t;
    for(int i=0;i<A.size()-1;i++){
        t=i;
        if(abs(target-A[i])<abs(target-A[i+1]))
            return i;
    }
    return t;
}

void searchNearest(vector<int> &A, int M, int k) {
    int i = linearsearch(A, M);
    int left = i - 1, right = i;
    while ((right - left) <= k) {
        cout <<  left << " " << right << endl;
        if (left < 0) {
            right++;
        } else if (right >= A.size()) {
            left--;
        } else if (abs(A[left] - M) >= abs(A[right] - M)) {
            right++;
        } else {
            left--;
        }
    }

    
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int m,k;
    cin >> m >> k;
    sort(arr.begin(), arr.end());
    searchNearest(arr,m,k);
    return 0;
}