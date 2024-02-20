# include <bits/stdc++.h>
using namespace std;

void mealy_to_moore()
{
    int cst = 0;
    
    int states;
    cout<<"Please input for Mealy transition table..."<<endl;
    cout<<"Enter number of states: ";
    cin>>states;
    int tt_mealy[states][4];
    
    for(int i = 0; i < states; i++)
    {
        cout<<"Enter for state "<<i<<endl;
        for(int j = 0; j < 2; j++)
        {
            cout<<"When "<<j<<", state: ";
            cin>>tt_mealy[i][j];
            cout<<"When "<<j<<", output(0/1): ";
            cin>>tt_mealy[i][j+2];
        }
    }
    
    int tt_moore[2*states][3];
    for(int i = 0; i < 2*states; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tt_moore[i][j] = -1;
        }
    }
    
    for(int i = 0; i < states; i++)
    {
        if(tt_mealy[i][2] == 0)
        {
            tt_moore[2*i][0] = tt_mealy[i][0];
            
        }
        if(tt_mealy[i][2] == 1)
        {
            tt_moore[(2*i)+1][0] = tt_mealy[i][0];
            
        }
        if(tt_mealy[i][3] == 0)
        {
            tt_moore[2*i][1] = tt_mealy[i][1];

        }
        if(tt_mealy[i][3] == 1)
        {
            tt_moore[(2*i)+1][1] = tt_mealy[i][1];
        }
        tt_moore[2*i][2] = 0;
        tt_moore[(2*i)+1][2] = 1;
    }

    {
        cout<<"Transition table of Moore Machine_ _ _"<<endl;
        cout<<"States  0\t1\tOutput"<<endl;
    }

    for(int i = 0; i < 2*states; i++)
    {
        if((tt_moore[i][0] == -1)&&(tt_moore[i][1] == -1)) continue;
        if(i%2 == 0) cout<<i/2<<"\t";
        else cout<<i/2<<"\'\t";
        if(tt_moore[i][2] == 0)
        {
            if(tt_moore[i][0] == -1)
            cout<<tt_moore[i+1][0]<<"\'\t"<<tt_moore[i][1]<<"\t"<<tt_moore[i][2];
            else if(tt_moore[i][1] == -1)
            cout<<tt_moore[i][0]<<"\t"<<tt_moore[i+1][1]<<"\'\t"<<tt_moore[i][2];
            else
            cout<<tt_moore[i][0]<<"\t"<<tt_moore[i][1]<<"\t"<<tt_moore[i][2];

        }
        else if(tt_moore[i][2] == 1)
        {
            if(tt_moore[i][0] == -1)
            cout<<tt_moore[i-1][0]<<"\t"<<tt_moore[i][1]<<"\'\t"<<tt_moore[i][2];
            else if(tt_moore[i][1] == -1)
            cout<<tt_moore[i][0]<<"\'\t"<<tt_moore[i-1][1]<<"\t"<<tt_moore[i][2];
            else
            cout<<tt_moore[i][0]<<"\t"<<tt_moore[i][1]<<"\t"<<tt_moore[i][2];
        }
        cout<<endl;
    }
    
}

int main()
{
    mealy_to_moore();
    return 0;
}