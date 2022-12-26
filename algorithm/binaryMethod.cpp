#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate y^n using the binary method
int binaryMethod(int y, int n)
{
    // 1101
    
    int result = 1;

    // While n is greater than 0
    while (n > 0)
    {
        // If n is odd, multiply result by y
        if (n & 1 == 1 ) // so le
        {
            result *= y;
        }
        // Divide n by 2 and square y
        n >>= 1;
        y =y* y;

    }

    return result;
}

int main()
{
    int y = 2, n = 13;
    cout<<"nhap y = ";
    cin>>y;
    cout<<"Nhap n = ";
    cin>>n;
    cout << y<<"^"<<n<< "="<< binaryMethod(y, n) << endl;

    return 0;
}
