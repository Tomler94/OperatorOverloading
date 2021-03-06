# OperatorOverloading
## Задание
Тип данных должен быть реализован в виде класса с указанными закрытыми полями, где операции реализуются в виде открытых методов класса. Требуется реализовать тип данных с помощью класса.
 Во всех заданиях обязательно должны присутствовать:
1.	Метод инициализации **Init()**; метод должен контролировать значения аргументов на корректность, при некорректных значения выводить сообщение No и заканчивать работу с этим экземпляром;
2.	Ввод с клавиатуры **Read()**;
3.	Вывод на экран **Display()**, в котором выводятся поля экземпляра и результат вычислений специфического метода;
5.	В головной функции требуется создать один статический экземпляр описанного типа и массив из n динамических экземпляров этого типа и вызвать для каждого из этих экземпляров все перечисленные методы в указанном порядке.

>Рациональная (несократимая) дробь представляется парой целых чисел (a,b), где a – >числитель, b – знаменатель. Создать класс Rational для работы с рациональными >дробями.

*Обязательно должны быть реализованы операции*:
*	cложение *add*, (a, b) + (c,d) = (ad + bc, bd);
*	вычитание *sub*, (a, b) − (c,d) = (ad − bc, bd);
*	умножение *mul*, (a, b) *  (c,d) = (ac, bd);
*	деление *div*, (a, b) + (c,d) = (ad, bc);
*	сравнение *equal*, *greate*, *less*;

*Ввод:* пара значений параметров статического объекта, число экземпляров в динамическом объекте и данные параметров динамических объектов.

*Вывод:* поля экземпляра и результаты специфических методов статического объекта, затем данные экземпляров и результаты специфических методов динамического объекта.
