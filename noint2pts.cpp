int getCount(Point p, Point q)
{
    if (p.x==q.x)
        return abs(p.y - q.y) - 1;
 
    if (p.y == q.y)
        return abs(p.x-q.x) - 1;
 
    return gcd(abs(p.x-q.x), abs(p.y-q.y))-1;
}

