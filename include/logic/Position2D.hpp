#ifndef POSITION2D_HPP
#define POSITION2D_HPP

struct Position2D
{
    int x;
    int y;
    Position2D() = default;
    Position2D(int x, int y) : x(x), y(y) {}
    bool operator==(const Position2D &other) const { return x == other.x && y == other.y; }
    bool operator<(const Position2D &other) const
    {
        if (x < other.x)
            return true;
        if (other.x < x)
            return false;

        if (y < other.y)
            return true;
        
        return false;
    }
};

#endif // POSITION2D_HPP