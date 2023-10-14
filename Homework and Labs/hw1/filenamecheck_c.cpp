/*
1. Execute this script for checking whether the naming convention of your file is correct or not.
2. Run the following commands to compile and execute
3a. For Windows users: g++ -std=c++17 filenamecheck_c.cpp -o filenamecheck.out
3b. For Mac users: clang++ -std=c++17 filenamecheck_c.cpp -o filenamecheck.out
4. ./filenamecheck.out <x500_ID> <Homework Number>
5. For example if my x500 ID is smithx1234 and homework number is 2, I should write ./filenamecheck.out smithx1234 hw2
*/

#include<iostream>
#include <filesystem>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc!=3){
        cout<<"Incorrect number of arguments!!Enter your username and homework number as arguments"<<endl;
        return 0;
    }
    else{
    string username = argv[1];
    string homework_num = argv[2];
    string correctfilename = username + "_" + homework_num + ".cpp";

    cout<<"Checking for username: "<<username<<endl;
    cout<<"Checking for homework number: "<<homework_num<<endl;;

    //TODO: Use <filename> to check if tarball even exists.
    //...otherwise we can't tell the difference between the two errors.

    string str = "tar -tf ";
    str = str + homework_num+"_"+username+".tgz ";
    string str1 = homework_num+"_"+username+".tgz";
    str = str + homework_num+"_directory"+"/";
    //str = str + correctfilename;
    //string str1 = "if exist";

    const char *command = str.c_str();
    //const char *command1 = str1.c_str();

    if (std::filesystem::exists(str1)){
        if (system(command)) {
            // System commands Return a number larger than 0 if there is an error
            cout<<"ugh, file not found in tarball...";
        } 
        else {
            // System commands Return 0 if it ran successfully
            cout<<"File exists in tarball, good work!"; 
                }
        }
        else{
            cout<<".tgz File doesn't exist";
        }
    return 0;
    }
}