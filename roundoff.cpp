#include <iostream>
#include <math.h>
using namespace std;

int roundof(int x){
    if(x/10 == 0 && x%10 < 5) return x;
    else if(x/10 == 0 && x%10 >= 5) return 10;
    if(x%10 >= 5){
        x = x - x%10 + 10;
        roundof(x/10);
    }
    return x;
}

int main(){
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin>>x;
        //int nod = log10x + 1;
        int k = x;
        int dummy = x;
        int ans = 0;
        while(log10k+1 > 0){
            log10k--;
            if(dummy%10 >= 5 && dummy%10 < 9){
                dummy = dummy - dummy%10 + 10;
                ans = max(ans,dummy);
                dummy/=1
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}