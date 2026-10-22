/* 
--The Shape Calculator--

You are required to develop a shape-calculation system using Object-Oriented Programming (OOP) in C++.

The program must support three types of shapes: - Circle - Rectangle - Triangle

Use (pi = 3.14) for all circle calculations.

Create an abstract base class named Shape and derive the classes Circle, Rectangle, and Triangle from it.

The Shape class must declare a pure virtual function named calculateArea(). Each derived class must implement this function according to its shape.

The program must store the addresses of all created objects using pointers to the base class. When calculateArea() is called through a base-class pointer, the program must execute the appropriate derived-class implementation.

Additionally, each derived class must define a non-virtual function named displayType(), which hides the corresponding function in the base class. Calling this function through a base-class pointer must demonstrate early binding.

Finally, the base class must have a virtual destructor, and each derived class must have its own destructor. When objects are deleted through base-class pointers, the destructors must execute in the correct order.

Requirements 1. Create an abstract class named Shape. 2. Declare calculateArea() as a pure virtual function in Shape. 3. Define a non-virtual displayType() function in Shape that prints Category: Shape. 4. Implement the Circle, Rectangle, and Triangle classes. 5. Each derived class must override calculateArea() and hide displayType(). 6. Use an array or vector of Shape* pointers to manage the objects. 7. Call displayType() and calculateArea() through base-class pointers. 8. Use a virtual destructor in the base class to ensure proper destruction of derived objects. Important: Since displayType() is non-virtual, calling it through a Shape* must execute the base-class version. In contrast, calculateArea() must execute the correct derived-class version because it is virtual.

The program must print all shape categories and areas first, then delete the objects in their input order and print the destructor messages.

Input Format

The first line contains an integer (N), representing the number of shapes.
Each of the next (N) lines describes one shape.
The first character specifies the shape type:
C — Circle, followed by the radius (r).
R — Rectangle, followed by the length (l) and width (w).
T — Triangle, followed by the base (b) and height (h). All dimensions are positive numbers.
Constraints

1 <= N <= 100
0

Shape types will only be C, R, or T.

Each input line will contain exactly the parameters required for its shape.
All areas must be printed with exactly two digits after the decimal point.
Use 3.14 as the value of (\pi).
All objects must be accessed and deleted through base-class pointers.
Destructor messages must follow the required order.
Output Format

For each shape, print two lines:

Category: Shape
Area: X.XX, where X.XX is the calculated area rounded to two decimal places.
After printing the results for all shapes, delete each object in its input order. For every deleted object, print:

Circle destructor for a circle, followed by Shape destructor.
Rectangle destructor for a rectangle, followed by Shape destructor.
Triangle destructor for a triangle, followed by Shape destructor.
Each message must appear on a separate line.

Sample Input 0

3
C 2
R 4 5
T 6 3
Sample Output 0

Category: Shape
Area: 12.56
Category: Shape
Area: 20.00
Category: Shape
Area: 9.00
Circle destructor
Shape destructor
Rectangle destructor
Shape destructor
Triangle destructor
Shape destructor
Explanation 0

Circle: (3.14 x 2 x 2 = 12.56)
Rectangle: (4 x 5 = 20.00)
Triangle: (0.5 x 6 x 3 = 9.00)*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Shape {
    public:
        virtual ~Shape() {
            cout << "Shape destructor\n";
        }

        virtual void calculateArea() const = 0;

        void displayType() const {
            cout << "Category: Shape\n";
        }
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}
        
        ~Circle() override {
            cout << "Circle destructor\n";
        }

        void calculateArea() const override {
            cout << "Area: " << fixed << setprecision(2) << 3.14 * radius * radius << "\n";
        }

        void displayType() const {
            cout << "Category: Circle\n";
        }
};

class Rectangle : public Shape {
    private:
        double length, width;
    public:
        Rectangle(double l, double w) : length(l), width(w) {}
        
        ~Rectangle() override {
            cout << "Rectangle destructor\n";
        }

        void calculateArea() const override {
            cout << "Area: " << fixed << setprecision(2) << length * width << "\n";
        }

        void displayType() const {
            cout << "Category: Rectangle\n";
        }
};

class Triangle : public Shape {
    private:
        double base, height;
    public:
        Triangle(double b, double h) : base(b), height(h) {}
        
        ~Triangle() override {
            cout << "Triangle destructor\n";
        }

        void calculateArea() const override {
            cout << "Area: " << fixed << setprecision(2) << 0.5 * base * height << "\n";
        }

        void displayType() const {
            cout << "Category: Triangle\n";
        }
};

int main() {
    int N;
    cin >> N;

    vector<Shape*> shapes;

    for (int i = 0; i < N; ++i) {
        char type;
        cin >> type;
        if (type == 'C') {
            double r;
            cin >> r;
            shapes.push_back(new Circle(r));
        } else if (type == 'R') {
            double l, w;
            cin >> l >> w;
            shapes.push_back(new Rectangle(l, w));
        } else if (type == 'T') {
            double b, h;
            cin >> b >> h;
            shapes.push_back(new Triangle(b, h));
        }
    }

    for (Shape* shape : shapes) {
        shape->displayType();
        shape->calculateArea();
    }

    for (Shape* shape : shapes) {
        delete shape; 
    }

    return 0;
}