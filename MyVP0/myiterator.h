

template<typename T>
class Iterator {
// делаем внешний класс дружественным к подклассу
// чтобы он имел доступ к нашим закрытым свойствам
friend class Vector;
public:
// пишем конструктор копирования
// который будет производить инициализацию членов класса
// тело конструктора будет пустым
Iterator(const Iterator& it) : m_pElement(it.m_pElement) {}
// перегружаем оператор сравнения
bool operator==(const Iterator& it) const {
return m_pElement == it.m_pElement;
}
// перегружаем оператор неравенства
bool operator!=(const Iterator& it) const {
return m_pElement != it.m_pElement;
}
// перегружаем оператор инкремента
Iterator& operator++() {
++m_pElement;
return *this;
}
Iterator& operator--() {
--m_pElement;
return *this;
}
Iterator& operator-(int a) {
m_pElement-=a;
return *this;
}
Iterator& operator+(int a) {
m_pElement+=a;
return *this;
}
// перегружаем оператор разыменования указателя
T& operator*()  {
return *m_pElement;
}

Iterator(T* p) : m_pElement(p) {}
private:
T* m_pElement{};
// создаём закрытый конструктор инициализации членов класса

};
