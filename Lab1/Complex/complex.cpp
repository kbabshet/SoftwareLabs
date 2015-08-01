// complex.cpp
// Multiplying complex numbers

#include <iostream>
#include <complex> // required for the complex class

using namespace std;

using c_float = complex<float>;

int main()
{
    c_float num1{ 2.0, 2.0 };  // using C++11 uniform initialisation syntax
    c_float num2{ 4.0, -2.0 }; // old syntax: complex<float> num2(4.0,-2.0);

    auto answer = num1 * num2; // using C++11 auto keyword,
                               // answer is of type: complex<float>

    cout << "The answer is: " << answer << endl;
    cout << "Or in a more familiar form: " << answer.real() << " + " << answer.imag() << "j" << endl;

    // answer++;
    // This line will not work because ++ is not defined for complex numbers
    // (would the real or imaginary part be incremented?)
    // An operator could be defined to do this

    return 0;
}
