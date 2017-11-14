//Timoteo Shockness
// A00972539
//

class PaymentCalculator {



//global constants
public:

    const long NINE_DIGITS = 100000000; //const value to make sure the social insurance # is always 9 digits;
    const long TEN_DIGITS = 1000000000;
    const double MINRATE = 0;
    const double MAXRATE = 99.99;
    const int MAXEXEMPT = 19;
    const int MINEXEMPT = 0;
    const double MINHOURS = 0;
    const double MAXHOURS = 54;
    const double FULLTIME = 40;
    const double EXTRARATE = 1.5;
    const double MAXPENSION = 16.5;

    bool errorChks(long, double, int, double, int&);			//verifying the inputs
    double grossPay(double, double);							//to calculate Gross pay
    double calculateDeductions(double);							//to calculate deductions
    double calculatePension(double);							//to calculate pension
    double calculateTaxable(double, int);						//to calculate taxable
    double calculateFederalTax(double);							//to calculate federal tax
    double netPay(double, double, double);						//to calculate net pay

    int employeeProcessed = 0;		//counts the number of processed employees
    double 	gross,						// gross income of the employee
            federalTax,					// federal tax
            taxable,					// taxable
            deductions,					// deductions
            pension,					// pension
            netIncome,					// net income
            totalGrossPay = 0,			// store total gross pay to employees
            totalNetPay = 0,			// store total net pay to employees
            totalPension = 0,			// store total pension withheld for all employees
            totalDeductions = 0;		// store total deductions for all employees:
    bool print;				//return true to print the result to the output file




};





