#pragma once

typedef int Value;

struct Set;

/**
создание нового множества
@return указатель на новое множество
*/
Set* createSet();

/**
удаление множества
@param set множество дл€ удалени€
*/
void deleteSet(Set* set);

/**
добавление элемента во множество
@param set множество дл€ добавлени€
@param value элемент дл€ добавлени€
*/
void addToSet(Set* set, Value value);

/**
удаление элемента из множества
@param set множество, из которого удал€етс€ элемент
@param value элемент, который удал€етс€
*/
void removeFromSet(Set* set, Value value);

/**
ѕечать множества в пор€дке возрастани€ элементов
¬ывод в строчку
@param set множество дл€ печати
*/
void printSetAscend(Set* set);

/**
ѕечать множества в пор€дке убывани€ элементов
¬ывод в строчку
@param set множество дл€ печати
*/
void printSetDescend(Set* set);

/**
ѕечать множества в пор€дке возрастани€ элементов
¬ывод в виде дерева
@param set множество дл€ печати
*/
void printLPR(Set* set);

/**
ѕечать множества в пор€дке убывани€ элементов
¬ывод в виде дерева
@param set множество дл€ печати
*/
void printRPL(Set* set);

/**
ѕроверка наличи€ значени€ во множестве
@param set множество дл€ поиска элемента
@param value елемент дл€ поиска
*/
bool containsInSet(Set* set, Value value);