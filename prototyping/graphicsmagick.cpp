#include "GraphicsMagick/Magick++.h"

int main() {

    Magick::InitializeMagick(0);

    Magick::Image i("100x100", "white");
    Magick::Color c(1.f/2, 1.f/2, 1.f/2);
    i.pixelColor(49, 49, c);

    try {
        i.write("test.png");
    } catch (std::exception e) {
        return 1;
    }

    return 0;
}
