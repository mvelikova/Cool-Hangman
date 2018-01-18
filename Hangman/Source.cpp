#include <iostream>
#include "Engine.h"
using namespace std;

int main()
{
	Engine* engine = new Engine();
	engine->Run();

	delete engine;
	system("pause");
	return 0;
}
