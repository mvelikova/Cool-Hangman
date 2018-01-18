#pragma once
class Console
{
public:
	static void Clear();
	static void SetCursorPosition(int x, int y);
	static void SetSize(int width, int height);
	static char ReadKey();

private:
	Console();
	~Console();
};
