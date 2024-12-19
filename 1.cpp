#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin>> n;
        int a[n];
        for (int k = 0; k < n; k++)
        {
            cin>> a[k];
        }

        cout << a[0] << endl;
    }
    
    return 0;
}