//
// Created by TIMOTEO SHOCKNESS on 2017-09-22.
//

#ifndef ASSIGNMENT1_EMPLOYEE_H
#define ASSIGNMENT1_EMPLOYEE_H

#include <string>


class Employee {
public:
    explicit Employee(std::string firstName, std::string lastName, int monthSalary);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setMonthlySalary(int monthSalary);
    std::string getFirstName() const;
    std::string getLastName() const;
    int getMonthlySalary() const;

private:
    std::string firstName;
    std::string lastName;
    int monthSalary;
    bool isStringBiggerThanOne(std::string) const;
    bool isNumberPositive(int value) const;

};


#endif //ASSIGNMENT1_EMPLOYEE_H
