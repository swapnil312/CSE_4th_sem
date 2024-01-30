// Concatenation of two strings (Language = {0,1})
# include <iostream>
# include <cstring>
using namespace std;
int check_string(string str)
{
    int l = str.length();
    if(l == 0)
    {
        return 1;
    }
    int l_alpha = 2;
    char alpha[2] = {'0', '1'};
    
    for(int i = 0; i < l; i++)
    {
        int flag = 0;
        char c = str[i];
        for(int j = 0; j < l_alpha; j++)
        {            
            if(c == alpha[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            return 0;
        }
    }
    return 1;

}

string concat(string str1, string str2)
{
    int l1 = str1.length();
    int l2 = str2.length();
    string str3 = "";
    for(int i = 0; i < l1; i++)
    {
        str3+=str1[i];
    }
    for(int i = 0; i < l2; i++)
    {
        str3+=str2[i];
    }
    return str3;

}
int main()
{

    string str1 = "";
    cout<<"\nEnter string 1: ";
    cin>>str1;
    if(check_string(str1))
    {
        // cout<<str<<" is accepted.";
    }
    else
    {
        cout<<str1<<" is not accepted.";
        return -1;
    }
    string str2 = "";
    cout<<"\nEnter string 2: ";
    cin>>str2;
    if(check_string(str2))
    {
        // cout<<str<<" is accepted.";
    }
    else
    {
        cout<<str2<<" is not accepted.";
        return -1;
    }
    string str = concat(str1, str2);
    cout<<"Concatenated string is "<<str;
    return 0;
}