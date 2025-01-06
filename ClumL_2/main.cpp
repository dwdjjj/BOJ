#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

int main()
{
    string s;
    ifstream file("Q2_log sample");
    ofstream file2("output.txt");
    string find_str = "\t";
    string after_str = ",";
    vector<string> output;

    if (file.is_open())
    {
        while (getline(file, s))
        {
            // cout << s << "\n";
            s = regex_replace(s, regex(find_str), after_str);
            output.push_back(s);
        }
        file.close();
    }
    else
    {
        cout << "cannot open it.\n";
        return 0;
    }

    if (file2.fail())
        cout << "파일 쓰기 실패 \n";

    for (const string &str : output)
    {
        file2 << str << "\n";
    }

    return 0;
}