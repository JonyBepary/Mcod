// Task: Pattern matching.
// Alogorithm: 2nd Method / KMP.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> lps_array(string pattern)
{
    vector<int> arra(pattern.length());
    int index = 0;
    for (int i = 1; i < pattern.length();)
    {
        if (pattern[i] == pattern[index])
        {
            arra[i] = index + 1;
            i++;
            index++;
        }
        else
        {
            if (index != 0)
                index = arra[index - 1];
            else
            {
                arra[i] = index;
                i++;
            }
        }
    }
    return arra;
}

int kmpsearch(string mainstr, string pattern)
{
    vector<int> lps = lps_array(pattern);
    int flag = 0;
    int occurence = 0;
    for (int j = 0, i = 0; i < mainstr.length();)
    {
        if (mainstr[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == pattern.length())
        {
            occurence++;
            flag = 1;
        }
    }
    return occurence;
}

int main(int argc, char const *argv[])
{
    string mainstr, pattern;

    getline(cin, mainstr);
    getline(cin, pattern);

    if (kmpsearch(mainstr, pattern))
    {
        cout << "The pattern \"" << pattern << "\" occured " << kmpsearch(mainstr, pattern) << " times."
             << endl;
    }
    else
        cout << "Pattern not occured\n";

    return 0;
}
