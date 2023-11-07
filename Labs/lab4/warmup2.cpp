#include <iostream>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();


void printHumanTower(const std::string arrayOfNames[], int length_array_names, const double arrayOfHeights[]){

	double sum = 0;

	cout << "If ";
	for (int i = 0; i < length_array_names; i++)
	{	
		sum += arrayOfHeights[i];
		cout << arrayOfNames[i];
		if (i < length_array_names - 1)
		{
			cout << " and ";
		}
		else
		{
			cout << " form a human tower, their combined height will be ";
		}
	}
	cout << sum << endl;
}
	

int main() 
{
	string arrayOfNames[100];
	double arrayOfHeights[100];

	int numberOfPartners = requestNumberOfPartners();

	for (int i = 0; i < numberOfPartners; i++)
	{
		arrayOfNames[i] = requestName();
		arrayOfHeights[i] = requestHeight(arrayOfNames[i]);
	}

	printHumanTower(arrayOfNames, numberOfPartners, arrayOfHeights);

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
	cout << "How many partners are there? ";
	cin >> numberOfPartners;

	return numberOfPartners;
}
