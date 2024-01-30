// Take input of alphabet set, then take input a string and check if it is valid or not
# include <iostream>
# include <cstring>
using namespace std;
int check_string(string str, char* alpha)
{
    int l = str.length();
    if(l == 0)
    {
        return 1;
    }
    int l_alpha = strlen(alpha);
    
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
int main()
{
    int x;
    cout<<"Enter number of alphabets: ";
    cin>>x;
    char alpha[x];
    for(int i = 0; i < x; i++)
    {
        cout<<"Enter alphabet "<<(i+1)<<": ";
        cin>>alpha[i];
    }
    string str = "";
    cout<<"\nEnter string: ";
    cin>>str;
    if(check_string(str, alpha))
    {
        cout<<str<<" is accepted.";
    }
    else
    {
        cout<<str<<" is not accepted.";
    }
    
    return 0;
}