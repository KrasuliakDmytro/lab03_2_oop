
#include "Computer.h"

#include <cstring>
#include <sstream>
#include <cmath>

// Конструктор за замовчуванням
Computer::Computer()
{
    brand = nullptr;

    SetBrand("Unknown");
    SetPrice(1000);
}

// Конструктор з параметрами
Computer::Computer(const HardDisk& disk,
    const char* brand, double price)
{
    this->brand = nullptr;

    SetDisk(disk);
    SetBrand(brand);
    SetPrice(price);
}

// Конструктор копіювання
Computer::Computer(const Computer& other)
{
    brand = nullptr;

    SetDisk(other.disk);
    SetBrand(other.brand);
    SetPrice(other.price);
}

// Оператор присвоєння
Computer& Computer::operator=(const Computer& other)
{
    if (this != &other)
    {
        SetDisk(other.disk);
        SetBrand(other.brand);
        SetPrice(other.price);
    }

    return *this;
}

// Деструктор
Computer::~Computer()
{
    delete[] brand;
}

// Встановлення жорсткого диска
void Computer::SetDisk(const HardDisk& disk)
{
    this->disk = disk;
}

// Встановлення марки
void Computer::SetBrand(const char* brand)
{
    if (brand == nullptr || strlen(brand) == 0)
        Error("Марка комп'ютера не може бути порожньою!");

    char* newBrand = new char[strlen(brand) + 1];

    strcpy_s(newBrand, strlen(brand) + 1, brand);

    delete[] this->brand;

    this->brand = newBrand;
}

// Встановлення ціни
void Computer::SetPrice(double price)
{
    if (!isfinite(price) || price <= 0)
        Error("Ціна має бути додатною!");

    this->price = price;
}

// Отримання жорсткого диска
HardDisk Computer::GetDisk() const
{
    return disk;
}

// Отримання марки
const char* Computer::GetBrand() const
{
    return brand;
}

// Отримання ціни
double Computer::GetPrice() const
{
    return price;
}

// Функція виведення
void Computer::Show() const
{
    cout << "\n===== КОМП'ЮТЕР =====" << endl;
    cout << "Марка: " << brand << endl;
    cout << disk << endl;
    cout << "Ціна: " << price << " грн" << endl;
}

// Перетворення в рядок
Computer::operator string() const
{
    stringstream ss;

    ss << "Комп'ютер: " << brand
        << ", " << disk.GetCapacity() << " MB"
        << ", ціна: " << price << " грн";

    return ss.str();
}

// Операція введення
istream& operator>>(istream& in, Computer& computer)
{
    HardDisk disk;
    char brand[256];
    double price;

    cout << "Введіть марку комп'ютера: ";

    in >> ws;
    in.getline(brand, 256);

    if (!in)
        Error("Некоректне введення марки!");

    cout << "Введіть жорсткий диск:" << endl;
    in >> disk;

    cout << "Введіть ціну комп'ютера: ";
    in >> price;

    if (!in)
        Error("Некоректне введення ціни!");

    computer.SetDisk(disk);
    computer.SetBrand(brand);
    computer.SetPrice(price);

    return in;
}

// Операція виведення
ostream& operator<<(ostream& out, const Computer& computer)
{
    out << "Марка: " << computer.brand << endl;
    out << computer.disk << endl;
    out << "Ціна: " << computer.price << " грн";

    return out;
}

// Функція отримує і повертає об'єкт базового класу
Computer ProcessComputer(Computer computer)
{
    cout << "\nФункція отримала об'єкт базового класу."
        << endl;

    return computer;
}

// Демонстрація поліморфізму
void DisplayComputer(const Computer& computer)
{
    computer.Show();
}
