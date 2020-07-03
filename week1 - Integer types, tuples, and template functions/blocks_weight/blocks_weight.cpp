// Copyright 2020 aaaaaaaalesha

#include <iostream>

int main() {
    size_t N, R;
    std::cin >> N >> R;
    uint64_t W, H, D;
    uint64_t s = 0, m;

    for (int i = 0; i < N; ++i) {
        std::cin >> W >> H >> D;
        m = W * H * D * R;
        s += m;
    }

    std::cout << s;

    return 0;
}
