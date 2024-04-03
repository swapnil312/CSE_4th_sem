# include <bits/stdc++.h>
using namespace std;

class Item{
    public:
    int id;
    int profit;
    int weight;
    double ratio;
};

bool compare(Item item1, Item item2){
    return (item1.ratio) > (item2.ratio);
}

pair<vector<int>, int> fractional_knapsack(Item item_arr[], int size, int capacity){
    pair<vector<int>, int> rtnpair;
    vector<int> ans;
    sort(item_arr,item_arr+size,compare);
    int current_weight = 0;
    float total_profit = 0.0;
    for(int i = 0; i < size; i++){
        if(item_arr[i].weight >= (capacity-current_weight)){
            current_weight += item_arr[i].weight;
            
            total_profit += item_arr[i].profit;
            // cout<<"Inside if (total profit) = "<<total_profit<<endl;
            ans.emplace_back(item_arr[i].id);
        }
        else{
            
            total_profit += (item_arr[i].ratio)*(capacity-current_weight);
            // cout<<"Inside else (total profit) = "<<total_profit<<endl;        
            ans.emplace_back(item_arr[i].id);
            break;
        }
    }
    rtnpair.first = ans;
    rtnpair.second = total_profit;
    return rtnpair;
}

int main(){

    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    Item item_arr[n];
    for(int i = 0; i < n; i++){
        Item item;
        item.id = i+1;
        cout<<"Enter profit of object "<<(i+1)<<": ";
        cin>>item.profit;
        cout<<"Enter weight of object "<<(i+1)<<": ";
        cin>>item.weight;
        item.ratio = ((double)item.profit)/((double)item.weight);
        item_arr[i] = item;
    }
    pair<vector<int>, int> ans = fractional_knapsack(item_arr,n,20);
    cout<<"Profit = "<<ans.second<<endl;
    for(auto id : ans.first){
        cout<<id<<endl;
    }
    // cout<<pair.second;


    return 0;
}