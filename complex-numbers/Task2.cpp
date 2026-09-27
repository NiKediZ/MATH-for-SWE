#include <iostream>
#include <cmath>

class Complex {
private:
    double real_;   // Reaaliosa
    double imag_;   // Imaginääriosa

public:
    enum class From { Polar };

    // Konstruktorit
    // Oletuskonstruktori
    Complex(double real = 0.0, double imag = 0.0)
        : real_(real), imag_(imag) {}
    // Osoitinmuotoinen konstruktori
    Complex(double r, double theta, From)
        : real_(r * std::cos(theta)), imag_(r * std::sin(theta)) {}

    // Staattiset metodit
    static Complex fromPolar(double r, double theta) {
        return Complex(r * std::cos(theta), r * std::sin(theta));
    }

    // Hakijat Summamuoto
    double getReal() const { return real_; }
    double getImag() const { return imag_; }

    // Setterit Summamuoto
    void setReal(double real) { real_ = real; }
    void setImag(double imag) { imag_ = imag; }
    void setRectangular(double real, double imag) {
        real_ = real;
        imag_ = imag;
    }

    // Palauttaa itseisarvon
    double getMagnitude() const {
        return std::hypot(real_, imag_);
    }
    // Palauttaa vaihekulman

    double getPhase() const {
        return std::atan2(imag_, real_);
    }

    // Setteri
    void setPolar(double r, double theta) {
        real_ = r * std::cos(theta);
        imag_ = r * std::sin(theta);
    }

    // Tulostus
    void print() const {
        std::cout << real_ << " + " << imag_ << "i" << "(r = " << getMagnitude() << ", theta = " << getPhase() << " rad)\n";
    }

};

// Pääohjelma
int main() {
    Complex c1(3.0, 4.0); // summamuotoinen kompleksiluku 3 + 4i
    c1.print();

    Complex c2(5.0, 0.927295, Complex::From::Polar); // polarimuotoinen 
    c2.print();

    Complex c3 = Complex::fromPolar(5.0, M_PI / 4); // R=5, theta=45 astetta pi/4
    c3.print();

    // luetaan arvot erimuodoissa
    std::cout << "c1 Reaaliossa: " << c1.getReal() << "\n";
    std::cout << "c1 itseisarvo: " << c1.getMagnitude() << "\n";
    std::cout << "c1 kulma: " << c1.getPhase() << " rad\n";

    return 0;
}