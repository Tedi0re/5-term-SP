#include "Tests.h"

int main()
{
	ht::HtHandle* ht = ht::open(L"D:/HTspace.ht");
	std::cout << "test 1: " << test::TC1(ht, "test", "test1") << std::endl;
	std::cout<<"test 2: " << test::TC2(ht, "test", "test1") << std::endl;
	std::cout<<"test 3: " << test::TC3(ht, "test") << std::endl;
	std::cout<<"test 4: " << test::TC4(ht, "test1") << std::endl;
}