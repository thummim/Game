#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
	int temp = a;

	a = b;
	b = temp;
}

void Sort(int numbers[], int count) 
{

	for (int i = 0; i < count; i++)
	{
		// i번째 값이 제일 좋은 후보
		int best = i;
		
		// 다른 후보와 비교를 통해 제일 좋은 후보를 찾는다.
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
				best = j;
		}

		if (i != best)
			Swap(numbers[i], numbers[best]);
	}
}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));

	int count = 0;

	while (count != 6)
	{
		int randValue = 1 + (rand() % 45);

		// 이미 찾은 값인지 중복제거
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				// 이미 찾은 값
				found = true;
				break;
			}
		}

		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
}

int main()
{
	// 1) Swap 함수 만들기 
	int a = 1;
	int b = 2;
	Swap(a, b);

	// 2) 정렬 함수 만들기
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };
	Sort(numbers, sizeof(numbers) / sizeof(int));

	// 3) 로또 번호 생성
	ChooseLotto(numbers);

	return 0;
}
