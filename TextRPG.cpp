#include <iostream>
using namespace std;

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

//struct ObjectInfo
//{
//	int playerType;
//	int hp;
//	int attack;
//	int defence;
//};

int playerType;
int hp;
int attack;
int defence;

int monsterType;
int monsterHp;
int monsterAttack;
int monsterDefence;


void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	//랜덤 시드 설정, 설정하지 않고 rand사용하면 계속  동일한 값 나옴
	srand(time(0));

	EnterLobby();

	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "--------------------" << endl;
		cout << "로비에 입장했습니다!" << endl;
		cout << "--------------------" << endl;
		
		// 플레이어 직업 선택
		SelectPlayer();

		cout << "---------------------------" << endl;
		cout << "(1) 필드 입장 (2) 게임 종료" << endl;
		cout << "---------------------------" << endl;
		
		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "--------------------" << endl;
		cout << "직업을 골라주세요!" << endl;
		cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
		cout << "> ";

		cin >> playerType;

		if (playerType == PT_Knight)
		{
			cout << "기사 생성중... !" << endl;
			hp	= 150;
			attack = 10;
			defence = 5;
			break;
		}
		else if (playerType == PT_Archer)
		{
			cout << "궁수 생성중... !" << endl;
			hp = 100;
			attack = 15;
			defence = 3;
			break;
		}
		else if (playerType == PT_Mage)
		{
			cout << "법사 생성중... !" << endl;
			hp = 80;
			attack = 25;
			defence = 0;
			break;
		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << "--------------------" << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << "--------------------" << endl;

		cout << "[PLAYER] HP : " << hp << " / ATT : " << attack << " / DEF : " << defence << endl;

		CreateRandomMonster();

		cout << "--------------------" << endl;
		cout << "(1) 전투 (2) 도주" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (hp == 0)
				return;
		}
		else if (input == 2)
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	// 1~3
	monsterType = 1 + ( rand() % 3 );

	switch (monsterType)
	{
	case MT_Slime:
		cout << "슬라임 생성중...! (HP:15 / ATT:5 / DEF:0)" << endl;
		monsterHp = 15;
		monsterAttack = 5;
		monsterDefence = 0;
		break;
	case MT_Orc:
		cout << "오크 생성중...! (HP:40 / ATT:10 / DEF:3)" << endl;
		monsterHp = 40;
		monsterAttack = 10;
		monsterDefence = 3;
		break;
	case MT_Skeleton:
		cout << "스켈레톤 생성중...! (HP:80 / ATT:15 / DEF:5)" << endl;
		monsterHp = 80;
		monsterAttack = 15;
		monsterDefence = 5;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = attack - monsterDefence;
		if (damage < 0) // 몬스터의 방어력이 플레이어의 공격력보다 높은 경우 보정
			damage = 0;

		//플레이어가 공격하는 상황
		monsterHp -= damage;
		if (monsterHp < 0) // 몬스터의 체력이 음수가 되는경우 보정
			monsterHp = 0;

		cout << "몬스터 남은 체력 : " << monsterHp << endl;
		if (monsterHp == 0)
		{
			cout << "몬스터를 처치했습니다!" << endl;
			return;
		}

		damage = monsterAttack - defence;
		if (damage < 0) // 몬스터의 방어력이 플레이어의 공격력보다 높은 경우 보정
			damage = 0;

		//몬스터가 공격하는 상황
		hp -= damage;
		if (hp < 0)
			hp = 0;

		cout << "플레이어 남은 체력 : " << hp << endl;
		if (hp == 0)
		{
			cout << "당신은 사망했습니다... GAME OVER" << endl;
			return;
		}

	}
}