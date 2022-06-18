#include <iostream>
using namespace std;

void Test(int a)
{
	a++;
}

// 배열을 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환함 (char[] -> char*)
// 즉 배열 내용의 전부를 넘기지 않고 배열의 시작 주소(포인터)를 넘김
void Test(char a[])
{
	a[0] = 'x';
}

int main()
{
	// data 주소[H][e][l][l][o][W][o][r][l][d][\0]
	// test1 [ 주소 ] << 8바이트
	const char* test1 = "Hello World";

	// .data 주소 [H][e][l][l][o][W][o][r][l][d][\0]
	// [H][e][l][l][o][W][o][r][l][d][\0]
	// test2 = 주소
	char test2[] = "Hello World";

	//test2[0] = "R";

	//cout << test2 << endl;

	// 포인터는 [주소를 담는 바구니]
	// 배열은 [닭장] 즉, 그 자체로 같은 데이터끼리 붙어있는 '바구니 모음'
	// - 다만 [배열 이름]은 '바구니 모음'의 [시작 주소]

	int a = 0;
	// [매개변수][RET][지역변수(a=0)]
	Test(a);
	cout << a << endl;

	// test2는 바뀜
	Test(test2);
	cout << test2 << endl;

	return 0;
}
