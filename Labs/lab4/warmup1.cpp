#include <iostream>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();
void printHumanTower(string name1, string name2, double height1, double height2);

int main() 
{
	string arrayOfNames[2];
	double arrayOfHeights[2];
	
	// string fullName1, fullName2;
	// double height1, height2;

	arrayOfNames[0] = requestName();
	arrayOfHeights[0] = requestHeight(arrayOfNames[0]);
	arrayOfNames[1] = requestName();
	arrayOfHeights[1] = requestHeight(arrayOfNames[1]);

	printHumanTower(arrayOfNames[0], arrayOfNames[1], arrayOfHeights[0], arrayOfHeights[1]);

	return 0;
}

string requestName()
{
	string name;
	cout << "Please enter full name: ";
	cin >> std::ws;
	getline(cin, name);
	return name;
}

double requestHeight(string fullName)
{
	double height;
	cout << "Please enter " << fullName << "'s height: ";
	cin >> height;
	
	return height;
}

int requestNumberOfPartners()
{
	int numberOfPartners; 
	cout << "How many partners are there?";
	cin >> numberOfPartners;

	return numberOfPartners;
}
void printHumanTower(string name1, string name2, double height1, double height2){
cout << "If " << name1 << " and " << name1
		<< " form a human tower, their combined height will be "
		<< (height1 + height2) << endl;
}
	