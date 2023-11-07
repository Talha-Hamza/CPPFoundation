
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int hours;
	int dependents;

	double base_rate = 16.78;
	double overtime_rate = 1.5 * base_rate;

	double total_pay ;
	double final_pay;

	cout << "The number of hours worked in a week: ";
	cin >> std::ws;
	cin >> hours;

	cout << "The number of dependents: ";
	cin >> std::ws;
	cin >> dependents;

	if (hours <= 40 && hours >=0)
	{
		total_pay = hours * base_rate;
	}
	else if (hours > 40)
	{
		total_pay = 40 * base_rate + (hours - 40) * overtime_rate;
	}
	else{
		cout << "Invalid hours input";
		return 0;
	}

	double social_security_tax = 0.06 * total_pay;
	double federal_income_tax = 0.14 * total_pay;
	double state_income_tax = 0.05 * total_pay;
	int union_dues = 10;
	int health_insurance = 0;

	if (dependents >= 3)
	{
		health_insurance = 35;
	}
	else if (dependents < 0)
	{
		cout << "Invalid dependents input";
		return 0;
	}

	final_pay = total_pay - social_security_tax - federal_income_tax - state_income_tax - union_dues - health_insurance;

	cout << fixed << setprecision(1);
	cout << "Your ideal total pay is: " << total_pay << endl;

	cout << fixed << setprecision(3);
	cout << "Your social security withholding is: " << social_security_tax << endl;
	cout << "Your federal income withholding is:" << federal_income_tax << endl;
	cout << "Your state income withholding is: " << state_income_tax << endl;
	cout << "Your union dues withholding is: " << union_dues << endl;
	cout << "Your dependent health care withholding is: " << health_insurance << endl;
	cout << "The net take-home pay is: " << final_pay << endl;



	return 0;
 }
