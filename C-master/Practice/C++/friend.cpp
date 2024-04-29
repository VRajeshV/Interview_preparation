#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;
public:
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }
    friend int getArea(Rectangle rect);
};

int getArea(Rectangle rect) {
    return rect.length * rect.width;
}

int main() {
    Rectangle rect(5, 10);
    cout << "Area of rectangle is: " << getArea(rect) << endl;
    return 0;
}