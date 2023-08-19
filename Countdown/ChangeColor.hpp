#include "Main.h"
/// <summary>
/// ±äÉ«
/// </summary>
void changeColor() {
    static bool foo = false;
    if (foo) {
        if (b == 0) {
            r = 255;
            g = b = 0;
            foo = false;
        }
        if (g > 0) {
            g -= 51;
            return;
        }
        if (r < 255) {
            r += 51;
            return;
        }
        if (b > 0) {
            b -= 51;
            return;
        }
    }

    if (g < 255) {
        g += 51;
        return;
    }
    if (r > 0) {
        r -= 51;
        return;
    }
    if (b < 255) {
        b += 51;
        if (b == 255) {
            foo = true;
        }
        return;
    }

}