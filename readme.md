VK C++ industrial programming course homework
==============================

Код-стайл: Google cod-style

Задания - Sequences modification.
Были реализованы аналоги следующих 7 функций:
1) copy_n
2) fill_n
3) transform
4) find_if
5) remove_if
6) generate
7) fill

Подробнее про каждую из этих функций можно прочитать в документации: https://en.cppreference.com/w/cpp/algorithm

Инструкция по запуску:
~~~
$ mkdir build
$ cd build
$ cmake ..
$ make
~~~
Запуск юнит тестов:
~~~
$ ./test/unit/tests
~~~
Запуск интеграционных тестов, из корня проекта:
~~~
$ ./test/integr/tests
~~~
