#include<iostream>
#include<vector>
#include<string>
#include "KMP.h"
using namespace std;
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