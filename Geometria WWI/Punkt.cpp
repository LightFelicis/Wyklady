#include <iostream>

template <typename T>
class Punkt {
public:
    Punkt(T x, T y) : m_x(x), m_y(y) {}

    T m_x;
    T m_y;
};

template <typename T>
Punkt<T> operator-(const Punkt<T>& A, const Punkt<T>& B) {
    return Punkt<T>(A.m_x - B.m_x, A.m_y - B.m_y);
}

template <typename T>
Punkt<T> operator+(const Punkt<T>& A, const Punkt<T>& B) {
    return Punkt<T>(A.m_x + B.m_x, A.m_y + B.m_y);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Punkt<T>& Obj) {
    return out << "(" << Obj.m_x << " " << Obj.m_y << ")\n";
}

int main() {
    Punkt <long double> A(0.5, 0.2);
    Punkt <long double> B(1.3, 2.0);
    Punkt <int> C(0, 3);
    auto Roznica = A - B;
    // auto Roznica2 = A - C;   <----------- Nie skompiluje się, bo zdefiniowaliśmy tylko odejmowanie
                                //           punktów o takim samym typie T.
    std::cout << Roznica;       // Przydatne w debugu : )
}