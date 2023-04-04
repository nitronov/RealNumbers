// RealNumbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
    // Создание бинарного файла
    std::ofstream outfile("input.dat", std::ios::binary);
    float numbers[] = { 5.0, 6.8, -10.1, -8.4, 5.6 };
    float numbers2[] = { -2.4, -8.5, -8.5, -4.8, -3.6, -8.2 };
    outfile.write(reinterpret_cast<char*>(&numbers), sizeof(numbers));
    outfile.write(reinterpret_cast<char*>(&numbers2), sizeof(numbers2));
    outfile.close();

    // Поиск максимального числа в массиве numbers
    std::ifstream infile("input.dat", std::ios::binary);
    float max_number = 0.0;
    while (infile)
    {
        float number;
        infile.read(reinterpret_cast<char*>(&number), sizeof(number));
        if (std::abs(number) > std::abs(max_number))
        {
            max_number = number;
        }
    }
    infile.close();

    // Вывод максимального числа из массива numbers на экран
    std::cout << "Самое большое по модулю число в массиве numbers: " << max_number << std::endl;

    // Поиск максимального числа в массиве numbers2
    infile.open("input.dat", std::ios::binary);
    infile.seekg(sizeof(numbers)); // переход к началу массива numbers2
    max_number = 0.0;
    while (infile)
    {
        float number;
        infile.read(reinterpret_cast<char*>(&number), sizeof(number));
        if (std::abs(number) > std::abs(max_number))
        {
            max_number = number;
        }
    }
    infile.close();

    // Вывод максимального числа из массива numbers2 на экран
    std::cout << "Самое большое по модулю число в массиве numbers2: " << max_number << std::endl;

    return 0;
}
// PS: Так и не разобрался почему при выводе перед результатом кодировка слетает