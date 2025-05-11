# 💾 SharpPlusPlus

**C++ библиотека, которая приносит лаконичность C# коллекций в C++ код!**  

`SharpPlusPlus` — это `List`, `Queue`, `string` и куча фич, чтобы писать код, как будто ты в 2025 году. 🚀

---

## 🔥 Что это?

`SharpPlusPlus` — библиотека, вдохновлённая C# коллекциями, с поддержкой:
- 📋 **List** — динамический массив с сортировкой, срезами и операциями.
- 📜 **String** — строка со срезами, `Split` и конкатенацией.
- 🔢 **BitArray** — Для компактного хранения и моментальных манипуляций с булевыми значениями.


- 🗄️ **Queue** — простая очередь с `Enqueue` и `Dequeue`.
- 🔗 **LinkedList** — Для эффективного добавления, удаления и доступа к элементам в двусвязном списке.
- 🌳 **SortedDictionary** — Сбалансированное бинарное дерево для упорядоченного хранения пар ключ-значение.


- 👥 **Pair** — пара значений любых типов с поддержкой сравнения и хэширования.
- 📖 **Dictionary** — хэш-таблица для быстрого доступа к значениям по ключу с рехешированием.
- 🗃️ **HashSet** — множество для уникальных элементов с быстрым поиском и вставкой.

 
- 🖨️ **print** — обёртка над `std::cout` с perfect forwarding для вывода чего угодно через запятую без копирования.

Плюс, автоматическая настройка UTF-8 для вывода на Windows (можно отключить через `#define NO_INSTALL_UTF8`) и поддержка срезов через `Substr`, `operator()` и `operator[]`. Для `List` и `string` перегружен оператор `<<`, что позволяет красиво выводить их в консоль, как списки в Python. 🛠️

---

## 📚 Подробнее по каждой коллекции
### [**📋 List**](./docs/List.md) - Динамический массив
### [**📜 String**](./docs/String.md) - Строка
### [**🔢 BitArray**](./docs/BitArray.md) - Битовый массив
### [**🗄️ Queue**](./docs/Queue.md) - Очередь (FIFO)
### [**🔗 LinkedList**](./docs/LinkedList.md) - Двусвязный список
### [**🌳 SortedDictionary**](./docs/SortedDictionary.md) - Сбалансированное бинарное дерево
### [**👥 Pair**](./docs/Pair.md) - Пара значений
### [**📖 Dictionary**](./docs/Dictionary.md) - Словарь
### [**🗃️ HashSet**](./docs/HashSet.md) - Множество


---

## 🚀 Установка

1. Склонируй репо (или скачай архивом, если лень):
   ```bash
   git clone https://github.com/boykopovar/SharpPlusPlus
   ```

2. Скопируй папку `cs` в свой проект.
3. Подключи библиотеку:
   ```c++
   #include "cs/types.h"
   ```

### Если используешь CMake:
Добавь файл `cs/types.cpp` в `add_executable`:
```cmake
add_executable(YourTarget main.cpp cs/types.cpp)
```

### Если НЕ используешь CMake:
В одном из своих `.cpp` файлов, которые компилируются, подключи (**только в одном)**:
```c++
#include "cs/types.cpp"
```

### Отключение авто-настройки UTF-8:
Если UTF-8 не нужен, добавь перед каждым включением:
```c++
#define NO_INSTALL_UTF8
#include "cs/types.h"
```

> ⚠️ **UTF-8 нюанс**: Вывод UTF-8 работает стабильно (благодаря автоматической настройке кодировки, которую можно отключить), но ввод не-ASCII символов требует самостоятельной настройки, например, `system("chcp 65001 > nul")`.

---

## 🎯 Возможности


### 📋 List
Динамический массив с методами: `append`, `Sort`, `GetRange`, `Binsearch` и операторами `+`, `+=`, `%`, `/`.  
Перегруженный `<<` выводит список как в Python.

**Пример**:
```c++
#include "cs/types.h"

int main() {
    List<int> nums = {1, 2, 3};
    nums.append(4);
    
    std::cout << nums << std::endl; // [1, 2, 3, 4]
    nums.Sort();
    
    std::cout << nums[0] << std::endl; // 1
    return 0;
}
```


---

### 📜 String
Строка с поддержкой UTF-8, срезов (`Substr`, `operator()`, `operator[]`), `Split` (по одному символу) и `Find`.

Перегруженный `<<` красиво выводит строку.

**Пример**:
```c++
#include "cs/types.h"

int main() {
    String s = "Hello мир!";
    std::cout << s.Split(",") << std::endl; // ["Hello",  "мир!"]
    std::cout << s(0, 6) << std::endl; // Hello
    return 0;
}
```

> 💡 **Split** принимает строку из одного символа (по умолчанию пробел).

---


### 📋 BitArray

Массив битов для компактного хранения и моментальных манипуляций.

**Основные методы**:
- `Set`, `Flip` — установка и инверсия битов.
- `AllTrue`, `HasTrue`, `TrueCount` — проверка и подсчёт.
- `ToString`, `ToNumber` — преобразование в строку/число.

**Операторы**:
- `[]` — доступ к битам (чтение/запись через `BitReference`).
- `<<` — вывод строки битов.

**Пример**:
```c++
#include "cs/types.h"

int main() {
    BitArray bits = {true, false, false, true};    // 1001
    bits[2] = true; // 1011
    
    std::cout << bits << std::endl; // 1011
    std::cout << bits.TrueCount() << std::endl; // 3
    return 0;
}
```


---

### 🗄️ Queue
Простая очередь с `Enqueue` и `Dequeue`.

**Пример**:
```c++
#include "cs/types.h"

int main() {
    Queue<int> q;
    
    q.Enqueue(42);
    q.Enqueue(13);
    
    std::cout << q.Dequeue() << std::endl; // 42
    return 0;
}
```


---


### 📋 LinkedList
Двусвязный список с методами: `AddFirst`, `AddLast`, `Remove`, `Find`, `First`, `Last`.  
Перегруженный `<<` выводит список в формате `[1, 2, 3]`.

**Пример**:
```c++
#include "cs/types.h"

int main() {
    LinkedList<int> list = {1, 2, 3};
    list.AddLast(4);
    
    std::cout << list << std::endl; // [1, 2, 3, 4]
    list.Remove(2);
    
    std::cout << list.First() << std::endl; // 1
    return 0;
}
```

---


### 🌳 SortedDictionary
Сбалансированное бинарное дерево с методами: `Insert`, `Remove`, `Find`, `ToList`.  
Хранит пары ключ-значение в упорядоченном виде.

**Пример**:
```c++
#include "cs/types.h"

int main() {
    SortedDictionary<int, String> dict;
    dict.Insert(1, "one");
    dict.Insert(2, "two");
    
    auto list = dict.ToList();
    // [(1, one), (2, two)]
    dict.Remove(1);
    // [(2, two)]
    return 0;
}
```


---


### 📖 Dictionary
Хэш-таблица, вдохновлённая C# и Python. Поддерживает пары ключ-значение, доступ через `[]`, сравнение и хэширование. Рехеширование при заполнении >71%. Использует `DictValueProxy` для удобной работы с значениями.

**Пример**:
```c++
#include "cs/types.h"

int main() {
    Dictionary<String, int> dict = {{"apple", 5}, {"banana", 3}};
    dict["orange"] = 7;
    std::cout << dict << std::endl; // [(orange, 7), (apple, 5), (banana, 3)]
    std::cout << dict["banana"] << std::endl; // 3
    return 0;
}
```

> 💡 **DictValueProxy** позволяет читать/записывать значения через `[]` с поддержкой операторов сравнения.

---


### 🗃️ HashSet
Хэш-множество с методами: `Insert`, `Contains`, `ToList`, `Clear`.  
Перегруженный `<<` выводит множество как список в Python.

**Пример**:
```c++
#include "cs/types.h"

int main() {
    HashSet<int> set = {10, 20, 30};
    set.Insert(40);
    
    // [10, 20, 30, 40]
    if (!set.Contains(50)) {
        // true (50 отсутствует)
    }
    auto list = set.ToList();
    // [10, 20, 30, 40]
    return 0;
}
```


---


### 📖 Pair
Шаблонная структура для хранения двух значений любых типов (`Item1`, `Item2`). Поддерживает сравнение, хэширование и вывод в формате `(Item1, Item2)`.

**Пример**:
```c++
#include "cs/types.h"

int main() {
    Pair<String, int> pair("score", 42);
    std::cout << pair << std::endl; // (score, 42)
    
    Dictionary<Pair<String, int>, String> dict;
    dict[pair] = "high";
    
    std::cout << dict[pair] << std::endl; // high
    return 0;
}
```

> 💡 **Хэширование** позволяет использовать `Pair` как ключ в `Dictionary`.


---



### 🖨️ print
Функция для вывода любых типов с perfect forwarding. Не копирует аргументы, работает с любым количеством! Представляет собой минималистичную обёртку над `std::cout`.  

**Реализация**:
```c++
template<typename T>
void print(T&& last) {
    std::cout << last << std::endl;
}

template<typename T, typename... Args>
void print(T&& first, Args&&... args) {
    std::cout << first << ' ';
    print(std::forward<Args>(args)...);
}
```
**Пример**:
```c++
#include "cs/types.h"

int main() {
    print(42, "hello", 3.14); // 42 hello 3.14
    return 0;
}
```



---

## 🛠️ Почему это круто?

- **Минимализм** — код выглядит чисто, без классического C++ нагромождения.
- **UTF-8** — автоматическая поддержка на Windows (ввод требует самостоятельной настройки).
- **Срезы** — `Substr`, `operator()`, `operator[]` для удобной работы со строками и списками.
- **Perfect Forwarding** — `print` не копирует данные, сохраняя производительность.
- **C# Вайбик** — коллекции, как в C#, но в C++!
- **Красивый вывод** — `List` и `string` выводятся в консоль прямо через `std::cout` (в случае List с аккуратным оформлением как в `Python`).

---

## 🤝 Контрибьют

Хочешь улучшить? Форкай, пулл-реквесты приветствуются! 😎  
GitHub: [**SharpPlusPlus**](https://github.com/boykopovar/SharpPlusPlus)
