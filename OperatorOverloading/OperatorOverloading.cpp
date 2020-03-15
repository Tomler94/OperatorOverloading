#include <iostream> 
using namespace std;

class Rational
{
private:
	int a, b;

public:
	//Считывание данных с клавиатуры
	void Read();
	//Проверка введенных данных
	bool Init(Rational chislo);
	//Сложение
	Rational operator+(Rational chislo);
	//Вычитание
	Rational operator-(Rational chislo);
	//Умножение
	Rational operator*(Rational chislo);
	//Деление
	Rational operator/(Rational chislo);
	//Сравнение
	void Comparison(Rational chislo);
	//Вывод на экран
	void Display();

private:
	//Сокращение дроби
	Rational reduce(Rational drob);
};

int main()
{
	static Rational drob1, drob2, drobItog;
	int n;
	bool trigger;
	drob1.Read();
	drob2.Read();
	trigger = drob1.Init(drob2);
	if (trigger == true)
	{
		drobItog = drob1 + drob2;
		drobItog.Display();
		drobItog = drob1 - drob2;
		drobItog.Display();
		drobItog = drob1 * drob2;
		drobItog.Display();
		drobItog = drob1 / drob2;
		drobItog.Display();
		drob1.Comparison(drob2);
	}
	cin >> n;
	n *= 2;
	Rational* mass = new Rational[n];
	for (int i = 0; i < n; i += 2)
	{
		mass[i].Read(); mass[i + 1].Read();
		trigger = mass[i].Init(mass[i + 1]);
		if (trigger == true)
		{
			drobItog = mass[i] + mass[i + 1];
			drobItog.Display();
			drobItog = mass[i] - mass[i + 1];
			drobItog.Display();
			drobItog = mass[i] * mass[i + 1];
			drobItog.Display();
			drobItog = mass[i] / mass[i + 1];
			drobItog.Display();
			mass[i].Comparison(mass[i + 1]);
		}
	}
	//system("pause");
}

void Rational::Read()
{
	cin >> a >> b;
}

bool Rational::Init(Rational chislo)
{
	if ((b == 0) || (chislo.b == 0))
	{
		cout << "No" << endl;
		return false;
	}
	else return true;
}

Rational Rational::operator+(Rational chislo)
{
	Rational drob;
	drob.a = a * chislo.b + b * chislo.a;
	drob.b = b * chislo.b;
	return reduce(drob);
}
Rational Rational::operator-(Rational chislo)
{
	Rational drob;
	drob.a = a * chislo.b - b * chislo.a;
	drob.b = b * chislo.b;
	return reduce(drob);
}

Rational Rational::operator*(Rational chislo)
{
	Rational drob;
	drob.a = a * chislo.a;
	drob.b = b * chislo.b;
	return reduce(drob);
}

Rational Rational::operator/(Rational chislo)
{
	Rational drob;
	if (chislo.a != 0)
	{
		drob.a = a * chislo.b;
		drob.b = b * chislo.a;
	}
	else
	{
		drob.a = 0;
		drob.b = 0;
	}
	return reduce(drob);
}

void Rational::Comparison(Rational chislo)
{
	if (float(a) / float(b)
	> (float(chislo.a) / float(chislo.b)))
		cout << "greate" << endl;
	else if (float(a) / float(b)
		< (float(chislo.a) / float(chislo.b)))
		cout << "less" << endl;
	else
		cout << "equal" << endl;
}

void Rational::Display()
{
	if ((a || b) != 0)
		cout << a << "/" << b << endl;
}

Rational Rational::reduce(Rational drob)
{
	int num_x = drob.a,
		denom_y = drob.b,
		NOD = 1;
	if (num_x != 0)
	{
		if (num_x < 0)
			num_x = num_x * (-1);
		if (denom_y < 0)
			denom_y = denom_y * (-1);
		while (num_x != denom_y)
			if (num_x > denom_y)
				num_x = num_x - denom_y;
			else
				denom_y = denom_y - num_x;
		NOD = num_x;
	}
	if (((drob.a < 0) && (drob.b < 0)) ||
		((drob.a > 0) && (drob.b < 0)))
	{
		drob.a = drob.a * (-1);
		drob.b = drob.b * (-1);
	}
	drob.a /= NOD;
	drob.b /= NOD;
	return(drob);
}
