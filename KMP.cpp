#include "KMP.h"

using namespace std;

vector<int> GetNext(const string& pattern)
{
    vector<int> next(pattern.size(), 0);
    int j = 0;
    for (int i = 1; i < pattern.size(); i++)
    {
        while (j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
        if (pattern[i] == pattern[j]) j++;
        next[i] = j;
    }
    return next;
}

vector<int> KMP(const string& text, const string& pattern)
{
    vector<int> next = GetNext(pattern);
    int j = 0;
    vector<int> positions;
    for (int i = 0; i < text.size(); i++)
    {
        while (j > 0 && text[i] != pattern[j]) j = next[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == pattern.size())
        {
            positions.push_back(i - j + 1);
            j = next[j - 1];  // backtrack to allow overlapping matches
        }
    }
    return positions;
}
