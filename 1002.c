#include <stdio.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
typedef struct _circle {
    int x;
    int y;
    int r;
}Circle;

int DistSquare(const Circle* c1, const Circle* c2)
{
    return ((c1->x - c2->x) * (c1->x - c2->x)) +
            ((c1->y - c2->y) * (c1->y - c2->y));
}
int Square(int n)
{
    return n * n;
}
int CalcSameCords(const Circle* c1, const Circle* c2)
{
    if (c1->r == c2->r)
        return -1;
    else
        return 0;
}
int CalcOuter(const Circle* c1, const Circle* c2)
{
    if (DistSquare(c1, c2) > Square(c1->r + c2->r))
        return 0;
    else if (DistSquare(c1, c2) == Square(c1->r + c2->r))
        return 1;
    else
        return 2;
}

int CalcIner(const Circle* c1, const Circle* c2)
{
    if (DistSquare(c1, c2) > Square(max(c1->r, c2->r) - min(c1->r, c2->r)))
        return 2;
    else if (DistSquare(c1, c2) < Square(max(c1->r, c2->r) - min(c1->r, c2->r)))
        return 0;
    else
        return 1;
}

int main()
{
    int t, x1, y1, r1, x2, y2, r2;
    int result;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        Circle c1 = {x1, y1, r1};
        Circle c2 = {x2, y2, r2};
        if (c1.x == c2.x && c1.y ==  c2.y) {
            // Same x, y location
            result = CalcSameCords(&c1, &c2);
        } else if (DistSquare(&c1, &c2) > Square(max(c1.r, c2.r))) {
            // if Distance between two circle is larger than radius of bigger(radius) circle,
            // smaller(radius) circle is not in the larger circle.
            result = CalcOuter(&c1, &c2);
        } else {
            // smaller circle is in the bigger circle.
            result = CalcIner(&c1, &c2);
        }
        printf("%d\n", result);
    }
    return 0;
}