#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

vector<string> file1Lines;
vector<string> file2Lines;
mutex mtx;
condition_variable cv;
bool file1Flag = false;
bool file2Flag = false;

void readFile(const string &fileName, vector<string> &line, bool &readFlag)
{
    ifstream infile(fileName);
    if (!infile.is_open())
    {
        cerr << "Error opening file: " << fileName << "\n";
        return;
    }

    string s;
    while (getline(infile, s))
    {
        lock_guard<mutex> lock(mtx);
        line.push_back(s);
    }
    {
        lock_guard<mutex> lock(mtx);
        readFlag = true;
    }
    cv.notify_all();
}

void writeFile(const string &outputFile)
{
    ofstream outfile(outputFile);
    if (!outfile.is_open())
    {
        cerr << "Error creating output file: " << outputFile << "\n";
        return;
    }

    while (true)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []
                { return file1Flag && file2Flag; });

        unsigned int file1Index = 0, file2Index = 0;
        bool firstWordInLine = true; // 문장의 첫 단어인지 체크(쓸데없는 공백 없도록)

        while (file1Index < file1Lines.size() || file2Index < file2Lines.size())
        {
            if (file1Index < file1Lines.size())
            {
                string file1Line = file1Lines[file1Index++];

                if (file1Line.empty())
                {
                    outfile << "\n";
                    firstWordInLine = true; // 줄을 바꾼 경우 첫 단어임을 명시
                }
                else
                {
                    if (!firstWordInLine) // 첫단어가 아니라면
                    {
                        outfile << " "; // 공백 추가
                    }
                    outfile << file1Line;
                    firstWordInLine = false; // 첫 단어를 넘겼다면 이후에는 공백 계속 추가하기 위해 false로
                }
            }

            if (file2Index < file2Lines.size())
            {
                string file2Line = file2Lines[file2Index++];

                if (file2Line.empty())
                {
                    outfile << "\n";
                    firstWordInLine = true;
                }
                else
                {
                    if (!firstWordInLine)
                    {
                        outfile << " ";
                    }
                    outfile << file2Line;
                    firstWordInLine = false;
                }
            }
        }

        break; // 다 작성했으면 나오기
    }
}

int main()
{
    const string file1 = "file1.txt";
    const string file2 = "file2.txt";
    const string output = "output.txt";

    thread reader1(readFile, file1, ref(file1Lines), ref(file1Flag));
    thread reader2(readFile, file2, ref(file2Lines), ref(file2Flag));
    thread writer(writeFile, output);

    reader1.join();
    reader2.join();
    writer.join();

    cout << "이미 출력파일이 존재합니다." << output << "\n";
    return 0;
}
