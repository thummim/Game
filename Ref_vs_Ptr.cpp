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

// 특정 조건을 만족하는 몬스터를 찾는 함수
StatInfo* FindMonster()
{
	// TODO : Heap 영역에서 뭔가를 찾아봄
	// 찾았다!
	// return monster~;

	return nullptr;
}

StatInfo globalInfo;

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
void PrintInfoByPtr(const StatInfo* info)
{
	if (info == nullptr)
		return;

	if (!info)
		return;


	cout << "----------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "----------------------" << endl;

	// 별 뒤에 붙인다면?
	// StatInfo* const info
	// info라는 변수의 내용물(주소)을 바꿀 수 없음
	// info는 주소값이 들어있는 포인터 변수
	// info = &globalInfo; 가 막힘

	// 별 이전에 붙인다면?
	// const StatInfo* info
	// info가 가리키고 있는 주소값에 들어있는 데이터를 바꿀 수 없음
	// info->hp = 10000; 가 막힘

	// info[ 주소값 ]	주소값[ 데이터 ]

	/*info = &globalInfo;

	info->hp = 10000;*/
}

#define OUT

void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

//StatInfo 구조체가 1000바이트 일 경우
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사됨
// - (주소 전달) StatInfo*는 8바이트가 복사됨(64비트인 경우)
// - (참조 전달) StatInfo&는 8바이트가 복사됨

// 3) 참조 전달 방식
// 값 전달처럼 편리하게 사용하고
// 주소 전달처럼 주소값을 이용해 실제 변수에 접근함
void PrintInfoByRef(const StatInfo& info)
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
	//int number = 1;

	// * 주소를 담는 바구니
	// int 그 바구니를 따라가면 int형 데이터(바구니)가 있음
	//int* pointer = &number;
	//pointer 바구니에 있는 주소를 타고 이동해서, 그 멀리 있는 바구니에 2를 넣는다
	//*pointer = 2;

	// 로우레벨(어셈블리) 관점에서의 실제 작동 방식은 포인터 변수(int*) 와 똑같음
	// 실제로 실행해보면 포인터랑 100% 똑같음
	//int& reference = number;
	// C++ 관점에서는 number 바구니에 또 다른 이름을 부여한 것
	// number라는 바구니에 reference라는 이름을 짓고
	// 앞으로 reference에 값을 꺼내거나 넣을 경우
	// 실제 number에 값을 꺼내거나 넣으면 됨

	// 그런데 굳이 레퍼런스를 사용하는 이유는 결국 참조 전달 때문임

	//reference = 3;	

	StatInfo info;

	CreateMonster(&info);

	// 포인터 vs 참조
	// 성능 : 같음
	// 편의성 : 참조

	// 1) 편의성
	// 편의성이 좋다는게 꼭 장점은 아니다.
	// 포인터는 주소를 넘기기 때문에 확실한 원본을 넘긴다는 힌트를 줄 수 있음
	// 참조는 참조임을 모를 수도 있음
	// ex) 값을 마음대로 바꿀 경우
	// const를 사용하여 방지 가능
	// 참조와 const를 같이 사용하는 경우가 굉장히 많음

	// 포인터에도 const 사용가능

	// 2) 초기화 여부
	// 참조 타입은 변수의 2번째 이름 (별칭?)
	// -> 참조하는 대상이 없으면 안됨
	// 참조타입은 비어있으면 안됨, 즉 무언가를 참조하고 있어야 함 
	// 반면 포인터는 어떤 주소라는 의미임
	// 따라서 대상에 유효한 데이터가 없을 수도 있음
	// 포인터에서 '없다'라는 의미로 사용하려면? = nullptr
	// 참조 타입은 이런 nullptr가 들어가지 않음


	//PrintInfoByCopy(info);

	StatInfo* pointer = nullptr;
	pointer = &info;
	PrintInfoByPtr(&info);

	StatInfo& reference = info;
	PrintInfoByRef(info);

	// 뭐가 더 좋느냐고 하였을 때 답은 없다.
	// 구글은 거의 무조건 포인터
	// 언리얼 엔진은 레퍼런스도 사용

	// null도 체크해야 한다면 pointer
	// 바뀌지 않고 읽는 용도로만 사용한다면 const ref&
	// 그 외 일반적으로 ref (명시적으로 호출할 때에는 OUT을 붙인다)
	// 단, 다른 사람이 pointer를 만들어놓은걸 이어서 만든다면, 계속 pointer 사용 
	ChangeInfo(OUT info);

	// Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?
	// pointer[ 주소(&info) ]		info [ 데이터 ]

	PrintInfoByRef(*pointer);	//StatInfo& ref = *pointer; 

	// Bonus) 참조로 사용하던걸 포인터로 넘겨주려면?
	// pointer[ 주소 ]		reference, info [ 데이터 ]

	PrintInfoByPtr(&reference);	//StatInfo* ptr = &reference;

	return 0;
}
