#include <iostream>
#include <algorithm>

using namespace std;

struct Event{
	int time;
	int type;
};

bool CompareEvent(const Event& a,const Event& b ){
	if(a.time == b.time){
		return a.type > b.type;
	}
	return a.time < b.time;
}

int main(){
	int n;
	
	cin >> n;
	
	Event events[2*n];
	
	int eventcounts = 0;
	
	for(int i = 0;i<n;i++){
		int start,end;
		cin >> start >> end;
		events[eventcounts++] = {start, 1};
		events[eventcounts++] = {end, -1};
	}
	
	sort(events, events + eventcounts, CompareEvent);
	
	int maxCustomer = 0, currentCustomer = 0;
	int eventstart = 0, eventend = 0;
	bool ismaxInterval = false;
	
	for(int i = 0 ;i<eventcounts;i++){
		if(events[i].type == 1){
			currentCustomer++;
			if(currentCustomer > maxCustomer){
				maxCustomer = currentCustomer;
				eventstart = events[i].time;
				ismaxInterval = true;
			}
		}
		else{
			if(ismaxInterval && currentCustomer == maxCustomer){
				eventend = events[i].time;
				ismaxInterval = false;
			}
			currentCustomer--;
		}
	}
	
	cout<<eventstart<<" "<<eventend<<" "<<maxCustomer<<endl;
}
