
#include "HardDisk.h"
#include <cstdlib>

// Функція повідомлення про помилку
void Error(const char* message)
{
    cout << "\nПомилка: " << message << endl;
    exit(1);
}

// Конструктор за замовчуванням
HardDisk::HardDisk()
{
    SetCapacity(1024);
}

// Конструктор з параметром
HardDisk::HardDisk(int capacity)
{
    SetCapacity(capacity);
}

// Конструктор копіювання
HardDisk::HardDisk(const HardDisk& other)
{
    SetCapacity(other.capacity);
}

// Метод встановлення обсягу
void HardDisk::SetCapacity(int capacity)
{
    if (capacity <= 0)
        Error("Обсяг жорсткого диска має бути більшим за 0!");

    this->capacity = capacity;
}

// Метод отримання обсягу
int HardDisk::GetCapacity() const
{
    return capacity;
}

// Перетворення в рядок
HardDisk::operator string() const
{
    return "Обсяг диска: " + to_string(capacity) + " MB";
}

// Операція введення
istream& operator>>(istream& in, HardDisk& disk)
{
    int capacity;

    cout << "Введіть обсяг жорсткого диска (MB): ";
    in >> capacity;

    if (!in)
        Error("Некоректне введення обсягу!");

    disk.SetCapacity(capacity);

    return in;
}

// Операція виведення
ostream& operator<<(ostream& out, const HardDisk& disk)
{
    out << "Обсяг жорсткого диска: "
        << disk.capacity << " MB";

    return out;
}
