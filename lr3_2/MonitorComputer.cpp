
#include "MonitorComputer.h"

#include <sstream>
#include <cmath>

// Конструктор за замовчуванням
MonitorComputer::MonitorComputer() : Computer()
{
    SetDiagonal(21.5);
}

// Конструктор з параметрами
MonitorComputer::MonitorComputer(const HardDisk& disk,
    const char* brand, double price, double diagonal)
    : Computer(disk, brand, price)
{
    SetDiagonal(diagonal);
}

// Конструктор копіювання
MonitorComputer::MonitorComputer(const MonitorComputer& other)
    : Computer(other)
{
    SetDiagonal(other.diagonal);
}

// Оператор присвоєння
MonitorComputer& MonitorComputer::operator=(
    const MonitorComputer& other)
{
    if (this != &other)
    {
        Computer::operator=(other);
        SetDiagonal(other.diagonal);
    }

    return *this;
}

// Деструктор
MonitorComputer::~MonitorComputer()
{
}

// Встановлення діагоналі
void MonitorComputer::SetDiagonal(double diagonal)
{
    if (!isfinite(diagonal) || diagonal <= 0)
        Error("Діагональ монітора має бути більшою за 0!");

    this->diagonal = diagonal;
}

// Отримання діагоналі
double MonitorComputer::GetDiagonal() const
{
    return diagonal;
}

// Функція виведення
void MonitorComputer::Show() const
{
    cout << "\n===== КОМП'ЮТЕР З МОНІТОРОМ ====="
        << endl;

    Computer::Show();

    cout << "Діагональ монітора: "
        << diagonal << " дюймів" << endl;
}

// Перетворення в рядок
MonitorComputer::operator string() const
{
    stringstream ss;

    ss << static_cast<string>(
        static_cast<const Computer&>(*this));

    ss << ", діагональ монітора: "
        << diagonal << " дюймів";

    return ss.str();
}

// Операція введення
istream& operator>>(istream& in, MonitorComputer& computer)
{
    in >> static_cast<Computer&>(computer);

    double diagonal;

    cout << "Введіть діагональ монітора: ";
    in >> diagonal;

    if (!in)
        Error("Некоректне введення діагоналі!");

    computer.SetDiagonal(diagonal);

    return in;
}

// Операція виведення
ostream& operator<<(ostream& out,
    const MonitorComputer& computer)
{
    out << static_cast<const Computer&>(computer)
        << endl;

    out << "Діагональ монітора: "
        << computer.diagonal << " дюймів";

    return out;
}
