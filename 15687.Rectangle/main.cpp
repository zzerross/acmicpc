#include <stdio.h>

#include "Rectangle.hpp"

int main() {
    Rectangle r(4, 5);

    r.dmp();
    r.set_width(5);
    r.set_height(5);
    r.dmp();

    return 0;
}
