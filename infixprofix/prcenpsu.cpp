
#include <bits/stdc++.h>
using namespace std;

class circle
{

private:
    float r;

public:
    void setRadius(float R)
    {
        r = R;
    }
    int getRadius()
    {
        return r;
    }
    int getArea()
    {
        return 3.14 * r * r;
    }
};

int main()
{
    circle ra;
    ra.setRadius(5.6);
    cout << "Radius = " << ra.getRadius() << endl;
    cout << "Area = " << ra.getArea() << endl;
    return 0;
}