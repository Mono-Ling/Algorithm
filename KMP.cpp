#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> KMP(string text, string pattern);
vector<int> GetNext(string pattern);
int main()
{
    string pattern = "aabaaf";
    string text = "aabaabaafaabbaabaaf";
    vector<int> positions = KMP(text, pattern);
    for(int pos : positions)
    {
        cout << "Pattern found at index: " << pos << endl;
    }
    return 0;
}
vector<int> KMP(string text, string pattern)
{
    vector<int> next = GetNext(pattern);
    int j = 0;
    vector<int> positions;
    for(int i=0;i<text.size();i++)
    {
        while(j > 0 && text[i] != pattern[j]) j = next[j - 1];
        if(text[i] == pattern[j]) j++;
        //if(j == pattern.size()) positions.push_back(i - j + 1);
        if(j == pattern.size()) 
        {
            positions.push_back(i - j + 1);
            j = next[j - 1];  // 让 j 回退，允许寻找重叠匹配
        }
    }
    return positions;
}
vector<int> GetNext(string pattern)
{
    vector<int> next(pattern.size(),0);
    int j = 0;
    for(int i=1;i<pattern.size();i++)
    {
        while(j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
        if(pattern[i] == pattern[j]) j++;
        next[i] = j;
    }
    return next;
}
