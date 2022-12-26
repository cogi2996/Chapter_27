#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

int soNguyenTo(int n);
void phanTich(int n1, int m1, int &count);
int y;
unsigned long long kq;

int main()
{
    int n;
    cout << "P=y^n\nNhap n:";
    cin >> n;
    cout << "Nhap y: ";
    cin >> y;
    kq = y;
    int n1 = n;
    int m1 = 1;
    string str;
    int count = 0;
    cout << "Phan tich: \nBan dau lay y" << endl;
    phanTich(n1, m1, count);
    cout << "So phep nhan toi thieu: " << count << endl;
    cout << kq;
    return 0;
}

int soNguyenTo(int n)
{
    if (n == 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return i; // thua so nguyen to be nhat
        }
    }
    return 0; // so nguyen to
}

void phanTich(int n1, int m1, int &count)
{
    if (n1 != 1)
    {
        if (soNguyenTo(n1) == 0) // so nguyen to
        {
            n1 = n1 - 1;
            count++;
            cout << "Nhan voi y^" << m1 << endl;
            if (m1 != 1)
            {
                return;
            }
            phanTich(n1, m1, count); 
            kq = kq * y;
        }
        else if (soNguyenTo(n1) > 0) // khong phai so nguyen to
        {
            int p = soNguyenTo(n1);
            int n2 = p;
            int m2 = (n1 * m1) / p;
            n1 = n1 / p;
            phanTich(n1, m1, count);
            kq = pow(kq, p);
            phanTich(n2, m2, count); 
        }
    }
}