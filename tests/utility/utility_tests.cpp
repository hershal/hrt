#include <limits>

#include "utility/utility_functions.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>
#include <boost/test/execution_monitor.hpp>

BOOST_AUTO_TEST_SUITE(utility_tests)

bool clamp_is_okay(int val, int low, int high) { return is_between_inc(clamp(val, low, high), low, high); }

BOOST_AUTO_TEST_CASE(float_clamp) {

    BOOST_CHECK(clamp_is_okay(0.f, -10.f, 10.f));
    BOOST_CHECK(clamp_is_okay(-11.f, -10.f, 10.f));
    BOOST_CHECK(clamp_is_okay(11.f, -10.f, 10.f));

    BOOST_CHECK(clamp_is_okay(11.f, 0.f, 10.f));
    BOOST_CHECK(clamp_is_okay(-11.f, 0.f, 10.f));

    BOOST_CHECK(clamp_is_okay(11.f, 0.f, 10.f));
    BOOST_CHECK(clamp_is_okay(-11.f, 0.f, 10.f));
}

BOOST_AUTO_TEST_SUITE_END()
