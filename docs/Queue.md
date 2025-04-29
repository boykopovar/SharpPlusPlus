# 🗄️ Queue

Простая очередь (FIFO) с `Enqueue` и `Dequeue`. Реализована на односвязном списке. 🛠️

---

## 🔥 Основные методы

- `Enqueue(T item)` — добавляет элемент в конец.
- `Dequeue()` — извлекает первый элемент.

---

## 🎯 Пример

```c++
#include "cs/types.h"
#include <iostream>

int main() {
    Queue<int> q;
    
    q.Enqueue(42);
    q.Enqueue(13);
    
    std::cout << q.Dequeue() << std::endl; // 42
    std::cout << q.Dequeue() << std::endl; // 13
    return 0;
}
```

---

## 💡 Особенности

- Копирование и присваивание отключены для безопасности.
- Лёгкая и быстрая реализация через односвязный список.
- Поддержка любых типов данных.
