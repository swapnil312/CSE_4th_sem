# include <bits/stdc++.h>
using namespace std;

void moore_to_mealy()
{
    int cst = 0;
    string ans = "";
    int states = 0;
    cout<<"_ _ _Input for Moore_ _ _"<<endl;
    cout<<"Enter number of states: ";
    cin>>states;
    int tt_moore[states][3];
    for(int i = 0; i < states; i++)
    {
        cout<<"Enter transitions for state "<<i<<endl;
        cout<<"When 0: ";
        cin>>tt_moore[i][0];
        cout<<"When 1: ";
        cin>>tt_moore[i][1];
        char ch;
        cout<<"Corresponding output: ";
        cin>>ch;
        tt_moore[i][2] = (int)ch;
    }
    
    int tt_mealy[states][4];
    for(int i = 0; i < states; i++)
    {
        tt_mealy[i][0] = tt_moore[i][0];
        tt_mealy[i][1] = tt_moore[i][1];
        tt_mealy[i][2] = tt_moore[tt_mealy[i][0]][2];
        tt_mealy[i][3] = tt_moore[tt_mealy[i][1]][2];
    }
    cout<<"Printing Mealy transition table_ _ _"<<endl;
    cout<<"States   "<<"[0]State  "<<"[0]Output "<<"[1]State  "<<"[1]Output"<<endl;
    for(int i = 0; i < states; i++)
    {
        cout<<i<<"\t "<<tt_mealy[i][0]<<"\t    "<<(char)tt_mealy[i][2]<<"\t      "<<tt_mealy[i][1]<<"\t       "<<(char)tt_mealy[i][3]<<endl;
        
    }
}


int main()
{
    moore_to_mealy();
    return 0;
}