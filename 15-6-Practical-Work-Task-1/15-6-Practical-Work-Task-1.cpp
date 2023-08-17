/*Что нужно сделать
Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве, 
что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.

a = {-2,1,-3,4,-1,2,1,-5,4}

Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, 
сумма = 6. Необходимо вывести 3 и 6.*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    int max_sum = a[0]; // Максимальная сумма подмассива -2
    int current_sum = a[0]; // Текущая сумма подмассива -2
    int start_index = 0; // Индекс начала текущего подмассива 0
    int max_start_index = 0; // Индекс начала максимального подмассива 0
    int max_end_index = 0; // Индекс конца максимального подмассива 0

    for (int i = 1; i < a.size(); ++i) {
        // Проверяем, продолжать ли текущий подмассив или начать новый
        if (a[i] > current_sum + a[i]) {  
            current_sum = a[i]; 
            start_index = i;
        }
        else {
            current_sum += a[i];
        }

        // Проверяем, является ли текущий подмассив максимальным
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_start_index = start_index;
            max_end_index = i;
        }
    }

    std::cout << "Наибольшая сумма последовательных элементов находится между индексами " << max_start_index
        << " и " << max_end_index << ": {";
    for (int i = max_start_index; i <= max_end_index; ++i) {
        std::cout << a[i];
        if (i < max_end_index) std::cout << ",";
    }
    std::cout << "}, сумма = " << max_sum << std::endl;

    return 0;
}


