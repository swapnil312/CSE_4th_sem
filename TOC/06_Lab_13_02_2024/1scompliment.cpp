//1s complement
# include <iostream>
# include <bits/stdc++.h>
using namespace std;

string moore(string str)
{
    int cst = 0;
    string ans = "";
    int tt[2][3] = {
        {1,0,0},
        {1,0,1}
    };
    int l = str.length();
    for(int i = 0; i < l; i++)
    {
        ans += to_string(tt[cst][2]);
        cst = tt[cst][str[i]-'0'];
    }
    ans += to_string(tt[cst][2]);
    return ans;
}

string mealy(string str)
{
    int cst = 0;
    string ans = "";
    int tt[1][4] = {
        {0,0,1,0}
    };
    int l = str.length();
    for(int i = 0; i < l; i++)
    {
        cst = tt[cst][str[i]-'0'];
        ans += to_string(tt[cst][(str[i] - '0')+2]);
    }
    return ans;
}

int main()
{
    string str;
    cout<<"Enter string: ";
    cin>>str;
    cout<<"Mooore: "<<moore(str)<<endl;
    cout<<"Mealy: "<<mealy(str)<<endl;
    return 0;
}