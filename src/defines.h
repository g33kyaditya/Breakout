#ifndef DEFINES_H
#define DEFINES_H

#define WIDTH 800
#define HEIGHT 600
#define BRICKSPACING 2
#define VERTICALWINDOWSPACKING 5
#define BRICKROWS 7
#define BRICKCOLUMNS 14

namespace Game {
    template<typename T1, typename T2>
    bool isColliding(T1& A, T2& B) {

        return A.getRight() >= B.getLeft() && A.getLeft() <= B.getRight() && A.getBottom() >= B.getTop() && A.getTop() <= B.getBottom();
    }
}

#endif //DEFINES_H
