// NFA to DFA ====> ending with 00
# include <iostream>
# include <cstring>
# include <cmath>
using namespace std;
int isValid(string str)
{
    int f = 0;
    int l = str.length();
    for(int i = 0; i < l; i++)
    {
        if((str[i] == '0')||(str[i] == '1'))
        {
            f = 0;
        }
        else{
            f = 1;
            break;
        }
    }
    if(f == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

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

int isAccepted(string word)
{
    string state = "0";
    int l_w = word.length();
    for(int i = 0; i < l_w; i++)
    {
        if(state == "0")
        {
            if(word[i] == '0'){state = "0";}
            else if(word[i] == '1'){state = "01";}
        }
        else if(state == "01")
        {
            if(word[i] == '0'){state = "0";}
            else if(word[i] == '1'){state = "012";}
        }
        else if(state == "012")
        {
            if(word[i] == '0'){state = "03";}
            else if(word[i] == '1'){state = "012";}
        }
        else if(state == "03")
        {
            if(word[i] == '0'){state = "03";}
            else if(word[i] == '1'){state = "013";}
        }
        else if(state == "013")
        {
            if(word[i] == '0'){state = "03";}
            else if(word[i] == '1'){state = "0123";}
        }
        else if(state == "0123")
        {
            if(word[i] == '0'){state = "03";}
            else if(word[i] == '1'){state = "0123";}
        }
    }
    if((state == "03")||(state == "013")||(state == "0123"))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
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

    string word = "";
    cout<<endl<<"Enter a string: ";
    cin>>word;
    if(isValid(word)&&isAccepted(word))
    {
        cout<<word<<" is accepted";
    }
    else
    {
        cout<<word<<" is not accepted";
    }

    return 0;
}