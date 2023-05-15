#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
bool isThreatenedByRook(int kingX, int kingY, int rookX, int rookY) {
    // Проверяем, находится ли ладья по вертикали или горизонтали от короля
    return (kingX == rookX) || (kingY == rookY);
}

bool isThreatenedByBishop(int kingX, int kingY, int bishopX, int bishopY) {
    // Проверяем, находится ли слон на одной диагонали с королем
    return (abs(kingX - bishopX) == abs(kingY - bishopY));
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int kingX, kingY;     // Координаты короля
    int rookX, rookY;     // Координаты ладьи
    int bishopX, bishopY; // Координаты слона

    // Ввод координат с клавиатуры
    cout << "Введите координаты короля (x y): ";
    cin >> kingX >> kingY;
    cout << "Введите координаты ладьи (x y): ";
    cin >> rookX >> rookY;
    cout << "Введите координаты слона (x y): ";
    cin >> bishopX >> bishopY;

    // Проверяем, угрожает ли королю ладья или слон
    bool threatenedByRook = isThreatenedByRook(kingX, kingY, rookX, rookY);
    bool threatenedByBishop = isThreatenedByBishop(kingX, kingY, bishopX, bishopY);

    // Выводим результат
    if (threatenedByRook && threatenedByBishop) {
        cout << "Король находится под угрозой и от ладьи, и от слона." << endl;
    } else if (threatenedByRook) {
        cout << "Король находится под угрозой от ладьи." << endl;
    } else if (threatenedByBishop) {
        cout << "Король находится под угрозой от слона." << endl;
    } else {
        cout << "Король не находится под угрозой." << endl;
    }

    return 0;
}
