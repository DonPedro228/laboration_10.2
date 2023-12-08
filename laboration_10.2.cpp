#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int IfFileOpen(const string& filename)
{
    int A;
    ifstream F("t1.txt");
    if (!F)
    {
        cout << "Can`t open the file" << endl;
        A = 0;
    }
    else {
        A = 1;
    }
    return A;
}

void CopyStrings(const string& filename)
{
    ifstream t1(filename);
    char ch;
    cout << "Original string (File t1.txt):" << endl;
    while (t1.get(ch)) {
        cout << ch;
    }

    cout << endl;
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << endl;

    t1.close();
}


void RemoveSpaces(const string& filename) {
    ifstream t1(filename);
    ofstream t2("t2.txt");

    if (!t1.is_open() || !t2.is_open()) {
        cerr << "Unable to open files" << endl;
        exit(1);
    }

    cout << "Modificated string(File t2.txt):" << endl;

    char ch;
    bool space_Before_Punctuation = true;
    int space_Count_After_Punctuation = 0;

    while (t1.get(ch)) {
        if (ch == '.' || ch == ',' || ch == ':' || ch == ';' || ch == '-' || ch == '!') {
            space_Before_Punctuation = false;
            t2 << ch;
            cout << ch;
        }
        else if (ch == ' ' && space_Before_Punctuation) {
            continue;
        }
        else if (ch == ' ' && !space_Before_Punctuation) {
            space_Count_After_Punctuation++;
        }
        else {
            space_Before_Punctuation = true;
            t2 << string(space_Count_After_Punctuation, ' ') << ch;
            cout << string(space_Count_After_Punctuation, ' ') << ch;
            space_Count_After_Punctuation = 0;  
        }
    }

    t1.close();
    t2.close();
}



int main()
{
    string filename = "t1.txt";

    IfFileOpen(filename);

    CopyStrings(filename);

    RemoveSpaces(filename);

    cout << endl;

    return 0;
}