#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to find the minimum operations needed to convert an array to a palindrome
int minOperationsToPalindrome(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = n - 1;
    int operations = 0;

    // Two-pointer approach to compare symmetric elements from both ends
    while (left < right)
    {
        if (arr[left] != arr[right])
        {
            operations++; // Increment the operation counter for mismatch
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
