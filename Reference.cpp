#include <iostream>
using namespace std;

struct StatInfo
{					// �ּҰ�
	int hp;			// +0
	int attack;		// +4
	int defence;	// +8
};

// [�Ű�����][RET][��������(info)] [�Ű�����(&info)][RET][��������]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// [�Ű�����][RET][��������(info)] [�Ű�����(info(100, 8, 5))][RET][��������]
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// 1) �� ���� ���
// [�Ű�����][RET][��������(info)][�Ű�����(info)][RET][��������]
void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "----------------------" << endl;
}

// 2) �ּ� ���� ���
// [�Ű�����][RET][��������(info)][�Ű�����(&info)][RET][��������]
void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "----------------------" << endl;
}

//StatInfo ����ü�� 1000����Ʈ �� ���
// - (�� ����) StatInfo�� �ѱ�� 1000����Ʈ�� �����
// - (�ּ� ����) StatInfo*�� 8����Ʈ�� �����(64��Ʈ�� ���)
// - (���� ����) StatInfo&�� 8����Ʈ�� �����

// 3) ���� ���� ���
// �� ����ó�� ���ϰ� ����ϰ�
// �ּ� ����ó�� �ּҰ��� �̿��� ���� ������ ������
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
	// 4����Ʈ ������ �ٱ��ϸ� ���
	// �� �ٱ��� �̸��� number
	// number�� ���� �ְų� ������ �ش� �ּ�(data or stack or heap)�� ���� �ְų� ��
	int number = 1;

	// * �ּҸ� ��� �ٱ���
	// int �� �ٱ��ϸ� ���󰡸� int�� ������(�ٱ���)�� ����
	int* pointer = &number;
	//pointer �ٱ��Ͽ� �ִ� �ּҸ� Ÿ�� �̵��ؼ�, �� �ָ� �ִ� �ٱ��Ͽ� 2�� �ִ´�
	*pointer = 2;

	// �ο췹��(�����) ���������� ���� �۵� ����� ������ ����(int*) �� �Ȱ���
	// ������ �����غ��� �����Ͷ� 100% �Ȱ���
	int& reference = number;
	// C++ ���������� number �ٱ��Ͽ� �� �ٸ� �̸��� �ο��� ��
	// number��� �ٱ��Ͽ� reference��� �̸��� ����
	// ������ reference�� ���� �����ų� ���� ���
	// ���� number�� ���� �����ų� ������ ��

	// �׷��� ���� ���۷����� ����ϴ� ������ �ᱹ ���� ���� ������

	reference = 3;	

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);

	return 0;
}