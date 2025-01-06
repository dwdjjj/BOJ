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
bool file1Read = false;
bool file2Read = false;

void readFile(const string &filePath, vector<string> &lines, bool &readFlag)
{
    ifstream infile(filePath);
    if (!infile.is_open())
    {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    string line;
    while (getline(infile, line))
    {
        lock_guard<mutex> lock(mtx);
        lines.push_back(line);
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
        cerr << "Error creating output file: " << outputFile << endl;
        return;
    }

    while (true)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []
                { return file1Read && file2Read; });

        size_t file1Index = 0, file2Index = 0;

        bool firstWordInLine = true; // Flag to manage spaces correctly

        while (file1Index < file1Lines.size() || file2Index < file2Lines.size())
        {
            // Process file1 line
            if (file1Index < file1Lines.size())
            {
                string file1Line = file1Lines[file1Index++];

                // If file1 line is empty (i.e., a blank line), add a newline and skip space
                if (file1Line.empty())
                {
                    outfile << endl;
                }
                else
                {
                    if (!firstWordInLine)
                    {
                        outfile << " "; // Add a space between words
                    }
                    outfile << file1Line;
                    firstWordInLine = false; // After the first word, allow space to be added
                }
            }

            // Process file2 line
            if (file2Index < file2Lines.size())
            {
                string file2Line = file2Lines[file2Index++];

                // If file2 line is empty (i.e., a blank line), add a newline
                if (file2Line.empty())
                {
                    outfile << endl;
                }
                else
                {
                    if (!firstWordInLine)
                    {
                        outfile << " "; // Add a space between words
                    }
                    outfile << file2Line;
                    firstWordInLine = false; // After the first word, allow space to be added
                }
            }
        }

        break; // Exit the loop after writing all lines
    }
}

int main()
{
    const string file1 = "file1.txt";
    const string file2 = "file2.txt";
    const string output = "output.txt";

    thread reader1(readFile, file1, ref(file1Lines), ref(file1Read));
    thread reader2(readFile, file2, ref(file2Lines), ref(file2Read));
    thread writer(writeFile, output);

    reader1.join();
    reader2.join();
    writer.join();

    cout << "Merged file has been written to " << output << endl;
    return 0;
}
