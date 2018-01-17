#pragma once
#include "IRunnable.h"

class Engine : IRunnable
{
public:
	Engine();
	~Engine();

	void Run() override;
};
