#include "InputWriter.h"
#include <string>
#include <algorithm>

InputWriter::InputWriter(std::ofstream& ostream) : ofs(ostream)
{
}


InputWriter::~InputWriter()
{
}

void InputWriter::Write(std::string input, std::string file_name) const
{
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	ofs.open(file_name.c_str(), std::ios::app);
	ofs << "\n" << input;
	ofs.close();
}
