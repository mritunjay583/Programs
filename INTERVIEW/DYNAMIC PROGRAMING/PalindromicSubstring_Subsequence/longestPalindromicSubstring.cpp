#include <bits/stdc++.h>

// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
using namespace std;

////space complexity O(1)
//////////////////////////////////////////////////////////////////////////////////
void palindromes(int low, int high, string input, int &MAX_LEN, int start)
{
    int n = input.size();
    while (low >= 0 && high < n && input[low] == input[high])
    {
        if (MAX_LEN < (high - low + 1))
        {
            MAX_LEN = high - low + 1;
            start = low;
        }
        low--;
        high++;
    }
}

int longestPalindromicSubstring_2(string input)
{
    int MAX_LEN = 1;
    int start = 0;
    int n = input.size();
    int low, high;

    //consider one by one each character as center point of odd and even length palindromes
    for (int i = 1; i < n; i++)
    {

        //for even length palindromes
        low = i - 1;
        high = i;
        palindromes(low, high, input, MAX_LEN, start);

        //for odd length palindromes
        low = i - 1;
        high = i + 1;
        palindromes(low, high, input, MAX_LEN, start);
    }

    cout << "length of longest palindromic substring is : " << MAX_LEN << endl;
    for (int i = start; i < start + MAX_LEN; i++)
    {
        cout << input[i];
    }
    cout << endl;
}
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
//time complexity O(n*n) and space O(n*n)
int longestPalindromicSubstring(string input)
{
    int MAX_LEN = 1;
    int start = 0;
    int n = input.size();
    bool dp[input.size()][input.size()]; // dp matrix which stores T/F according to string from i to j
                                         //is palindrome or not
    //intialization
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = false;
        }
    }

    //string of length 1 will be palindrome
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    //store value if two digit string if it is palindrome or not
    for (int i = 0; i < n - 1; i++)
    {
        if (input[i] == input[i + 1])
        {
            dp[i][i + 1] = true;
            if (MAX_LEN < 2)
            {
                MAX_LEN = 2;
                start = i;
            }
        }
    }

    //checking and store result of all substring of length greater than 2 in dp matrix
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (dp[i + 1][j - 1] == true && input[i] == input[j])
            {
                dp[i][j] = true;
                if (k > MAX_LEN)
                {
                    MAX_LEN = k;
                    start = i;
                }
            }
        }
    }
    cout << "length of longest palindromic substring is : " << MAX_LEN << endl;
    for (int i = start; i < start + MAX_LEN; i++)
    {
        cout << input[i];
    }
    cout << endl;
}

int main()
{
    string input = "aaaabbaa";
    longestPalindromicSubstring(input);
    longestPalindromicSubstring_2(input);
}