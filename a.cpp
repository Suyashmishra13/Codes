#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int size;
        cin>>size;
        int arr[size];
        for (int j = 0; j < size; j++)
        {
            cin>>arr[j];
        }
        int noe=0;
        int nod=0;
        for (int k = 0; k < size; k++)
        {
            if(arr[k]%2 == 0){
                noe++;
            }
            else nod++;
        }
        nod = nod%2;
        if (nod == 0)
        {
            cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl;
        
    }
    
    return 0;
}