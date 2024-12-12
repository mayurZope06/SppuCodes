// Write a C++ program that creates an output file, writes information to it, 
// closes the file, open it again as an input file and read the information from the file.

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream myFile; //object of fstream class

    //opening file "sample.txt" in out(write) mode
    myFile.open("sample.txt", ios :: out);

    if (!myFile)
    {
        cout<<"Error in creating file!!!"<<endl;
        return 0;
    }

    cout<<"File created successfully!"<<endl;
    //write text into file

    myFile << "ABCD";
    //closing the file

    myFile.close();

    //again open file in read mode
    myFile.open("sample.txt", ios :: in);

    if (!myFile)
    {
        cout<<"Error in opening file!!!"<<endl;
        return 0;
    }

    //read until end of file is not found.
    string str; //to read single character
    cout<< "File content: ";

    while(!myFile.eof())
    {
        myFile >> str; // read single character from file
        cout << str;
    }

    myFile.close(); //close file
    cout<<endl;
    
    return 0;
}

// OR

// C++ program to write and read text in/from file.
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream file; // object of fstream class

    // opening file "sample.txt" in out(write) mode
    file.open("sample.txt", ios::out);

    if (!file)
    {
        cout << "Error in creating file!!!" << endl;
        return 0;
    }

    cout << "File created successfully!" << endl;
    // write text into file
    file << "ABCD.";
    // closing the file
    file.close();

    // again open file in read mode
    file.open("sample.txt", ios::in);

    if (!file)
    {
        cout << "Error in opening file!!!" << endl;
        return 0;
    }

    // read untill end of file is not found.
    char ch; // to read single character
    cout << "File content: ";

    while (!file.eof())

    {
        file >> ch; // read single character from file
        cout << ch;
    }

    file.close(); // close file
    cout << endl;
    return 0;
}
