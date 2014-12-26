auto clamp(float n, float lower, float upper) -> float {
    return std::max(lower, std::min(n, upper));
}
