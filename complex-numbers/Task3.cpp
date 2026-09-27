#include <iostream>
#include <cmath>

class Complex {
private:
    double real_;   // Reaaliosa
    double imag_;   // Imaginääriosa

public:
    enum class Form { Polar };
    // Konstruktorit
    Complex(double real = 0.0, double imag = 0.0)
        : real_(real), imag_(imag) {}
    
    Complex(double r, double theta, Form)
        : real_(r * std::cos(theta)), imag_(r * std::sin(theta)) {}

    static Complex fromPolar(double r, double theta) {
        return Complex(r * std::cos(theta), r * std::sin(theta));
    }

    // getterit ja setterit
    double getReal() const { return real_; }
    double getImag() const { return imag_; }
    void setReal(double real) { real_ = real; }
    void setImag(double imag) { imag_ = imag; }
    double getMagnitude() const { return std::hypot(real_, imag_); }
    double getPhase() const { return std::atan2(imag_, real_); }

    // sijoittavat operaattorit
    Complex& operator+=(const Complex& rhs) {
        real_ += rhs.real_;
        imag_ += rhs.imag_;
        return *this;
    }

    Complex& operator-=(const Complex& rhs) {
        real_ -= rhs.real_;
        imag_ -= rhs.imag_;
        return *this;
    }

    Complex& operator*=(const Complex& rhs) {
        double r = real_ * rhs.real_ - imag_ * rhs.imag_;
        double i = real_ * rhs.imag_ + imag_ * rhs.real_;
        real_ = r;
        imag_ = i;
        return *this;
    }

    Complex& operator/=(const Complex& rhs) {
        double denom = rhs.real_ * rhs.real_ + rhs.imag_ * rhs.imag_;
        double r = (real_ * rhs.real_ + imag_ * rhs.imag_) / denom;
        double i = (imag_ * rhs.real_ - real_ * rhs.imag_) / denom;
        real_ = r;
        imag_ = i;
        return *this;
    }
    void print() const {
        std::cout << real_ << (imag_ >= 0 ? " + " : " - ") 
                  << std::abs(imag_) << "i\n";
    }
};

    // binääriset operaattorit
    inline Complex operator+(Complex lhs, const Complex& rhs) {
        lhs += rhs;
        return lhs;
    }

    inline Complex operator-(Complex lhs, const Complex& rhs) {
        lhs -= rhs;
        return lhs;
    }

    inline Complex operator*(Complex lhs, const Complex& rhs) {
        lhs *= rhs;
        return lhs;
    }

    inline Complex operator/(Complex lhs, const Complex& rhs) {
        lhs /= rhs;
        return lhs;
    }
    // Tulostusvirtaaoperaattori
    std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.getReal() << (c.getImag() >= 0 ? " + " : " - ")
            << std::abs(c.getImag()) << "i";
        return os;
    }





int main() {
    Complex c1(3.0, 4.0); // 3 + 4i
    Complex c2(1.0, -2.0); // 1 - 2i

    Complex sum = c1 + c2;
    std::cout << "Summa: " << sum << "\n";

    // Vähennyslasku (3+4i) - (1+2i) = 2 + 2i
    Complex diff = c1 - c2;
    std::cout << "Erotus: " << diff << "\n";

    // Skalaarilla kertolasku (3+4i) * 2 = 6 + 8i
    Complex scalar1 = c1 * 2.0;
    Complex scalar2 = 3.0 * c1; // Toimii molemmin päin!
    std::cout << "c1 * 2: " << scalar1 << "\n";
    std::cout << "3 * c1: " << scalar2 << "\n";

    // Kertolasku (3+4i) * (1+2i) = (3*1 - 4*2) + (3*2 + 4*1)i = -5 + 10i
    Complex prod = c1 * c2;
    std::cout << "Tulo: " << prod << "\n";

    // Jakolasku (3+4i) / (1+2i) = (11/5) + (-2/5)i = 2.2 - 0.4i
    Complex quot = c1 / c2;
    std::cout << "Osamäärä: " << quot << "\n";

    return 0;
}