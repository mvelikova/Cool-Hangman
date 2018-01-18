#pragma once
class Console
{
public:
	static void Clear();
	static void SetCursorPosition( int x , int y);

private:
	Console();
	~Console();
};

