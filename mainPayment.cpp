//
// Calculate gross pay, net pay, pension and deductions for employees of Rogers Hostpital Supplies Company.
//
// Timoteo Shockness
// A00972539
//

#include <iostream>
#include <conio.h>  // Required for _getch() function
#include <fstream>  // Required for file input/output
#include <iomanip>
#include "PaymentCalculator.h"

using namespace std;

//global constants

// One way to specify a file name:
const char * IN_FILE = "EmployeePayInput.txt";

// A second way to specify a file name:
#define OUT_FILE "EmployeePayOutput.txt"

int main()
{
    PaymentCalculator paymentCalculator;
	//Declare variables
	long socialInsuranceNum;  // Will store social security number of employee
	int numberOfExemptions;  // Will store number of excemptions for employee

	double payRate,			// Will store the pay rate for the employee
		hoursWorked;		// Will store hours worked for the employee

	//Define ifstream object and open file
	ifstream ins;
	ins.open(IN_FILE);

	//Check that file opened without any issues
	if (ins.fail())
	{
		cerr << "ERROR--> Unable to open input file : " << IN_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -1; //error return code
	}

	//Define ofstream object and open file
	ofstream outs;
	outs.open(OUT_FILE);

	//Check that file opened without any issues
	if (outs.fail())
	{
		cerr << "ERROR--> Unable to open output file : " << OUT_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -2; //error return code
	}

	// Read in first social security number
	ins >> socialInsuranceNum;

    outs << "Rogers Hospital Supplies Company " << endl;
    outs << "-------------------------------- \n" << endl;

    outs << "Social insurance no.   gross pay    net pay    pension    deductions" << endl;
    outs << "--------------------------------------------------------------------" << endl;

    // Process data until end of file is reached
    while (!ins.eof()) {

// Read in other data for the employee
        ins >> payRate >> numberOfExemptions >> hoursWorked;

        paymentCalculator.print = paymentCalculator.errorChks(socialInsuranceNum, payRate, numberOfExemptions, hoursWorked, paymentCalculator.employeeProcessed);

        paymentCalculator.gross = paymentCalculator.grossPay(payRate, hoursWorked);					// gross pay

        paymentCalculator.taxable = paymentCalculator.calculateTaxable(paymentCalculator.gross, numberOfExemptions);
        paymentCalculator.federalTax = paymentCalculator.calculateFederalTax(paymentCalculator.taxable);
        paymentCalculator.deductions = paymentCalculator.calculateDeductions(paymentCalculator.federalTax);			//deductions is calculated using taxable, federal tax and provincial income tax

        paymentCalculator.pension = paymentCalculator.calculatePension(paymentCalculator.gross);						//pension

        paymentCalculator.netIncome = paymentCalculator.netPay(paymentCalculator.gross, paymentCalculator.deductions, paymentCalculator.pension);			//net pay


// The following line of code is used to confirm that reading and writing from/to files is working correctly.
//  This line of code (and these 2 comment lines) will need to be removed in your final solution.
//        outs << fixed << setprecision(2);
        if (paymentCalculator.print) {
            paymentCalculator.totalGrossPay += paymentCalculator.gross;
            paymentCalculator.totalNetPay += paymentCalculator.netIncome,
            paymentCalculator.totalPension += paymentCalculator.pension,
                    paymentCalculator.totalDeductions += paymentCalculator.deductions;
            outs << socialInsuranceNum << setw(23) << paymentCalculator.gross << setw(11) << paymentCalculator.netIncome << setw(11) << paymentCalculator.pension << setw(14) << paymentCalculator.deductions << '\n';
        }
// Read in next social security number
        ins >> socialInsuranceNum;
    }

    outs << "\n\n\nSummary" << endl;
    outs << "------- \n" << endl;
    outs << "Number of employees processed:" << setw(25) << paymentCalculator.employeeProcessed << endl;
    outs << "Total gross pay for all employees:" << setw(21) << paymentCalculator.totalGrossPay << endl;
    outs << "Total net pay for all employees:" << setw(23) << paymentCalculator.totalNetPay << endl;
    outs << "Total pension withheld for all employees: " << setw(13) << paymentCalculator.totalPension << endl;
    outs << "Total deductions for all employees:" << setw(20) << paymentCalculator.totalDeductions << endl;
	// Process data until end of file is reached
	while (!ins.eof()){

		// Read in other data for the employee
		ins >> payRate >> numberOfExemptions >> hoursWorked;

		// The following line of code is used to confirm that reading and writing from/to files is working correctly.
		//  This line of code (and these 2 comment lines) will need to be removed in your final solution.
		//outs << socialInsuranceNum << "  " << payRate << "  " << numberOfExemptions << "  " << hoursWorked << '\n';

		// Read in next social security number
		ins >> socialInsuranceNum;
	}

	// Close files
	ins.close();
	outs.close();

	cout << '\n' << endl;

	// Remove following line of code (and this comment) from your solution
	cout << "Type any key to continue ... \n\n";

	_getch(); // causes execution to pause until char is entered

}




