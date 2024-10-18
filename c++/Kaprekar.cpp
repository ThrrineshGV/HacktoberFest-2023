#include <iostream>
#include <cmath>
using namespace std;

bool isKaprekar(int number, int base)
{
    if (number < 0 || base <= 1)
    {
        return false;
    }
    long long squared = static_cast<long long>(number) * number;
    long long divisor = 1;

    // Find the proper divisor that will separate left and right parts of the squared number
    while (divisor <= squared / base)  // Fixed condition
    {
        divisor *= base;
    }

    while (divisor > 0)
    {
        long long left = squared / divisor;
        long long right = squared % divisor;

        // Check if left + right == number and ensure right part is non-zero
        if (left + right == number && right > 0)
        {
            return true;
        }
        divisor /= base;
    }
    return false;
}

int main()
{
    int number, base;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the base: ";
    cin >> base;

    if (isKaprekar(number, base))
    {
        cout << number << " is a Kaprekar number in base " << base << endl;
    }
    else
    {
        cout << number << " is not a Kaprekar number in base " << base << endl;
    }

    return 0;
}
