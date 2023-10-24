#include "Shapes.h"

// ================== Shape2D ==================

void Shape2D::ShowArea() const
{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}

bool Shape2D::operator>(const Shape2D &rhs) const{

    if (Area() > rhs.Area()){
        return true;
    }
    else{
        return false;
    }
}

bool Shape2D::operator<(const Shape2D &rhs) const{
    if (Area() < rhs.Area()){
        return true;
    }
    else{
        return false;
    }
}

bool Shape2D::operator==(const Shape2D &rhs) const{
    if (Area() == rhs.Area()){
        return true;
    }
    else{
        return false;
    }
}

// ================== Shape3D ==================


void Shape3D::ShowVolume() const
{
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

bool Shape3D::operator>(const Shape3D &rhs) const{
    if (Volume() > rhs.Volume()){
        return true;
    }
    else{
        return false;
    }
}

bool Shape3D::operator<(const Shape3D &rhs) const{
    if (Volume() < rhs.Volume()){
        return true;
    }
    else{
        return false;
    }
}

bool Shape3D::operator==(const Shape3D &rhs) const{
    if (Volume() == rhs.Volume()){
        return true;
    }
    else{
        return false;
    }
}

// ================== Square ==================

Square::Square(float s_length){
    sideLength = s_length;
}

void Square::Scale(float scaleFactor){
    sideLength *= scaleFactor;
}

void Square::Display() const{
    cout << "The area of the Square is : " << Area() << endl;
    cout << "Length of a side: " << sideLength << endl;
}

float Square::Area() const{
    return (sideLength * sideLength);
}

string Square::GetName2D() const{
    return "Square";
}

// ================== Triangle ==================

Triangle::Triangle(float b, float h){
    base = b;
    height = h;
}

void Triangle::Scale(float scaleFactor){
    base *= scaleFactor;
    height *= scaleFactor;
}

void Triangle::Display() const{
    cout << "The area of the Triangle is : " << Area() << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
}

float Triangle::Area() const{
    float area = (base * height) / 2;
    return area;
}

string Triangle::GetName2D() const{
    return "Triangle";
}

// ================== Circle ==================
Circle::Circle(float r){
    radius = r;
}

void Circle::Scale(float scaleFactor) {
    radius *= scaleFactor;
}

void Circle::Display() const{
    cout << "The area of the Circle is : " << Area() << endl;
    cout << "Radius: " << radius << endl;
}

float Circle::Area() const{
    float area = (radius * radius) * PI;
    return area;
}

string Circle::GetName2D() const{
    return "Circle";
}

float Circle::get_radius() const{
    return radius;
}


// ================== Triangular Pyramid ==================

TriangularPyramid::TriangularPyramid(float p_h, float t_len, float t_h): Triangle(t_len, t_h){
    pyramid_height = p_h;
}

void TriangularPyramid::Scale(float scaleFactor){
    pyramid_height *= scaleFactor;
    Triangle::Scale(scaleFactor);
}

void TriangularPyramid::Display() const{
    cout << "The volume of the TriangularPyramid is : " << Volume() << endl; 
    cout << "The height is: " << pyramid_height << endl;
    Triangle::Display();
}

float TriangularPyramid::Volume() const{
    float volume = Area() * pyramid_height * (1.0/3.0);
    return volume;
}

string TriangularPyramid::GetName3D() const {
    return "Triangular Pyramid";
}

// ================== Cylinder ==================

Cylinder::Cylinder(float h, float r): Circle(r){
    height = h;
}


void Cylinder::Scale(float scaleFactor){
    height *= scaleFactor;
    Circle::Scale(scaleFactor);
}

void Cylinder::Display() const{
    cout << "The volume of the Cylinder is : " << Volume() << endl;
    cout << "The height is: " << height << endl;
    Circle::Display();
}

float Cylinder::Volume() const{
    float volume = Area() * height;
    return volume;
}

string Cylinder::GetName3D() const{
    return "Cylinder";
}

// ================== Sphere ==================

Sphere::Sphere(float r): Circle(r){

}

void Sphere::Scale(float scaleFactor){
    Circle::Scale(scaleFactor);
}
void Sphere::Display() const{
    cout << "The volume of the Sphere is : " << Volume() << endl;
    Circle::Display();
}

float Sphere::Volume() const{

    float radius = get_radius();
    float volume = (4.0/3.0) * PI * pow(radius, 3);
    return volume;
}

string Sphere::GetName3D() const{
    return "Sphere";
}



