// Power of a string
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

string power(string str, int power)
{
    int x = 0;
    string s = "";
    for(int i = 0; i < power; i++)
    {
        s+=str;
    }
    return s;
}

int main()
{
    string str = "";
    cout<<"\nEnter string: ";
    cin>>str;
    if(check_string(str)){}
    else
    {
        cout<<str<<" is not accepted.";
        return -1;
    }
    int p;
    cout<<"Enter power: ";
    cin>>p;
    string ans = power(str,p);
    cout<<"Resultant string is "<<ans<<endl;
    return 0;
}