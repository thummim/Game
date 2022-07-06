#include <iostream>
using namespace std;

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

int main()
{
	int a = 0;
	SetNumber (&a);
	//cout << a << endl; 
	
	// .rdata Hello주소[H][e][l][l][o][\0] 
	// .rdata Bye주소[B][y][e][\0] 
	// msg[ Hello주소 ] << 8바이트 
	const char* msg = "Hello";
	
	// [매개변수][RET][지역변수msg(Hello주소))]  // 이 뒷 부분은 스택이 정리되면서 날아가면서 다중 포인터를 사용하지 않으면 값이 바뀌지 않음 [매개변수(a(Bye 주소))][RET][지역변수] 
	SetMessage(msg);
	//cout << msg << endl;
	
	// .rdata Hello주소[H][e][l][l][o][\0] 
	// msg[ Hello주소  ] << 8바이트 
	// pp[ &msg ] << 8바이트  
	const char** pp = &msg;
	
	// [매개변수][RET][지역변수msg(Hello주소))][매개변수(a(&msg msg의 주소)][RET][지역변수] 
	SetMessage(&msg);
	cout << msg << endl;
		
	return 0;
}
