// Copyright 2020 aaaaaaaalesha

#include <algorithm>
#include <vector>

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    // 1. Если диапазон содержит меньше 2 элементов, выходим из функции.
    if (range_end - range_begin < 2) return;

    // 2. Создаём вектор, содержащий все элементы текущего диапазона.
    std::vector<typename RandomIt::value_type> vector(range_begin, range_end);

    // 3. Разбиваем вектор на 3 равные части. [---it1--it2--]
    auto it1 = vector.size() / 3 + vector.begin();
    auto it2 = vector.size() / 3 + it1;

    // 4. Вызваем функцию MergeSort от каждой части вектора.
    MergeSort(vector.begin(), it1);
    MergeSort(it1, it2);
    MergeSort(it2, vector.end());

    // 5. Сливаем первые две трети вектора с помощью алгоритма merge, сохранив
    // результат во временный вектор с помощью back_inserter.
    std::vector<typename RandomIt::value_type> tempVector;
    std::merge(vector.begin(), it1, it1, it2, std::back_inserter(tempVector));

    // 6.Сливаем временный вектор из предыдущего пункта с последней третью вектора
    // из п. 2, записая полученный отсортированный диапазон вместо исходного.
    std::merge(tempVector.begin(), tempVector.end(), it2, vector.end(),
               range_begin);
}