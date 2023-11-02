#include <iostream>	


class Monster
{
public:
	Monster()
	{ std::cout << "??"; }

	~Monster() { std::cout << "???"; }
public:
	int i = 10;
};
void main()
{
	void* ptr = malloc(1000);

	Monster* test =(Monster*) malloc(sizeof(Monster));
	Monster* m = (Monster*)ptr;

	m->i = 100;
	test->i = 1100;

	std::cout << test->i;
	free(m);
	free(ptr);

}