    #include "funcionesDiaz.h"


   int obtenerMaximo(int x, int y, int z)
{
    int max;

    if( y > x && y > z)
    {
        max = y;
    }
    else if( x > y && x > z)
    {
        max = x;
    }
    else
    {
        max = z;
    }

    return max;

