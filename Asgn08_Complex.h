// Assign 8
// File Name: Complex.cpp
// Author: Timoteo Shockness
// Date: Nov. 20th, 2017

class Complex {
public:
    //Contructor setting initial value
    Complex(const double & real = 1.0, const double & imaginary = 0.0);

    //Get and Set for Real numbers
    void setReal(const double& );
    const double & getReal(void) const;

    //Get and Set for Imaginary numbers
    void setImaginary(const double& );
    const double & getImaginary(void) const;

    //Member function for Sum 2 objects
    //receives a object reference
    Complex & plusEq(const Complex&);

    //Member function for subtract 2 objects
    //receives a object reference
    Complex & minusEq(const Complex& );

    //Member function to display info
    void display(void) const;

private:
    double real;
    double imaginary;
};
