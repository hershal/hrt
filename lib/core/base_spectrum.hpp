#include <cstdint>
#include "../utility/utility_functions.hpp"

/* This is a coefficients spectrum */
namespace hrt {
    namespace core {

        template <std::size_t samples>
        class base_spectrum {
        public:
            base_spectrum(float c = 0.f) {
                for (std::size_t i=0; i<samples; ++i) {
                    this->c[i] = c;
                }
            }

            base_spectrum(const base_spectrum &s) {
                for (std::size_t i=0; i<samples; ++i) {
                    this->c[i] = s.c[i];
                }
            }

            auto operator+=(const base_spectrum &s) -> base_spectrum& {
                for (std::size_t i=0; i<samples; ++i) {
                    c[i] += s.c[i];
                }
                return *this;
            }

            auto operator+(const base_spectrum &s) const -> base_spectrum {
                base_spectrum ss = *this;
                for (std::size_t i=0; i<samples; ++i) {
                    ss.c[i] += s.c[i];
                }
                return ss;
            }

            auto operator-=(const base_spectrum &s) -> base_spectrum& {
                for (std::size_t i=0; i<samples; ++i) {
                    c[i] -= s.c[i];
                }
                return *this;
            }

            auto operator-(const base_spectrum &s) const -> base_spectrum {
                base_spectrum ss = *this;
                for (std::size_t i=0; i<samples; ++i) {
                    ss.c[i] -= s.c[i];
                }
                return ss;
            }

            auto operator*=(const base_spectrum &s) -> base_spectrum& {
                for (std::size_t i=0; i<samples; ++i) {
                    c[i] *= s.c[i];
                }
                return *this;
            }

            auto operator*(const base_spectrum &s) const -> base_spectrum {
                base_spectrum ss = *this;
                for (std::size_t i=0; i<samples; ++i) {
                    ss.c[i] *= s.c[i];
                }
                return ss;
            }

            auto operator/=(const base_spectrum &s) -> base_spectrum& {
                for (std::size_t i=0; i<samples; ++i) {
                    c[i] /= s.c[i];
                }
                return *this;
            }

            auto operator/(const base_spectrum &s) const -> base_spectrum {
                base_spectrum ss = *this;
                for (std::size_t i=0; i<samples; ++i) {
                    ss.c[i] /= s.c[i];
                }
                return ss;
            }

            auto operator==(const base_spectrum &s) const -> bool {
                for (std::size_t i=0; i<samples; ++i) {
                    if (approximately_equal(c[i], s.c[i])) {
                        return false;
                    }
                }
                return true;
            }

            auto clamp(float lower, float upper) const -> base_spectrum {
                base_spectrum ss;
                for (std::size_t i=0; i<samples; ++i) {
                    ss.c[i] = ::clamp(c[i], lower, upper);
                }
                return ss;
            }

        protected:
            /* The coefficients */
            float c[samples];
        };
    }
}
