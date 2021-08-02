#include <math.h>

class Vector2D
{
public:
    Vector2D(float X, float Y):x(X),y(Y){};
    float getX(){return x;};
    float getY(){return y;};
    void setX(float X){x = X;};
    void setY(float Y){y = Y;};
    float lengthof(){ return sqrt(x*x + y*y);};
private:
    float x, y;

};