#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<stdio.h>
#include<ctype.h>

using namespace std;

#pragma pack(push,1)
struct Person
{
    char Name[25];
    int age;
    double heightM;
};
#pragma pack(pop)

void enterFileContents(fstream &outFile,string fileName)
{
    string inputText;

    outFile.open(fileName,ios::out | ios::app);

    if(outFile.is_open())
    {
        do
        {
            cout<<"Enter text you would like to write to file";
            std::getline(std::cin >> std::ws, inputText);
            outFile<<inputText<<endl;
            cout<<"Would you like to enter more? y/n";
            cin>>inputText;
        }
        while(inputText == "Y" || inputText =="y");
        outFile.close();
    }
    else
    {
        cout<<"Could not create / open file : "<< fileName;
    }
}

void getFileContents(fstream &inFile, string fileName)
{
    inFile.open(fileName,ios::in);
    if(inFile.is_open())
    {
        string line;

        while(inFile)
        {
            getline(inFile,line);
            cout<<line<<endl;
        }
        inFile.close();
    }
    else
    {
        cout<<"Could not open file : "<<fileName;
    }
}

void parseFile(fstream &file,string fileName,char delimeter = '\n')
{
    vector<string> heading;
    vector<string> value;
    file.open(fileName,ios::in);
    if(file.is_open())
    {
        string line;
        while(getline(file,line,delimeter))
        {
            heading.push_back(line);
            file>>line>>ws;
            value.push_back(line);
        }
        file.close();
    }
    else
    {
        cout<<"Could not open file : "<<fileName;
        return;
    }
    for (int i=0;i<heading.size();i++)
    {
      cout << heading[i]<<'\t';
    }
    cout<<"\n";
    for (int i=0;i<value.size();i++)
    {
      cout << value[i]<<'\t';
    }

}

void enterBinary(fstream &outFile,string fileName)
{
    string inputText;
    Person someone;
    outFile.open(fileName,ios::out | ios::app| ios::binary);

    if(outFile.is_open())
    {
        do
        {
            cout<<"Enter struct you would like to write to file";
            cout<<"Name : ";
            cin>> someone.Name;
            cout<<"Age : ";
            cin>>someone.age;
            cout<<"Height in meters : ";
            cin>>someone.heightM;
            outFile.write(reinterpret_cast<char *>(&someone),sizeof(Person));
            cout<<"Would you like to enter more? y/n";
            cin>>inputText;
        }
        while(inputText == "Y" || inputText =="y");
        outFile.close();
    }
    else
    {
        cout<<"Could not create / open file : "<< fileName;
    }
}

void readBinFile(fstream &inFile, string fileName)
{
    Person someone;
    inFile.open(fileName,ios::in|ios::binary);
    if(inFile.is_open())
    {
        string line;

        while(inFile.read(reinterpret_cast<char *>(&someone),sizeof(Person)))
        {
            cout<<"Name: "<<someone.Name<<"\t Age : "<<someone.age<<"\t Height in Meters : "<<someone.heightM<<"\n";
        }
        inFile.close();
    }
    else
    {
        cout<<"Could not open file : "<<fileName;
    }
}

int main(int argc, char *argv[])
{
    fstream file;
    string fileName;
    int menuOption;
    cout<<"Menu of operations \n"<<
          "1. Write to a file \n"<<
          "2. Read a file \n"<<
          "3. Parse CSV\n"<<
          "4. Write to a bin File\n"<<
          "5. Read a binary file";
    cin>>menuOption;
    switch (menuOption) {
    case 1:
        cout<<"Enter the name for the file you want to write to : ";
        cin>>fileName;
        enterFileContents(file,fileName);
        break;
    case 2:
        cout<<"Enter the name for the file you want to read: ";
        cin>>fileName;
        getFileContents(file,fileName);
        break;
    case 3:
    {
        cout<<"Enter the name for the file you want to read: ";
        cin>>fileName;
        cout<<"Enter the delimeter you want to use";
        char del;
        cin>>del;
        parseFile(file,fileName,del);
        break;
    }
    case 4:
    {
        cout<<"Enter the name for the file you want to write to : ";
        cin>>fileName;
        enterBinary(file,fileName);
        break;
    }
    case 5:
    {
        cout<<"Enter the name for the file you want to read: ";
        cin>>fileName;
        readBinFile(file,fileName);
        break;
    }
    default:
        cout<<"Please choose a number in the options";
        break;
    }
    return 0;
}
