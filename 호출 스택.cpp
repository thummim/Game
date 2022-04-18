#include <iostream>
using namespace std;

// 함수 선언
// 나중에 헤더파일로 빠짐
void Func1();
void Func2(int hp, int mp);
void Func3(float a);
// C#에서는 상관없지만 C++에서는 이렇게 해주어야 순서에 따른 오류가 나지않음

int main()
{
	cout << "main" << endl;

	Func1();

	return 0;
}

void Func1()
{
	cout << "Func1" << endl;

	// 순서가 뒤바뀌면 호출되지 않는 이유
	// push 2
	// push 1
	// call Func2 <-- Func2를 호출할 때 찾지 못함
	
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


