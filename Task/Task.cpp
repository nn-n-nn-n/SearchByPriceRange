// Task.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "Task.h"
#include <iostream>

void AddFirst(ListItem* newList, ListItem* firstItem)
{
	ListItem* temp = new ListItem;
	temp->id = firstItem->id;
	strcpy_s(temp->name, firstItem->name);
	temp->price = firstItem->price;
	temp->count = firstItem->count;
	newList->next = temp;
}

ListItem* GetLast(ListItem* newList)
{
	if (newList == nullptr) return nullptr; // если список пуст, то вернем пустой указатель
	auto temp = newList; // временной переменной присваиваем указатель на первый элемент
	while (temp->next != nullptr) // пока ее поле next не пустой указатель (если пустой, то мы достигли последнего элемента!)
	{
		// запомните это присваивание - это переход к следующему в списке элементу
		temp = temp->next;  // перемещаемся к следующему элементу списка
	}
	return temp; // возвращаем указатель на последний элемент
}

void AddLast(ListItem* newList, ListItem* firstItem)
{
	if (firstItem == nullptr) // если список пуст, вызовем функцию добавления в начало списка
		AddFirst(newList, firstItem);
	ListItem* temp = new ListItem; // создаем в памяти новый элемент списка
	temp->id = firstItem->id;   // присваиваем полям элемента нужные значения
	strcpy_s(temp->name, firstItem->name);
	temp->price = firstItem->price;
	temp->count = firstItem->count;
	temp->next = nullptr; // нам нужно встроить элемент в конец списка, поэтому
	// указатель next настраиваем таким образом, чтобы он был пустым
	// который ранее был первым (на него указывает first)
	GetLast(newList)->next = temp;    // а теперь делаем, чтобы элемент, который до этого был последним
	// (а его мы получаем с помощью уже созданной GetLast)
	// ссылался на наш новый элемент
}


ListItem* SearchByPriceRange(ListItem* firstItem, float low, float high)
{
	if (firstItem == nullptr) return nullptr;
	ListItem* newList = new ListItem;
	while (firstItem != nullptr)
	{
		if (firstItem->price <= high && firstItem->price >= low)
		{
			//AddFirst(newList, firstItem);
			auto lastItem = GetLast(newList);
			AddLast(newList, firstItem);
		}
	}
	return newList;
}

/*
Создайте функцию, которая ищет в связном списке товаров товары с ценой, которая лежит в указанном диапазоне.
Функция возвращает в качечтве результата новый список, в который включены только те товары, цена которых
лежит в указанном диапазоне цен.

Структура элемента списка:

struct ListItem
{
    int id;
    char name[30];
    float price;
    float count;
    ListItem* next;
};

1. Функция должна иметь имя SearchByPriceRange
2. Функция в качестве параметров должна принимать следующее:
- первый параметр - указатель на первый элемент списка
- второй параметр - нижняя граница поиска цены (float)
- третий параметр - верхняя граница поиска цены (float)

3. Функция должна возвращать указатель на вновь созданный список товаров, удовлетворяющих условию. Если таких товаров нет,
   то функция должна вернуть nullptr.

Тип возвращаемого результата - ListItem*.

	!!!!! ВАЖНО !!!!!
	В данном файле разрешается разместить кроме кода требуемой функции - код любых других вспомогательных
	функций. Никакой функции main() в этом файле быть не должно.
	Если вы хотите испытать и отладить вашу функцию - пишите код в файле Example.cpp проекта Example данного решения
	Для этого задайте в качестве запускаемого проекта проект Example.

	ДЛЯ АВТОМАТИЧЕСКОГО ТЕСТИРОВАНИЯ  проверки правильности работы вашего задания - сделайте запукаемым проект
	Tests и запустите его. Если функция написана правильно - все тесты должны успешно выполниться
	(зеленый цвет в консоли). Если ваша функция работает некорректно - в консоли будут сообщения красным цветом
*/
