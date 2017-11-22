// Assign 8
// File Name: Complex.cpp
// Author: Timoteo Shockness
// Date: Nov. 20th, 2017

#include <iostream>
#include <iomanip>
#include "Complex.h"
using namespace std;

//Contructor setting initial value
Complex::Complex(const double & real, const double & imaginary)
        :real(real), imaginary(imaginary)
{

}

//Get and Set for Real numbers
void Complex::setReal(const double &real) {
    Complex::real = real;
}

//Get for Imaginary numbers
const double & Complex::getReal(void) const {
    return real;
}

//Set for Imaginary numbers
void Complex::setImaginary(const double &imaginary) {
    Complex::imaginary = imaginary;
}

//Get for Imaginary numbers
const double & Complex::getImaginary(void) const {
    return imaginary;
}

//Member function for Sum 2 objects
//receives a object reference
Complex & Complex::plusEq(const Complex &object) {
    real += object.real;
    imaginary += object.imaginary;
    return (*this);
}

//Member function for subtract 2 objects
//receives a object reference
Complex & Complex::minusEq(const Complex &object) {
    real -= object.real;
    imaginary -= object.imaginary;
    return (*this);
}

//Member function to display info
void Complex::display(void) const {
    cout << fixed << setprecision(4);
    cout << "( " << getReal() << " , " << getImaginary() << " )";
}
