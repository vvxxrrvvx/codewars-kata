#include <math.h>

struct point {
    int x, y;
};

double distance_from_line(struct point a, struct point b, struct point c) {
    if (a.x == b.x && a.y == b.y) {
        return sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
    }
    return fabs((b.y - a.y) * c.x - (b.x - a.x) * c.y + b.x * a.y - b.y * a.x) / sqrt(pow(b.y - a.y, 2) + pow(b.x - a.x, 2));
}