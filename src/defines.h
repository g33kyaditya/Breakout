#ifndef DEFINES_H
#define DEFINES_H

#define WIDTH 800
#define HEIGHT 600

namespace Game {
    template<typename T1, typename T2>
    bool isColliding(T1& A, T2& B) {

        return A.getRight() >= B.getLeft() && A.getLeft() <= B.getRight() && A.getBottom() >= B.getTop() && A.getTop() <= B.getBottom();
    }
}

#endif //DEFINES_H
