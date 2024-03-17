
#include "../dec/Bsp.hpp"

static float myAbs(float const n) {
    return (n < 0) ? -n : n;
}

static float triArea(Point const a, Point const b, Point const c) {
    float partialArea1 = a.getX().getRawBits() * (b.getY().getRawBits() - c.getY().getRawBits());
    float partialArea2 = b.getX().getRawBits() * (c.getY().getRawBits() - a.getY().getRawBits());
    float partialArea3 = c.getX().getRawBits() * (a.getY().getRawBits() - b.getY().getRawBits());

    return 0.5 * myAbs(partialArea1 + partialArea2 + partialArea3);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    float area = triArea(a, b, c);
    float area1 = triArea(point, b, c);
    float area2 = triArea(a, point, c);
    float area3 = triArea(a, b, point);
    if (area1 <= 0 || area2 <= 0 || area3 <= 0)
        return false;
    return area == area1 + area2 + area3;
}
