/*
Create two classes:

Meter
Centimeter
The Meter class stores distance in meters, while the Centimeter class stores distance in centimeters.

Implement a conversion from Meter to Centimeter.

Add lot of comments in the code and print statements which might not be a need

For example:

Meter m(2);

Centimeter c = static_cast<Centimeter>(m);
The resulting value should be:

200

Input Format

A single floating-point number representing distance in meters.

Constraints

Create a conversion constructor in Centimeter.
The conversion should be explicit.
Direct implicit conversion should not be allowed.
Output Format

Display the original distance and the converted distance.

Sample Input 0

12.345
Sample Output 0

Distance in meters: 12.345
Distance in centimeters: 1234.5
*/

#include <iostream>
using namespace std;

class Meter{
    
private:
    float dis_meter;
    
public:
    Meter(float m) {
        dis_meter = m;
    }
    
    float getMeter() const {
        return dis_meter;
    }
    
    void display()const{
        cout<<"Distance in meters: "<<dis_meter<<endl;
    }
    
    
};

class Centimeter{
    
private:
    float dis_cen;
    
public:

    explicit Centimeter(const Meter& m) {
        dis_cen = m.getMeter() * 100.0f;
    }
    
    void display(){
        cout<<"Distance in centimeters: "<<dis_cen<<endl;
    }
    
};

int main() {
    
    float m;
    cin>>m;
    
    Meter m1(m);
    m1.display();
    
    Centimeter c = static_cast<Centimeter>(m);
    c.display();
    
    return 0;
}
