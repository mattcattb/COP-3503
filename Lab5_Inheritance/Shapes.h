#pragma once
#define PI 3.14159f

#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Shape{

public:
    // each derived class MUST implement this function themselves
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
};

class Shape2D : virtual public Shape{

public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;

};

class Shape3D : virtual public Shape{

public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;

};

class Square: public Shape2D{
    float sideLength;
public:

    void Scale(float scaleFactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;

    Square(float s_length=0);

};

class Triangle: public Shape2D{
    float base;
    float height;

public:
    void Scale(float scaleFactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;

    Triangle(float b=0, float h=0);

};

class Circle: public Shape2D{
    float radius;

public:
    void Scale(float scaleFactor);
    float get_radius() const;
    void Display() const;
    float Area() const;
    string GetName2D() const;

    Circle(float r=0);

};

class TriangularPyramid: public Shape3D, private Triangle{
    float pyramid_height;

public:
    TriangularPyramid(float p_h=0, float t_len=0, float t_h=0);
    
    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;

};

class Cylinder: public Shape3D, private Circle{
    float height;

public:
    Cylinder(float h=0, float r=0);

    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;

};

class Sphere: public Shape3D, private Circle{

public:

    Sphere(float r=0);

    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;

};