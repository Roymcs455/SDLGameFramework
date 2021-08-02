#pragma once
#include <math.h>
#include <stdio.h>
class Vector2D
{
public:
    Vector2D(float X =0, float Y=0):x(X),y(Y){};
    float getX(){return x;};
    float getY(){return y;};
    void setX(float X){x = X;};
    void setY(float Y){y = Y;};
    float lengthof(){ return sqrt(x*x + y*y);};
    Vector2D operator+(Vector2D const  &op2) 
    {
        return Vector2D(x+op2.x,y+op2.y);
    };
    friend Vector2D& operator+=(Vector2D& v1,Vector2D& v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    };
    Vector2D operator++(int i)
    {
        return Vector2D(x++,y++);
    };

    Vector2D operator-(Vector2D const &op2)
    {
        return Vector2D(x-op2.x,y-op2.y);
    };
    friend Vector2D& operator-=(Vector2D& v1,Vector2D& v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    };
    Vector2D operator*(float scalar)
    {
        return Vector2D(x*scalar,y*scalar);
    };
    Vector2D& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    };
    Vector2D operator/(float scalar)
    {
        return Vector2D(x/scalar,y/scalar);
    };
    Vector2D& operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    };

    void normalize()
    {
        float l = lengthof();
        if (l > 0)
        {
            (*this) *= 1/l;
        }
    };

private:
    float x, y;

};
