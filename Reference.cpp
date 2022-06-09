#include <iostream>
using namespace std;

struct StatInfo
{					// 주소값
	int hp;			// +0
	int attack;		// +4
	int defence;	// +8
};

// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// [매개변수][RET][지역변수(info)] [매개변수(info(100, 8, 5))][RET][지역변수]
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// 1) 값 전달 방식
// [매개변수][RET][지역변수(info)][매개변수(info)][RET][지역변수]
void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "----------------------" << endl;
}

// 2) 주소 전달 방식
// [매개변수][RET][지역변수(info)][매개변수(&info)][RET][지역변수]
void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "----------------------" << endl;
}

//StatInfo 구조체가 1000바이트 일 경우
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사됨
// - (주소 전달) StatInfo*는 8바이트가 복사됨(64비트인 경우)
// - (참조 전달) StatInfo&는 8바이트가 복사됨

// 3) 참조 전달 방식
// 값 전달처럼 편리하게 사용하고
// 주소 전달처럼 주소값을 이용해 실제 변수에 접근함
void PrintInfoByRef(StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "----------------------" << endl;
}


int main()
{
	// 4바이트 정수형 바구니를 사용
	// 그 바구니 이름은 number
	// number에 값을 넣거나 꺼내면 해당 주소(data or stack or heap)에 값을 넣거나 뺌
	int number = 1;

	// * 주소를 담는 바구니
	// int 그 바구니를 따라가면 int형 데이터(바구니)가 있음
	int* pointer = &number;
	//pointer 바구니에 있는 주소를 타고 이동해서, 그 멀리 있는 바구니에 2를 넣는다
	*pointer = 2;

	// 로우레벨(어셈블리) 관점에서의 실제 작동 방식은 포인터 변수(int*) 와 똑같음
	// 실제로 실행해보면 포인터랑 100% 똑같음
	int& reference = number;
	// C++ 관점에서는 number 바구니에 또 다른 이름을 부여한 것
	// number라는 바구니에 reference라는 이름을 짓고
	// 앞으로 reference에 값을 꺼내거나 넣을 경우
	// 실제 number에 값을 꺼내거나 넣으면 됨

	// 그런데 굳이 레퍼런스를 사용하는 이유는 결국 참조 전달 때문임

	reference = 3;	

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);

	return 0;
}