# include <bits/stdc++.h>
using namespace std;

void print_array(int *ptr, int n){
    for(int i = 0; i < n; i++){
        int  *r = ptr;
        for(int j = 0; j < n; j++){
            cout<<*r<<"\t";
        }
        cout<<endl;
    }
}


void matrix_multiplication(int p[],int x){
    int n = x-1;
    int m[n+1][n+1];
    int s[n+1][n+1];
    for(int i = 0; i <= n; i++){
        m[i][i] = 0;
        s[i][i] = 0;
        m[0][i] = 0;
        s[0][i] = 0;
        m[i][0] = 0;
        s[i][0] = 0;
        int x = i;
        while(x > 0){
            m[i][x] = 0;
            s[i][x] = 0;
            x--;    
        }
    }
    for(int l = 1; l <= n-1; l++){
        for(int i = 1; i <= n-l; i++){
            int j = i+l;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j-1; k++){
                int q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout<<endl<<"Matrix for no of scalar multiplications..."<<endl;
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++) cout<<m[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"\n\n\n";
    cout<<"Matrix for finding partition..."<<endl;
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            cout<<s[i][j]<<"\t";
        }
        cout<<endl;
    }
    

}

int main(){

    int noOfMtrcs = 0;
    cout<<"Enter no of matrices: ";
    cin>>noOfMtrcs;
    int p[noOfMtrcs+1];
    for(int i = 0; i <= noOfMtrcs; i++){
        if(i == 0){ 
            cout<<"Enter no of rows for matrix "<<i+1<<": ";
            cin>>p[i];
        }
        else if(i == noOfMtrcs){
            cout<<"Enter no of coulmns for matrix "<<i<<": ";
            cin>>p[i];
        }
        else{
            cout<<"Enter no of coulmns for matrix "<<i<<" and no of rows for matrix "<<i+1<<": ";
            cin>>p[i];
        }
    }
    matrix_multiplication(p,noOfMtrcs+1);
    return 0;
}