#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

struct students
{
    string Name;
    int Roll;
    float Marks;
};

int main()
{
    ofstream onfile("struct_input.txt"); // for writing file

    if (!onfile)
    {
        cout << "Error file opening!" << endl;
        return 0;
    }

    onfile << "Name.......Roll.......Mark" << endl;

    while (1)
    {
        cout << "New studend details." << endl;
        cout << "Press enter to input or press esc to exit:" << endl;

        int ch;
        ch = getch();
        if (ch == 27)
        {
            break;
        }

        cout << "Enter Name: ";
        string Name;
        getline(cin, Name);

        cout << "Enter Roll: ";
        int Roll;
        cin >> Roll;

        cout << "Enter Mark: ";
        float Mark;
        cin >> Mark;

        cin.ignore();

        onfile << Name << " " << Roll << " " << Mark << endl;
    }

    onfile.close();
    cout << "file closed successfully" << endl;

    ifstream inFile("struct_input.txt"); // for reading file

    vector<students> v;

    if (!inFile)
    {
        cout << "Opening Error!" << endl;
    }

    string line;

    getline(inFile, line);

    students st;

    while (getline(inFile, line))
    {

        stringstream ss(line);

        string word;
        string name = "";

        //>> operator whitespace delimiter হিসাবে কাজ করে।

        while (ss >> word)
        {
            if (isdigit(word[0]))
            {
                st.Roll = stoi(word);
                break;
            }
            name += word + " ";
        }

        st.Name = name;
        ss >> st.Marks;

        v.push_back(st);

    }

    cout << "Sort by name press 1:" << endl;
    cout << "Sort by roll press 2:" << endl;
    cout << "Sort by mark press 3:" << endl;
    cout << "or" << endl;
    cout << "Search by name press 4:" << endl;
    cout << "Search by roll press 5:" << endl;
    cout << "Search by mark press 6:" << endl;

    int c;
    c = getch();

    switch (c)
    {
    case 49:
    {
        cout << endl
             << "Sort by Name......" << endl; // Lambda function for sorting
        sort(v.begin(), v.end(), [](students a, students b)
             { return a.Name < b.Name; });

        for (auto &s : v)
        {
            cout << s.Name << " " << s.Roll << " " << s.Marks << endl;
        }
    }
    case 50:
    {
        cout << endl
             << "Sort by Roll....." << endl;
        sort(v.begin(), v.end(), [](students a, students b)
             { return a.Roll < b.Roll; });

        for (auto &s : v)
        {
            cout << s.Name << " " << s.Roll << " " << s.Marks << endl;
        }
    }
    case 51:
    {
        cout << endl
             << "Sort By Marks......" << endl;

        sort(v.begin(), v.end(), [](students a, students b)
             { return a.Marks > b.Marks; });

        for (auto &s : v)
        {
            cout << s.Name << " " << s.Roll << " " << s.Marks << endl;
        }
    }
    case 52:
    {
        string key;
        cout << "Enter name to search: ";
        getline(cin, key);

        bool found = false;

        for (auto &s : v)
        {
            if (s.Name == key)
            {
                cout << "Found!\n";
                cout << s.Name << " " << s.Roll << " " << s.Marks << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Name not found!\n";

        break;
    }
    case 53:
    {
        int key;
        cout << "Enter roll to search: ";
        cin >> key;

        bool found = false;

        for (auto &s : v)
        {
            if (s.Roll == key)
            {
                cout << "Found!\n";
                cout << s.Name << " " << s.Roll << " " << s.Marks << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Roll not found!\n";
    }
    case 54:
    {
        float key;
        cout << "Enter marks to search: ";
        cin >> key;

        bool found = false;

        for (auto &s : v)
        {
            if (s.Marks == key)
            {
                cout << "Found!\n";
                cout << s.Name << " " << s.Roll << " " << s.Marks << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Marks not found!\n";
    }

    default:
        break;
    }

    inFile.close();
    cout << "File closing successfully." << endl;

    return 0;
}