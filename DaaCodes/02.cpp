#include<bits/stdc++.h>
using namespace std;

struct Job {

	char id;
	int dead;
	int profit;
};

bool comparison(Job a, Job b){
	return (a.profit > b.profit);
}


void printJobScheduling(Job arr[], int n){
	sort(arr, arr + n, comparison);

	int result[n];
	bool slot[n];

	for (int i = 0; i < n; i++)
		slot[i] = false;

	for (int i = 0; i < n; i++) {
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			if (slot[j] == false) {
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";
}


int main(){
    int n;
    cout<<"Enter total jobs availble: ";
    cin>>n;

    Job arr[n];

    cout<<"Enter id, dead, and profit of jobs: \n";

    for (int i = 0; i < n; i++){
        cin>>arr[i].id>>arr[i].dead>>arr[i].profit;
    }

	cout << "Following is maximum profit sequence of jobs \n";

	printJobScheduling(arr, n);
	return 0;
}


// a 2 100
// b 1 19
// c 2 27
// d 1 25
// e 3 15