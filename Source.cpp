#include <iostream>
using namespace std;

void printMenu(double ir, double iv, double cn, int yr); // Prints the main menu
void getInput(double& ir, double& iv, double& cn, int& yr, int& input); // Gets input from the user
void calculate(double ir, double iv, double cn, int yr); // Calculates and prints account amounts
void exitProgram(); // Exits the program and says thank you

int main()
{
	double interestRate = .1,
		investment = 0,
		contribution = 0;

	int yearsToRun = 25;

	int menuInput;
	char runAgain = 'Y';

	while (runAgain == 'Y' || runAgain == 'y')
	{
		menuInput = 0;

		while (menuInput != 5)
		{
			printMenu(interestRate, investment, contribution, yearsToRun);
			getInput(interestRate, investment, contribution, yearsToRun, menuInput);
		}

		calculate(interestRate, investment, contribution, yearsToRun); // Calculate interest rate

		cout << "\n\nWould you like to run again with different numbers? (Y or N)\n";
		cin >> runAgain;
		
		while (runAgain != 'Y' && runAgain != 'y' && runAgain != 'N' && runAgain != 'n')
		{

			cout << "\n\nWould you like to run again with different numbers? (Y or N)\n";
			cin >> runAgain;
		}
	}

	exitProgram();

	return 0;
}

void printMenu(double ir, double iv, double cn, int yr)
{
	system("CLS");

	cout << "Compound Interest Calculator\n\n"
		<< " 1. Annual interest: " << (ir * 100) << "%\n"
		<< " 2. Initial investment: $" << iv << endl
		<< " 3. Annual contribution: $" << cn << endl
		<< " 4. Years to run calculation: " << yr << endl
		<< " 5. Calculate!\n"
		<< " 6. Exit\n\n";

	cout << "Select an option from above to change the value: ";
}

void getInput(double& ir, double& iv, double& cn, int& yr, int& input)
{
	cin >> input;

	while (input < 1 && input > 6)
	{
		cout << endl << "Please select an option from above (1 - 5): ";
		cin >> input;
		cin.get();
	}
	cout << endl;

	switch (input)
	{
	case 1:
		cout << "Enter the interest rate in decimal form: ";
		cin >> ir;
		break;
	case 2:
		cout << "Enter the initial investment: ";
		cin >> iv;
		break;
	case 3:
		cout << "Enter the annual contribution: ";
		cin >> cn;
		break;
	case 4:
		cout << "How many years would you like to see: ";
		cin >> yr;
		break;
	case 5:
		return;
		break;
	case 6:
		exitProgram();
		break;
	default:
		cout << "Not a valid option. Please try again: ";
		break;
	}
}

void calculate(double ir, double iv, double cn, int yr)
{
	system("CLS");

	cout << "Results:\n"
		<< "Annual interest rate: " << (ir * 100) << "%\n"
		<< "Initial investment: $" << iv << endl
		<< "Annual contribution: $" << cn << endl << endl;

	for (int i = 1; i <= (yr * 12); i++)
	{
		if (i % 12 == 0 && (i / 12) % 5 == 0 || (i/12) == yr)
			cout << "Year " << (i / 12) << ": $" << iv << "\n";

		double mIR = ir / 12.0;
		double mCN = cn / 12.0;

		iv += (iv * mIR) + mCN;
	}
}

void exitProgram()
{
	cout << "\nThank you for using this calculator.\n";
	cin.get();
	cin.get();

	exit(0);
}