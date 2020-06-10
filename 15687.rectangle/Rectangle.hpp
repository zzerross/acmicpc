#include <stdio.h>

// #define dbg

#ifdef dbg
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define _pr(fmt, ...)
#endif

class Rectangle {
    public:
        Rectangle(int width, int height): width(width), height(height) {
        }

        int get_width() const{
            // : 직사각형의 가로 길이를 리턴한다.
            return width;
        }
        int get_height() const{
            // 직사각형의 세로 길이를 리턴한다.
            return height;
        }

        void set_width(int width) {
            // 직사각형의 가로 길이를 width로 변경한다.
            // 만약, width가 0보다 작거나 같거나,
            // 1,000보다 크면 변경하지 않는다.
            if (width <= 0 || 1000 < width)
                return;

            this->width = width;
        }

        void set_height(int height) {
            // 직사각형의 세로 길이를 height로 변경한다.
            // 만약, height가 0보다 작거나 같거나,
            // 2,000보다 크면 변경하지 않는다.
            if (height <= 0 || 2000 < height)
                return;

            this->height = height;
        }

        int area() const{
            // 직사각형의 넓이를 리턴한다.
            return width * height;
        }

        int permiter() const{
            // 직사각형의 둘레 길이를 리턴한다.
            return width * 2 + height * 2;
        }

        bool is_square() const{
            // 정사각형이면 true, 아니면 false를 리턴한다.
            return width == height;
        }

        void dmp() {
#ifdef dbg
            _pr("\n%10s>\n", "Rectangle");
            _pr("%10s: %d\n", "get_width", get_width());
            _pr("%10s: %d\n", "get_height", get_height());
            _pr("%10s: %d\n", "area", area());
            _pr("%10s: %d\n", "permiter", permiter());
            _pr("%10s: %d\n", "is_square", is_square());
#endif
        }

    private:
        int width, height;
};
