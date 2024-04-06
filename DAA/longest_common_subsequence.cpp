# include <bits/stdc++.h>
using namespace std;

string print_lcs(vector<vector<string>> arr2, int i, int j,string str1){
    string lcs = "";
    if(arr2[i][j] == "\\"){
        return print_lcs(arr2, i-1, j-1, str1) +  str1[i-1];
    }
    else if(arr2[i][j] == "--"){
        return print_lcs(arr2, i, j-1, str1);
    }
    else if(arr2[i][j] == "|"){
        return print_lcs(arr2, i-1, j, str1);
    }
    else if((i==0) || (j == 0)){
        return "";
    }
}

string lcs(string str1, string str2){
    int l1 = str1.length();
    int l2 = str2.length();
    vector<vector<int>> arr1(l1+1, vector<int>(l2+1,0));
    vector<vector<string>> arr2(l1+1, vector<string>(l2+1,""));
    for(int i = 0; i <= l2; i++){
        arr1[0][i] = 0;
        arr2[0][i] = "~";
    }
    for(int i = 0; i <= l1; i++){
        arr1[i][0] = 0;
        arr2[i][0] ="~";
    }
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(str1[i-1] == str2[j-1]){
                arr1[i][j] = arr1[i-1][j-1] + 1;
                arr2[i][j] = "\\";
            }
            else{
                if(arr1[i-1][j] >= arr1[i][j-1]){
                    arr1[i][j] = arr1[i-1][j];
                    arr2[i][j] = "|";
                }
                else{
                    arr1[i][j] = arr1[i][j-1];
                    arr2[i][j] = "--";
                }
            }
        }
    }

    // for(int i = 0; i <= l1; i++){
    //     for(int j = 0; j <= l2; j++){
    //         cout<<arr1[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // for(int i = 0; i <= l1; i++){
    //     for(int j = 0; j <= l2; j++){
    //         cout<<arr2[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    cout<<endl;
    cout<<"Longest common subsequence = "<<print_lcs(arr2, l1, l2, str1);
}

int main(){
    string str1,str2;
    cout<<"Enter first string: ";
    cin>>str1;
    cout<<"Enter second string: ";
    cin>>str2;
    lcs(str1,str2);


    return 0;
}
