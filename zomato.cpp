#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
// Will be solved more efficiently through the use of Disjoint Set
// Function to find the minimum operations needed to convert an array to a palindrome
int minOperationsToPalindrome(vector<int> &arr)
{
    map<int, int> r;
    int n = arr.size();
    int left = 0, right = n - 1;
    int operations = 0;

    for(int x : arr){
        r[x] = x;
    }
    while (left < right)
    {
        if (r[arr[left]] != r[arr[right]])
        {
            operations++;
            r[arr[right]] = r[arr[left]];
        }
        left++;
        right--;
    }

    return operations;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> data(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    int result = minOperationsToPalindrome(data);
    cout << "Minimum operations needed: " << result << endl;

    return 0;
}
