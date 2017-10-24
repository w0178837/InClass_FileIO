#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//  Notes:
//  to read/write a file you need to connect to a stream object
//  << insertion operator
//  >> extraction operator
//  If you create a text file in the same dir as the cpp, the compiler will
//  find it. In another location, it will not.
//  Close files/streams when done.
//


// prototypes
void demoOpenCloseStreams();
void demoOpenPrint();
void demoOpenWrite();

// begin main
int main() {

    demoOpenCloseStreams();
    cin.ignore();

    demoOpenPrint();
    cin.ignore();

    demoOpenWrite();
    cin.ignore();


    return 0;
}

void demoOpenCloseStreams(){
    cout << "Files Open" << endl;
    // declare stream objects
    ifstream inStream;
    ofstream outStream;

    //connect files to the streams
    inStream.open("InFile.txt");
    outStream.open("OutFile.txt");

    ifstream inStream2("InFile.txt"); // declared and connected in one line

    // use them, then close them

    inStream.close();
    inStream2.close();
    outStream.close();

    cout << "Files Closed" << endl;

}


// validate open state of a file using fstream.fail
void demoOpenPrint(){
    string line;
    ifstream myFileIn;

    myFileIn.open("../InFile.txt");

    //.fail() or .isopen() both work
    if(myFileIn.is_open())
    {
        cout << "It's open" << endl;
        while(!myFileIn.eof())
        {
            getline(myFileIn, line);
            cout << line << endl;
        }
        myFileIn.close();
        cout << "File closed";
    }else{
        cout << "Input file failed to open" << endl;
    }

}

void demoOpenWrite(){
    ofstream myFileOut;
    // to append to a file - use ios::app

    myFileOut.open("../OutFile.txt");

    if(myFileOut.is_open()){ //could also do myFileOut.fail to check inverse

        myFileOut << "Stuff" << "\nand more stuff" << endl;
        myFileOut.close();
        cout << "File closed" << endl;

    }else{
        cout << "File failed to open" << endl;
    }

}