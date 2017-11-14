// Timoteo Shockness
// A00972539
//
#include <iostream>
#include <iomanip>
#include "PaymentCalculator.h"


bool PaymentCalculator::errorChks(long num, double rate, int exempt, double hours, int &counter){

    bool ok = true;

    if (!(num < TEN_DIGITS && num >= NINE_DIGITS))
    {
        std::cerr << std::setw(10) << num << "	INPUT DATA ERROR:	Invalid social security #" << std::endl;
        ok = false;
    }

    if (!(rate >= MINRATE && rate <= MAXRATE))
    {
        std::cerr << std::setw(10) << num << "	INPUT DATA ERROR:	Invalid pay rate: " << rate << std::endl;
        ok = false;
    }

    if (!(exempt >= MINEXEMPT && exempt <= MAXEXEMPT))
    {
        std::cerr << std::setw(10) << num << "	INPUT DATA ERROR:	Invalid number of exemptions: " << exempt << std::endl;
        ok = false;
    }


    if (!(hours <= MAXHOURS && hours >= MINHOURS))
    {
        std::cerr << std::setw(10) << num << "	INPUT DATA ERROR:	Invalid hours worked: " << hours << std::endl;
        ok = false;
    }

    if (ok)
    {
        counter++;
    }
    return ok;
}

double PaymentCalculator::grossPay(double rate, double hours){

    double amount = 0;



    std::cerr << std::fixed << std::setprecision(2);


    if (rate >= MINRATE && rate <= MAXRATE) {
        if (hours <= MAXHOURS && hours >= MINHOURS) {
            if (hours > FULLTIME) {
                amount += (rate * EXTRARATE) *  (hours - FULLTIME);
                hours = FULLTIME;
            }
            amount += (rate * hours);
        }
    }
    return amount;
}

double PaymentCalculator::calculateDeductions(double fedTax){
    const double VALUE = 0.35;
    double result = fedTax + (fedTax * VALUE);
    if (result < 0) {
        result = 0;
    }
    return result;
}

double PaymentCalculator::calculateTaxable(double grs, int exemptions) {
    double result = 0;
    const double NUM1 = 14;
    const double NUM2 = 11;

    if (exemptions >= 0 && exemptions <= 19) {
        result = grs - (NUM1 * exemptions) - NUM2;
    }
    return result;
}

double PaymentCalculator::calculateFederalTax(double tax) {
    const double NUM1 = 0.14;
    const double NUM2 = 0.00023;

    return tax * (NUM1 + (NUM2 * tax));
}

double PaymentCalculator::calculatePension(double grs) {
    double sevenPointSevenPercentOfGross = grs * 7.7 / 100;


    if (sevenPointSevenPercentOfGross > MAXPENSION) {
        return MAXPENSION;
    }
    else {
        return sevenPointSevenPercentOfGross;
    }
}

double PaymentCalculator::netPay(double grs, double ddctn, double pnsn){
    return grs - ddctn - pnsn;
}
