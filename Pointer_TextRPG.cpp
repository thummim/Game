#include <iostream>
using namespace std;

struct StatInfo
{					// 주소값
	int hp;			// +0
	int attack;		// +4
	int defence;	// +8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
// 플레이어 승리 시에 true, 아니면 false
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	cout << "로비에 입장했습니다" << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	// [매개변수][RET][지역변수(temp(100,10,2), player(100,10,2))] [매개변수(&temp)][RET][지역변수(ret(100, 10, 2))]
	player = CreatePlayer();

	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;

	// [매개변수][RET][지역변수(monster(40, 8, 1))] [매개변수(&monster)][RET][지역변수()]
	//  결과는 같지만 중간 과정에서 오는 차이로 인해 훨씬 효율적인 선언 가능함
	CreateMonster(&monster);


	/* 구조체끼리의 복사가 일어날 때
	player = monster;
	003E25D2  mov         eax, dword ptr[monster]
	003E25D5  mov         dword ptr[player], eax
	003E25D8  mov         ecx, dword ptr[ebp - 24h]
	003E25DB  mov         dword ptr[ebp - 10h], ecx
	003E25DE  mov         edx, dword ptr[ebp - 20h]
	003E25E1  mov         dword ptr[ebp - 0Ch], edx
	
	player.hp = monster.hp;
	player.attack = monster.attack;
	player.defence = monster.defence;

	C++로 보았을 때에는 한 줄 짜리 코드이지만 많은 복사가 일어나게됨

	추후 코드가 커지거나 큰 구조체를 다룰 때에 참고해야 함	*/

	bool victory = StartBattle(&player, &monster);

	//victory가 true(1)면 승리 false(0)면 패배
	if (victory)
		cout << "승리!" << endl;
	else
		cout << "패배!" << endl;
}
 
StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;

	ret.hp		= 100;
	ret.attack	= 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp		= 40;
	info->attack	= 8;
	info->defence	= 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defence;
		
		//예외 처리
		if (damage < 0)
			damage = 0;

		//예외처리
		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;

		//몬스터 hp가 0이라면 플레이어 승
		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		cout << "플레이어 HP : " << player->hp << endl;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		if (player->hp == 0)
			return false;
	}
}
