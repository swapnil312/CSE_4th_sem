# include <bits/stdc++.h>
using namespace std;
int maxDeadline = 0;
struct job{
	int id;
	int deadline;
	int profit;
};

bool compare(struct job job1, struct job job2){
	return job1.profit>job2.profit;
}
void jobSequence(struct job job_arr[], int n){
	vector<int> job_sequence;
	int booked_slots[n+1] = {0};
	sort(job_arr, job_arr+n, compare);
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= n; j++){
			if((booked_slots[j] == 0)&&(job_arr[i].deadline >= j)){
			job_sequence.push_back(job_arr[i].id);
			booked_slots[j] = 1;
			break;
		}
		}
	}
	for(auto id : job_sequence) cout<<id<<"\t";
	

}

int main(){

	int n;
	cout<<"Enter no of jobs: ";
	cin>>n;
	struct job job_arr[n+1];
	for(int i = 0; i < n; i++){
		cout<<"Enter details of job "<<(i+1)<<"_ _ _"<<endl;
		cout<<"Id: ";
		cin>>job_arr[i].id;
		cout<<"Profit: ";
		cin>>job_arr[i].profit;
		cout<<"Deadline: ";
		cin>>job_arr[i].deadline;
	}
	jobSequence(job_arr,n);
	// int* ptr = jobSequence(job_arr, n);
	// while(ptr){
	// 	cout<<&ptr<<"\t";
	// }

	return 0;
}