#include <iostream>
#include <array>
#include <optional> // jos det on 0, niin palautetaan std::nullopt

//det lasku funktio
int laskeMatrix(const std::array<std::array<int, 2>, 2>& m) {
    //kaava laskemiseen: (a * d) - (b * c)
    return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);

}

std::optional<std::array<std::array<double, 2>, 2>> laskeKaanteis(const std::array<std::array<int, 2>, 2>& m) {
    int det = laskeMatrix(m);

    //tarkastetaan determinantin arvo
    if (det == 0) {
        return std::nullopt; // ei käänteismatriisia
    }

    // Luetaan alkiot matriisista
    double a = m[0][0];
    double b = m[0][1]; 
    double c = m[1][0];
    double d = m[1][1];

    //Cramerin sääntö
    std::array<std::array<double, 2>, 2> kaanteis = {{
        { d / det, -b / det },
        { -c / det, a / det }
    }};
    //palautetaan käänteismatriisi
    return kaanteis;
}

int main() {
    //esimerkkimatriisi
    // |10 12|
    // |-1 -19|

    std::array<std::array<int, 2>, 2> m = {{{10, 12}, {-1, -19}}};

    auto tulos = laskeKaanteis(m);

    if (tulos.has_value()) {
        auto inv = tulos.value();
        std::cout << "Käänteismatriisi:\n";
        std::cout << "| " <<inv[0][0] << " " << inv[0][1] << " |\n";
        std::cout << "| " <<inv[1][0] << " " << inv[1][1] << " |\n";
    } else {
        std::cout << "Matriisi ei ole käännettävissä (det = 0).\n";
    }
    
    return 0;
}