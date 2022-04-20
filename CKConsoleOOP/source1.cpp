#include <iostream>
using namespace std;
  
void power();
void PrimeNumber();

int main()
{
    power();
    // PrimeNumber();
    return 0;
}

void power()
{
    int n, k;
    int result;

    cin >> n >> k;
    result = pow(n, k);

    cout << result << endl;
}

void PrimeNumber()
{
    int n, i,j;
    
    cin >> n;

    for (i = 2; i <= n; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0) {
                break;
            }
        }

        if (j == i) {
            cout << j << endl;
        }
    }
}