#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(2.0f, 2.0f);
    Point edge(5.0f, 0.0f);
    Point outside(10.0f, 10.0f);

    std::cout << "Inside (2,2): " << (bsp(a, b, c, inside) ? "IN" : "OUT") << std::endl;
    std::cout << "On Edge (5,0): " << (bsp(a, b, c, edge) ? "IN" : "OUT") << std::endl;
    std::cout << "Outside (10,10): " << (bsp(a, b, c, outside) ? "IN" : "OUT") << std::endl;

    return 0;
}
