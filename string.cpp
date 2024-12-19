#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int length;
        cin>>length;
        string a[length];
        string b[length];
        cin>>string b;
        for (int k = 0; k < length; k++)
        {
            for (int j = 0; j < length; j++)
            {
                if (b[k] == b[j] || k!=j)
                {
                    cout<<b[i];
                }
                else{
                    continue;
                }
                
            }
            
            
        }
        
    }
    
    return 0;
}