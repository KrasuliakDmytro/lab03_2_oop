
#include <iostream>
#include <string>
#include <Windows.h>

#include "HardDisk.h"
#include "Computer.h"
#include "MonitorComputer.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ==========================================
    // 1. Створення об'єктів HardDisk
    // ==========================================

    cout << "\n===== ЖОРСТКІ ДИСКИ =====" << endl;

    HardDisk disk1;
    HardDisk disk2(2048);
    HardDisk disk3(disk2);

    cout << disk1 << endl;
    cout << disk2 << endl;
    cout << disk3 << endl;

    // ==========================================
    // 2. Створення об'єктів Computer
    // ==========================================

    cout << "\n===== КОМП'ЮТЕРИ =====" << endl;

    Computer computer1;
    Computer computer2(disk2, "ASUS", 25000);
    Computer computer3(computer2);

    computer1.Show();
    computer2.Show();
    computer3.Show();

    // ==========================================
    // 3. Створення MonitorComputer
    // ==========================================

    cout << "\n===== КОМП'ЮТЕРИ З МОНІТОРОМ ====="
        << endl;

    MonitorComputer monitor1;
    MonitorComputer monitor2(disk1, "Lenovo", 32000, 27);
    MonitorComputer monitor3(monitor2);

    monitor1.Show();
    monitor2.Show();
    monitor3.Show();

    // ==========================================
    // 4. Методи Set і Get
    // ==========================================

    cout << "\n===== МЕТОДИ SET І GET =====" << endl;

    computer2.SetPrice(28000);
    computer2.SetBrand("HP");

    monitor2.SetDiagonal(32);

    cout << "Марка: " << computer2.GetBrand() << endl;
    cout << "Ціна: " << computer2.GetPrice() << endl;

    cout << "Обсяг диска: "
        << computer2.GetDisk().GetCapacity()
        << " MB" << endl;

    cout << "Діагональ: "
        << monitor2.GetDiagonal() << " дюймів" << endl;

    // ==========================================
    // 5. Операції введення і виведення Computer
    // ==========================================

    cout << "\n===== ВВЕДЕННЯ КОМП'ЮТЕРА ====="
        << endl;

    Computer computer4;

    cin >> computer4;

    cout << "\nВведений комп'ютер:" << endl;
    cout << computer4 << endl;

    // ==========================================
    // 6. Операції введення і виведення MonitorComputer
    // ==========================================

    cout << "\n===== ВВЕДЕННЯ КОМП'ЮТЕРА З МОНІТОРОМ ====="
        << endl;

    MonitorComputer monitor4;

    cin >> monitor4;

    cout << "\nВведений комп'ютер:" << endl;
    cout << monitor4 << endl;

    // ==========================================
    // 7. Перетворення об'єктів у string
    // ==========================================

    cout << "\n===== ПЕРЕТВОРЕННЯ В STRING ====="
        << endl;

    string text1 = static_cast<string>(computer2);
    string text2 = static_cast<string>(monitor2);
    string text3 = static_cast<string>(disk2);

    cout << text1 << endl;
    cout << text2 << endl;
    cout << text3 << endl;

    // ==========================================
    // 8. Оператор присвоєння
    // ==========================================

    cout << "\n===== ОПЕРАТОР ПРИСВОЄННЯ ====="
        << endl;

    Computer computer5;
    computer5 = computer2;

    MonitorComputer monitor5;
    monitor5 = monitor2;

    computer5.Show();
    monitor5.Show();

    // ==========================================
    // 9. Статичний масив Computer
    // ==========================================

    cout << "\n===== СТАТИЧНИЙ МАСИВ =====" << endl;

    Computer computers[2];

    computers[0] = computer2;
    computers[1] = computer4;

    for (int i = 0; i < 2; i++)
    {
        computers[i].Show();
    }

    // ==========================================
    // 10. Динамічний масив Computer
    // ==========================================

    cout << "\n===== ДИНАМІЧНИЙ МАСИВ =====" << endl;

    Computer* dynamicComputers = new Computer[2];

    dynamicComputers[0] = computer1;
    dynamicComputers[1] = computer3;

    for (int i = 0; i < 2; i++)
    {
        dynamicComputers[i].Show();
    }

    delete[] dynamicComputers;

    // ==========================================
    // 11. Функція отримання і повернення базового класу
    // ==========================================

    cout << "\n===== PROCESSCOMPUTER =====" << endl;

    Computer result = ProcessComputer(monitor2);

    result.Show();

    // ==========================================
    // 12. Принцип підстановки
    // ==========================================

    cout << "\n===== ПРИНЦИП ПІДСТАНОВКИ ====="
        << endl;

    Computer* ptr = &monitor2;

    ptr->Show();

    DisplayComputer(monitor2);

    // ==========================================
    // 13. Масив похідного класу
    // ==========================================

    cout << "\n===== МАСИВ MONITORCOMPUTER ====="
        << endl;

    MonitorComputer monitors[2];

    monitors[0] = monitor2;
    monitors[1] = monitor3;

    for (int i = 0; i < 2; i++)
    {
        monitors[i].Show();
    }

    cout << "\n===== ЗАВЕРШЕННЯ ПРОГРАМИ ====="
        << endl;

    return 0;
}
