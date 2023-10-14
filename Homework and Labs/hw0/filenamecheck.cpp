#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{

string username = argv[2];
string homework_num = argv[3];
string correctfilename = username + "_" + homework_num + ".cpp";
string entered_filename = argv[1];

cout<<"Checking for username: "<<username<<endl;
cout<<"Checking for homework number: "<<homework_num<<endl;;
cout<<"Filename being checked is: "<<entered_filename<<endl;

if (entered_filename==correctfilename){
	cout<<"Entered Filename is correct";
}

else{
	cout<<"Incorrect Filename!!"<<endl;
	cout<<"Correct Filename is: "<<correctfilename<<endl;
	cout<<"User entered: "<<entered_filename<<endl;
}

return 0;

}

