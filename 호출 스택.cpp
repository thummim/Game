#include <iostream>
using namespace std;

// �Լ� ����
// ���߿� ������Ϸ� ����
void Func1();
void Func2(int hp, int mp);
void Func3(float a);
// C#������ ��������� C++������ �̷��� ���־�� ������ ���� ������ ��������

int main()
{
	cout << "main" << endl;

	Func1();

	return 0;
}

void Func1()
{
	cout << "Func1" << endl;

	// ������ �ڹٲ�� ȣ����� �ʴ� ����
	// push 2
	// push 1
	// call Func2 <-- Func2�� ȣ���� �� ã�� ����
	
	Func2(1, 2);

	Func3(10.0f);
}

void Func2(int hp, int mp)
{
	cout << "Func2" << endl;

	Func3(10);
}

void Func3(float a)
{
	cout << "Func3" << endl;
}


