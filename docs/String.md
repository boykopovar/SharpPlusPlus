# 📜 String

Класс для работы со строками. Поддерживает срезы, поиск, разделение и конкатенацию.

## 🔥 Конструкторы
- `String()` — пустая строка.
- `String(const char* text)` — из C-строки.
- `String(const std::string& s)` — из `std::string`.
- `String(const char32_t* text)` — из UTF-32.
- `String(char32_t c)` — из символа.
- `String(long double number)` — из `long double`.
- `String(long long number)` — из `long long`.
- `String(unsigned long long number)` — из `unsigned long long`.
- `String(int number)` — из `int`.

## 🛠️ Методы
- `c_str()` — C-строка.
- `Split(const String& delim = " ")` — делит по символу.
- `Strip()` — убирает пробелы.
- `IsNumber()` — проверяет, число ли.
- `Find(String c, start)` — ищет подстроку.
- `Substr(start, size)` — подстрока.
- `Size()` — длина.
- `ToDouble()` — в `double`.
- `ToInt()` — в `int`.
- `GetHash()` — хэш строки.

## ⚙️ Операторы
- `[]` — символ или срез через `Range`.
- `()` — срез, как `Substr`.
- `+`, `+=` — конкатенация.
- `==`, `!=`, `>`, `<`, `>=`, `<=` — сравнение (по длине для `>`, `<`, `>=`, `<=`).

## 🎯 Пример
```c++
#include "cs/types.h"

int main() {
    String s = "Привет, мир!";
    std::cout << s.Split(); // ["Привет,", "мир!"]
    
    print(s[0]); // П
    std::cout << s(7, 5) << '\n'; // мир!
    
    std::cout << String(42).ToInt() << '\n'; // 42
    std::cout << s.Strip().IsNumber() << '\n'; // false
}
```

## 💡 Особенности
- UTF-8 через `char32_t`.
- Срезы: `Substr`, `[]`, `()`.
- `Split` — только один символ.
- Windows: настрой UTF-8 ввод (`system("chcp 65001 > nul")`).

