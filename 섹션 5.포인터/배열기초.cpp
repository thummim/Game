#include <iostream>
using namespace std;

struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};

int main()
{
	// TYPE 이름[개수];

	// 배열의 크기는 상수여야 한다 (VC 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// 여태껏 사용하던 변수들의 [이름]은 바구니의 이름이었음
	int a = 10;
	int b = a;

	// 그런데 배열은 [이름] 조금 다르게 동작함

	/*StatInfo players[10];
	players = monsters;*/

	// 그럼 배열의 이름은?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터

	auto WhoAmI = monsters;

	// StatInfo [ (100, 10, 1) ] StatInfo [ ] StatInfo [ ] StatInfo [ ] StatInfo [ ] ...
	// monster_0[ 주소 ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터의 덧셈! 진짜 1을 더하라는게 아니라, StatInfo 타임 바구니 한개씩 이동하라는 의미
	// StatInfo [  ] StatInfo [ 200, 20, 2) ] StatInfo [ ] StatInfo [ ] StatInfo [ ] ...
	// monster_0[ 주소 ]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조 변환
	// StatInfo [ ] StatInfo [  ] monster_2, 주소 [ ] StatInfo [ ] StatInfo [ ] ...
	// monster_0[ 주소 ]
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;	
	
	// 완전 다른의미
	// StatInfo [  ] StatInfo [ ] 주소 [ 내용물 ] StatInfo [ ] StatInfo [ ] ...
	// temp[	내용물	]
	StatInfo temp;
	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = monsters[i];
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 30 * (i + 1);
		monsters[i].defence = (i + 1);
	}
	
	// *(monsters + i)가 가독성이 떨어지고 불편하기 떄문에 더 편한 방법은?
	// 인덱스 사용
	// 배열은 0번부터 시작. N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monsters + i) = monsters[i]

	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 10;

	// 배열 초기화 문법
	int numbers[5] = {}; // 디스어셈블러로 확인시에 그냥 하나하나 접근해서 다 0으로 밀어주는 방식
	int numbers1[10] = { 1,2,3,4,5 }; // 값을 넣어준 부분은 값이 들어가고 나머지 값들은 0으로 초기화
	int numbers2[] = { 1,2,3,4,11,24,124,14,1 }; // 개수만큼의 사이즈에 해당하는 배열이 자동으로 만들어짐

	char helloStr[] = { 'H', 'e', 'l', 'l', 'o' , '\0' };

	return 0;
}
