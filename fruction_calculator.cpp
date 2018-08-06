#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct fraction
{
    int phanNguyen;
    int tuSo;
    int mauSo;

};

fraction result;

fraction extra ( fraction x1 , fraction x2 )
{
    result.tuSo = x1.tuSo*x2.mauSo + x2.tuSo*x1.mauSo;
    result.mauSo = x1.mauSo*x2.mauSo;
    return result;
}

fraction sub (fraction x1, fraction x2)
{
    result.tuSo = x1.tuSo*x2.mauSo - x2.tuSo*x1.mauSo;
    result.mauSo = x1.mauSo*x2.mauSo;
    return result;
}

fraction multi(fraction x1, fraction x2)
{
    result.tuSo = x1.tuSo*x2.tuSo;
    result.mauSo = x1.mauSo*x2.mauSo;
    return result;
}

fraction div(fraction x1, fraction x2)
{
    result.tuSo = x1.tuSo*x2.mauSo;
    result.mauSo = x1.mauSo*x2.tuSo;
    return result;
}

void getFraction (fraction &x1, fraction &x2 )
{
    cout << "Nhap tu so cho x1: "; cin >> x1.tuSo;
    cout << "Nhap mau so cho x1: "; cin >> x1.mauSo;
    cout << "Nhap tu so cho x2: "; cin >> x2.tuSo;
    cout << "Nhap mau so cho x2: "; cin >> x2.mauSo;
}


void toiGian (fraction &x)
{
    x.phanNguyen = x.tuSo / x.mauSo ;
    x.tuSo = x.tuSo - x.phanNguyen*x.mauSo;
    for (int i = 2; i <= x.mauSo ; i++)
    {
        if (x.tuSo == 0) break;
        while (( x.tuSo % i == 0) && (x.mauSo % i == 0))
        {
            x.tuSo = x.tuSo / i;
            x.mauSo = x.mauSo / i;
        };
    }

}

void printFraction (fraction x)
{
    cout << "Ket qua cua phep toan la: ";
    if((x.phanNguyen != 0) && (x.tuSo == 0)) cout << x.phanNguyen << endl;
    if((x.phanNguyen != 0) && (x.tuSo != 0)) cout << x.phanNguyen <<"/" << x.tuSo << "/" << x.mauSo << endl;
    if (x.phanNguyen == 0) cout << x.tuSo << " / " << x.mauSo << endl;
}

int main()
{   int s;
    char ch;
    int i;
    fraction x1,x2;

    string operation[] =  {"+","-","*","/"};
    string op;

        do
     {
        do
        {
        cout << "Tinh toan phan so" << endl;
        cout << "-----------------------------" << endl;
        cout << "Hay nhap toan tu: "; cin >> op;
        for ( i = 0; i < 4; i++)
            {
                if (op == operation[i]) {s = i; break;}
                else s = -1;
            }
        if (s == -1 )
        {
            cout << "Toan tu khong hop le. Nhap lai !!!" << endl;
            system("pause");
            system("cls");
        }
        }while(s == -1);

        getFraction(x1, x2);
        switch (s)
        {
            case 0: result = extra(x1,x2); break;
            case 1: result = sub(x1,x2);break;
            case 2: result = multi(x1,x2); break;
            case 3: result = div (x1,x2); break;
        }
        toiGian(result);
        printFraction(result);
        cout << "Ban co muon tiep tuc(c/k): "; cin >> ch;
        system ("cls");
    }while (ch!= 'k');

}
