#include "base_spectrum.hpp"

namespace hrt {
    namespace core {
        class rgb_spectrum : public base_spectrum<3> {
        public:
            rgb_spectrum(float c = 0.f) : base_spectrum<3>(c) { }
            rgb_spectrum(const base_spectrum<3> &s) : base_spectrum<3>(s) { }

            auto to_rgb(float* rgb) -> void;
        };
    }
}
