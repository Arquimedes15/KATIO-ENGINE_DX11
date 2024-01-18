#include "katioExeciones.h"
#include <sstream>

katioExecption::katioExecption(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* katioExecption::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* katioExecption::GetType() const noexcept
{
	return "KATIO EXECPTION";
}

int katioExecption::GetLine() const noexcept
{
	return line;
}

const std::string& katioExecption::GetFile() const noexcept
{
	return file;
}

std::string katioExecption::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File]" << file << std::endl << "[Line]" << line;
	return oss.str();
}