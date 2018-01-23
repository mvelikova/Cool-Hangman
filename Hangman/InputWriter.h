#pragma once
#include <fstream>
#include <string>

class InputWriter
{
private:
	std::ofstream& ofs;
public:
	InputWriter(std::ofstream& ostream);
	~InputWriter();

	void Write(std::string input, std::string file_name) const;
};
