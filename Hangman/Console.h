#pragma once
class Console
{
public:
	static void Clear();
	static void SetCursorPosition(int x, int y);
	static void SetSize(int width, int height);

private:
	Console();
	~Console();
};
