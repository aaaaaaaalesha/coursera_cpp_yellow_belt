// Copyright 2020 aaaaaaaalesha

/* include TEST FRAMEWORK */

int LinearRootCount(double b, double c) {
    if (b == 0)
        return 0;
    else
        return 1;
}

int QuadraticRootCount(double a, double b, double c) {
    double d = b * b - 4 * a * c;

    if (d < 0)
        return 0;
    else if (d == 0)
        return 1;
    else
        return 2;
}

// function
int GetDistinctRealRootCount(double a, double b, double c) {
    if (a == 0)
        return LinearRootCount(b, c);
    else
        return QuadraticRootCount(a, b, c);
}

// tests
void TestQuadraticCount() {
    AssertEqual(GetDistinctRealRootCount(10, 2, 3), 0, "D < 0 --> 0 roots");
    AssertEqual(GetDistinctRealRootCount(4, 4, 1), 1, "D == 0 --> 1 root");
    AssertEqual(GetDistinctRealRootCount(5.1, 54.3, 31), 2,
                "D > 0 --> 2 roots");
}

void TestLinearCount() {
    Assert(GetDistinctRealRootCount(0, 2, 3) == 1,
           "a == 0 & b != 0 --> 1 root");
    Assert(GetDistinctRealRootCount(0, 0, 1) == 0,
           "a == 0 & b == 0 --> 0 roots");
}


int main() {
    TestRunner runner;

    runner.RunTest(TestQuadraticCount, "Quadratic TEST");
    runner.RunTest(TestLinearCount, "Linear TEST");

    return 0;
}