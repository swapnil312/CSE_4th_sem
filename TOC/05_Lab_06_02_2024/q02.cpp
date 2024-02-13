//WAP to implement NFA to accept strings starting with 1 and ending with 0
# include <iostream>
# include <cstring>
# include <vector>
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

int isAccepted(string str)
{
    int l = str.length();
    vector <int> cst;
    cst.push_back(0);
    for(int i = 0; i < l; i++)
    {
        int size = cst.size();
        for(int j = 0; j < size; j++)
        {
            if(str[i] == '0')
            {
                if(cst[j] == 0)
                {
                    cst.erase(cst.begin()+j);
                    
                }
                else if(cst[j] == 1)
                {
                    cst.push_back(2);
                }
                else if(cst[j] == 2)
                {
                    cst.erase(cst.begin()+j);
                }
            }
            else if(str[i] == '1')
            {
                if(cst[j] == 0)
                {
                    cst.push_back(1);
                }
                else if(cst[j] == 1)
                {
                    // cst.erase(cst.begin()+j);
                }
                else if(cst[j] == 2)
                {
                    cst.erase(cst.begin()+j);
                }
            }
            else
            {
                return 0;
            }
            
        }
    }
    for(int i = 0; i < cst.size(); i++)
    {
        if(cst[i] == 2)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    
    if((isAccepted(str))&&(isValid(str)))
    {
        cout<<str<<" is accepted.";
    }
    else
    {
        cout<<str<<" is not accepted.";
    }
    return 0;
}