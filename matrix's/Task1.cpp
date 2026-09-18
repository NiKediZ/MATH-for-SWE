#include <iostream>
#include <array>

// Funktio matriisin laskemiseen
// | a b |
// | c d |
int laskeMatrix(const std::array<std::array<int, 2>, 2>& m) {
    //kaava laskemiseen: (a * d) - (b * c)
    return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);

}

int main() {
    //esimerkki matriisi arvoilla -20 ja 20 välillä
    std::array<std::array<int, 2>, 2> matrix = {{{-20, 14}, {9, -14}}};

    int det = laskeMatrix(matrix);

    std::cout << "Matriisin determinantti: " << det << std::endl;

    return 0;

}
