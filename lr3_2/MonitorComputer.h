
#pragma once

#include "Computer.h"

class MonitorComputer : public Computer
{
private:
    double diagonal;

public:
    // Конструктори
    MonitorComputer();
    MonitorComputer(const HardDisk& disk, const char* brand,
        double price, double diagonal);
    MonitorComputer(const MonitorComputer& other);

    // Оператор присвоєння
    MonitorComputer& operator=(const MonitorComputer& other);

    // Деструктор
    ~MonitorComputer() override;

    // Метод встановлення
    void SetDiagonal(double diagonal);

    // Метод отримання
    double GetDiagonal() const;

    // Функція виведення
    void Show() const override;

    // Перетворення в рядок
    operator string() const;

    // Операції введення та виведення
    friend istream& operator>>(istream& in,
        MonitorComputer& computer);

    friend ostream& operator<<(ostream& out,
        const MonitorComputer& computer);
};
