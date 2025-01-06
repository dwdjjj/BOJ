#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

// input ?òà?†ú
// hello
// raccecar
// Í∏∞Îü¨Í∏?
// ?Ü†ÎßàÌÜ†
// kayak
// aa#$4$#aa
// 1234567
// 00110101100

// ???Ïπ?Î¨∏Ïûê?ó¥?ôï?ù∏
int main()
{
    string s;
    ifstream file("q1_Input.txt");

    vector<bool> ans;

    if (file.is_open())
    {
        while (getline(file, s))
        {
            vector<char> front;
            vector<char> back;
            bool flag = true;
            for (int i = 0; i < s.size() / 2; i++)
            {
                front.push_back(s[i]);
            }
            for (int i = s.size() - 1; i >= 0; i--)
            {
                back.push_back(s[i]);
            }

            for (int i = 0; i < s.size() / 2; i++)
            {
                if (front[i] != back[i])
                {
                    flag = false;
                    break;
                }
            }

            ans.push_back(flag);
        }
        file.close();
    }
    else
    {
        cout << "∆ƒ¿œ¿ª ø≠ ºˆ æ¯Ω¿¥œ¥Ÿ.\n";
        return 0;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}