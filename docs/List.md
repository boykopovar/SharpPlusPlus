# 📋 List

Динамический массив, вдохновлённый C# `List<T>`. Поддерживает добавление, сортировку, срезы, бинарный поиск и операторы для объединения и разделения. 🚀

---

## 🔥 Основные методы

- `append(T item)` — добавляет элемент в конец.
- `Sort(SortType type = QuickSort)` — сортировка (выбирай из `QuickSort`, `HeapSort`, `MergeSort`, `InterpolationSort`). По умолчанию `QuickSort`.
- `GetRange(start, count)` — возвращает подсписок.
- `Binsearch(T item)` — бинарный поиск.
- `Clear()` — очищает список.
- `Size()` — возвращает размер.
- `capacity()` — возвращает текущую ёмкость.


> 💡 **SortType**: Перечисление `SortType { QuickSort, HeapSort, MergeSort, InterpolationSort }` автоматически импортируется с `#include "cs/types.h"`.

> ❓ **MiracleSort?** Сори, пока не завез, молись и жди чуда! 😜



## 🛠️ Операторы

- `[]` — доступ к элементу по индексу.
- `+`, `+=` — объединение списков.
- `%` — разбиение на подсписки по количеству элементов в каждом.
- `/` — разбиение на заданное количество подсписков.

---

## 🎯 Пример

```c++
#include "cs/types.h"

int main() {
    List<int> nums = {3, 1, 2};
    nums.append(4);
    nums.Sort(QuickSort);
    std::cout << nums << std::endl; // [1, 2, 3, 4]
    std::cout << nums.GetRange(1, 2) << std::endl; // [2, 3]
    return 0;
}
```

### Операторы `%` и `/`
- `%` делит список на подсписки, где каждый (или не каждый, если нацело не делится) содержит указанное количество элементов.
- `/` делит список на указанное количество подсписков, распределяя элементы равномерно (если нацело не делиться, то последний будет не полным).

```c++
#include "cs/types.h"

int main() {
    List<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << list / 3 << std::endl; // [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10]]
    std::cout << list % 3 << std::endl; // [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10]]
    return 0;
}
```

---

## 💡 Особенности

- Итераторы через `begin()` и `end()` позволяют использовать в цикле for с `:`.
- Динамическое выделение памяти с управлением через `SetCapacity`.
- Поддержка любых типов (можно даже создать что-то типа `List<List<int>>`), включая пользовательские (чтобы для пользовательского типа работала сортировка, для него должны быть перегружены операторы сравнения). 
- Красивый вывод через `<<`, как списки в Python.

