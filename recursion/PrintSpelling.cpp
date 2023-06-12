
#include <iostream>
using namespace std;

void GetSpelling(int n, string str[])
{
    if (n == 0)
    {
        return;
    }

    GetSpelling(n / 10, str);
    int number = n % 10;
    cout << str[number] << " ";
}

int main()
{
    int n;
    cin >> n;

    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    GetSpelling(n, str);
}
