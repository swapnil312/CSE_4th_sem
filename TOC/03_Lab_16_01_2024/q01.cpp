// DFA to accept all possible combinations of strings
# include <iostream>
# include <cstring>
using namespace std;
int dfa = 0;
void q0(char x)
{
    if(x == '0')
    {
        dfa = 0;
    }
    else if(x == '1')
    {
        dfa = 0;
    }
    else
    {
        dfa = -1;
    }
}
int isAccepted(string str)
{
    int l = str.length();
    for(int i = 0; i < l; i++)
    {
        if(dfa == 0)
        {
            q0(str[i]);
        }
        else
        {
            return 0;
        }
    }
    if(dfa == 0)
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
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    if(isAccepted(str))
    {
        cout<<str<<" is accepted.";
    }
    else
    {
        cout<<str<<" is not accepted";
    }
    return 0;
}