#include <iostream>
#include <array>

// Funktio matriisin laskemiseen
// | a b |
// | c d |
int laskeMatrix(const std::array<std::array<int, 2>, 2>& m) {
    //kaava laskemiseen: (a * d) - (b * c)
    return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);

}

int kysyArvo(char nimi) {
    int arvo;
    while (true) {
        std::cout << "Anna alkion arvo väliltä (-20 ja 20): ";
        std::cin >> arvo;

        //tarkistetaan, että arvo on rajojen sisällä
        if (arvo >= -20 && arvo <= 20) {
            return arvo;
        } else {
            std::cout << "Alkion arvo ei ole rajojen sisällä. Yritä uudelleen.\n" << std::endl;
        }
    }
}

int main() {

    // luetaan arvot apufunktion avulla
    int a = kysyArvo('a');
    int b = kysyArvo('b');
    int c = kysyArvo('c');
    int d = kysyArvo('d');
    //esimerkki matriisi arvoilla -20 ja 20 välillä
    //std::array<std::array<int, 2>, 2> matrix = {{{-20, 14}, {9, -14}}};

    //sijoitetaan käyttäjän syöttämät arvot matriisiin
    std::array<std::array<int, 2>, 2> matrix = {{{a, b}, {c, d}}};

    int det = laskeMatrix(matrix);

    std::cout << "Matriisin determinantti: " << det << std::endl;

    return 0;

}
