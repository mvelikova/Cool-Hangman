#pragma once
#include <string>
#include <vector>
#include "IRunnable.h"

class Engine : IRunnable
{
public:
	Engine();
	~Engine();

	void Run() override;
private:
	std::vector<std::string> words;
};

