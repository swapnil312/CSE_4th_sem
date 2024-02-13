// NFA to DFA ====> 110 as substring
# include <iostream>
# include <cstring>
# include <cmath>
using namespace std;

int check_presence(string s1, string arr[], int l)
{
    for(int i = 0; i < l; i++)
    {
        if(s1 == arr[i])
        {
            return 1;
        }
    }
    return 0;

}

string remove_duplicate(string str)
{
    int l = str.length();
    string str1 = "";
    int flag = 0;
    int l_ans = str1.length();
    for(int i = 0; i < l; i++)
    {
        flag = 0;
        for(int j = 0; j < l_ans; j++)
        {
            if(str[i] == str1[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            str1 = str1 + str[i];
            l_ans++;
        }
    }
    return str1;
}


int main()
{
    int n_states;
    cout<<"Enter no of states: ";
    cin>>n_states;
    string nfa_tt[n_states][3];
    for(int i = 0; i < n_states; i++)
    {
        cout<<"Enter state: ";
        cin>>nfa_tt[i][0];
        for(int j = 1; j <= 2; j++)
        {
            cout<<"Enter transition from "<<nfa_tt[i][0]<<" when input is "<<j-1<<
        }

    }
    string nfa_tt[4][3] = {
        {"0","0", "01"},
        {"1","", "2"},
        {"2","3", ""},
        {"3","3", "3"}
    };
    int x = pow(2,4);
    int t = 0;
    string states[x];
    string dfa_tt[x][3];
    
    for(int i = 0; i < x; i++)
    {
        if(i == 0)
        {
            dfa_tt[0][0] = nfa_tt[0][0];
            dfa_tt[0][1] = nfa_tt[0][1];
            dfa_tt[0][2] = nfa_tt[0][2];
            states[i] = nfa_tt[i][0];
            t++;            
        }
        else
        {
            for(int j = 1; j <= 2; j++)
            {
                if(!check_presence(dfa_tt[i-1][j], states, x))
                {
                    string st = dfa_tt[i-1][j];
                    string val1 = "";
                    string val2 = "";
                    int l = st.length();
                    for(int k = 0; k < l; k++)
                    {
                        val1 = val1+nfa_tt[st[k]-'0'][1];
                        val2 = val2+nfa_tt[st[k]-'0'][2];
                        val1 = remove_duplicate(val1);
                        val2 = remove_duplicate(val2);
                    }
                    dfa_tt[i][0] = st;
                    states[i] = st;
                    t++;
                    dfa_tt[i][1] = val1;
                    dfa_tt[i][2] = val2;
                }
            }
        }
    }
    cout<<endl<<"Transition table of DFA _ _ _"<<endl;
    cout<<"State"<<"  "<<"\'0\' "<<"\t"<<"\'1\' "<<endl;
    for(int i = 0; i < t; i++)
    {
        cout<<dfa_tt[i][0]<<"\t"<<dfa_tt[i][1]<<"\t"<<dfa_tt[i][2]<<endl;
    }

    return 0;
}