//
// Created by TIMOTEO SHOCKNESS on 2017-09-22.
//
#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(string firstName, string lastName, int monthSalary)
{
    if(!isStringBiggerThanOne(firstName))
    {
        printf("\n");
        cout << "Warning - invalid length string entered for first name in ctor: " << firstName << endl;
        printf("The first name will be set as undefined.");
        printf("\n");
        firstName = "Undefined";
    }


    if(!isStringBiggerThanOne(lastName))
    {
        printf("\n");
        cout << "Warning - invalid length string entered for last name in ctor: " << lastName << endl;
        printf("The last name will be set as undefined.");
        printf("\n");
        lastName = "Undefined";
    }


    if(!isNumberPositive(monthSalary))
    {
        printf("\n");
        cout << "Invalid salary amount specified in ctor: " << monthSalary << endl;
        printf("Salary set to $0 instead.");
        printf("\n");
        monthSalary = 0;
    }

    setFirstName(firstName);
    setLastName(lastName);
    setMonthlySalary(monthSalary);
}

void Employee::setFirstName(std::string firstName)
{
    if(firstName.size() > 1)
    {
        Employee::firstName = firstName;
    }
    else
    {
        printf("\n");
        cout << "ERROR - invalid length string entered for first name ins setFirstName(): " << firstName << endl;
        cout << "The first name was left unchanged: " << getFirstName() << endl;
    }
}

void Employee::setLastName(std::string lastName)
{
    if(isStringBiggerThanOne(lastName))
    {
        Employee::lastName = lastName;
    }
    else
    {
        printf("\n");
        cout << "ERROR - invalid length string entered for last name in setLastName(): " << lastName << endl;
        cout << "The last name was left unchanged: " << Employee::getLastName() << endl;
    }
}

void Employee::setMonthlySalary(int monthSalary)
{
    if(isNumberPositive(monthSalary))
    {
        Employee::monthSalary = monthSalary;
    }
    else
    {
        printf("\n");
        cout << "ERROR - Invalid salary amount specified: $" << monthSalary << endl;
        cout << "Salary was left unchanged at: " << getMonthlySalary() << endl;
    }
}
std::string Employee::getFirstName() const
{
    return Employee::firstName;
}

std::string Employee::getLastName() const
{
    return Employee::lastName;
}

int Employee::getMonthlySalary() const
{
    return Employee::monthSalary;
}

bool Employee::isStringBiggerThanOne(std::string value) const
{
    if(value.size() > 1)
    {
        return true;
    }

    return false;

}

bool Employee::isNumberPositive(int value) const
{
    if(value >= 0)
    {
        return true;
    }

    return false;
}
