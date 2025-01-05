class Solution
{
public:
    string shiftingLetters(string &s, vector<vector<int>> &shifts)
    {
        char forward[26];
        int n = s.length();
        cout << n << endl;
        for (int i = 0; i < 26; i++)
        {
            forward[i] = 'a' + (i + 1) % 26;
        }
        char backward[26];
        // whenever using negatuve + mod always add the number through which we are modding because
        // % also outputs negative numbers.
        for (int i = 0; i < 26; i++)
        {
            backward[i] = 'a' + (i - 1 + 26) % 26;
        }
        vector<int> flips(n + 1, 0);
        for (const auto &x : shifts)
        {
            int start = x[0];
            int end = x[1];
            if (start == end)
            {
                if (x[2])
                {
                    if (s[start] != 'z')
                    {
                        s[start] = s[start] + 1;
                    }
                    else
                        s[start] = 'a';
                }
                else
                {
                    if (s[start] != 'a')
                    {
                        s[start] = s[start] - 1;
                    }
                    else
                        s[start] = 'z';
                }
            }
            else if (x[2])
            {
                flips[start]++;
                flips[end + 1]--;
            }
            else
            {
                flips[start]--;
                flips[end + 1]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            flips[i + 1] += flips[i] %= 26;
        }
        for (int i = 0; i < n; i++)
        {
            if (flips[i] > 0)
            {
                s[i] = 'a' + (s[i] - 'a' + flips[i]) % 26;
            }
            else
            {
                s[i] = 'a' + (s[i] - 'a' + flips[i] + 26) % 26;
            }
        }
        return s;
    }
};