#include <iostream>
#include <cmath>

int squaredSpiral(int x, int y)
{if (x==0 && y==0) return 0;if(y<0 && abs(y)>=abs(x))return pow(((y*2)-1),2)+y+x-1;if(x>0 && abs(y)<=abs(x))return(x*2-1)*(x*2-1)+(x+y-1);if(y>0 && abs(y)>=abs(x))return y*y*4-(y+x);return pow(x*2,2)+abs(x+y);}