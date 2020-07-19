// Copyright 2020 aaaaaaaalesha

#include <algorithm>
#include <vector>

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    // 1. Если диапазон содержит меньше 2 элементов, выходим из функции.
    if (range_end - range_begin < 2) return;

    // 2. Создаём вектор, содержащий все элементы текущего диапазона.
    std::vector<typename RandomIt::value_type> vector(range_begin, range_end);

    // 3. Разбиваем вектор на две равные части. (Гарантируется, что длина
    // передаваемого диапазона является степенью двойки, так что вектор всегда
    // можно разбить на две равные части.)
    auto it = vector.size() / 2 + vector.begin();

    // 4. Вызваем функцию MergeSort от каждой половины вектора.
    MergeSort(vector.begin(), it);
    MergeSort(it, vector.end());

    // 5. С помощью алгоритма merge слить отсортированные половины, записав
    // полученный отсортированный диапазон вместо исходного.
    std::merge(vector.begin(), it, it, vector.end(), range_begin);
}