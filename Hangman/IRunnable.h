#pragma once
class IRunnable
{
public:
	virtual ~IRunnable() = default;
	virtual void Run() = 0;
};
