#include <iostream>
#include <algorithm>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Circle
{
private:
    double radius = 0;

public:
    Circle(float r) : radius(r){};
    double area()
    {
        return M_PI * radius * radius;
    }
    double perimeter()
    {
        return M_PI * radius * 2;
    }
    void setRadius(double r)
    {
        radius = r;
    }
    double getRadius()
    {
        return radius;
    }
    void displayCircle()
    {
        cout << "Circle radius is " << getRadius() << endl;
        cout << "Area is " << area() << endl;
        cout << "Perimeter is " << perimeter() << endl;
    }
};

int main(int argc, char const *argv[])
{
    Circle c(3);
    c.displayCircle();

    Circle d(2);

    vector<Circle> circleList;
    circleList.push_back(c);
    circleList.push_back(d);

    for (Circle a : circleList)
    {
        cout << "----------------" << endl;
        a.displayCircle();
    }

    return 0;
}
