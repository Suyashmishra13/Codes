#include <iostream>
using namespace std;

int main(){
    int Testcases;
    cin>> Testcases;
    for (int t = 0; t < Testcases; t++)
    {
        int n;
        cin>>n;
        if (n==2||n==3||n==4)
        {
            cout<<"Bob"<<endl;
        }
        else if(n>=4&&n<=100) cout<<"Alice"<<endl;
        
    }
    
    return 0;
}