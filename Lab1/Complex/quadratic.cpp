// Solve quadratic equations using the complex type

#include <iostream>
#include <complex>
#include <string>

using namespace std;

using c_float = complex<float>;

string real_imag(const c_float& comp)
{
    // use a minus sign if the imag part is negative
    string pm = " + ";
    if (comp.imag() < 0) {
        pm = " - ";
    }

    return to_string(comp.real()) + pm + to_string(abs(comp.imag())) + "j";
}

int main()
{
    string input;
    do {
        float a, b, c;
        cout << "Enter a, b and c (real numbers) seperated by spaces, or q to quit" << endl;
        cin >> input;

        if (input[0] == 'q'){
            break;
        }

        a = stoi(input, nullptr, 0);
        cin >> b >> c;

        c_float a_comp {a};
        c_float b_comp {b};
        c_float c_comp {c};
        c_float disc = sqrt(pow(b_comp, 2) - 4.f * a_comp * c_comp);

        auto x1 = (-b_comp + disc) / (2.f * a_comp);
        auto x2 = (-b_comp - disc) / (2.f * a_comp);

        cout << "Roots are: " << endl << real_imag(x1) << endl << real_imag(x2) << endl;
    } while (input[0] != 'q');

   return 0;
}
