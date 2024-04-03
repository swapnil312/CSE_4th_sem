# include <bits/stdc++.h>
using namespace std;

class job{
    public:
    int id;
    int start;
    int end;
};

bool compare(job j1, job j2){
    return j1.end < j2.end;
}

vector<int> activity_selection(job job_arr[], int size){
    sort(job_arr, job_arr+size, compare);
    vector<int> ans;
    int j = 0;
    ans.push_back(job_arr[j].id);
    for(int i = 1; i < size; i++){
        if(job_arr[i].start >= job_arr[j].end){
            j = i;
            ans.push_back(job_arr[j].id);
            
        }
    }
    return ans;
}

int main(){
    int size;
    cout<<"Enter no of activities: ";
    cin>>size;
    job job_arr[size];
    for(int i = 0; i < size; i++){
        // job jb;
        job_arr[i].id = i+1;
        cout<<"Enter starting time of job "<<(i+1)<<": ";
        cin>>job_arr[i].start;
        cout<<"Enter ending time of job "<<(i+1)<<": ";
        cin>>job_arr[i].end;
    }
    vector<int> ans = activity_selection(job_arr,size);
    cout<<"_ _ _ Selected Activities _ _ _"<<endl;
    for(auto id : ans) cout<<id<<"\t";    return 0;
}