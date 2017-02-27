#include "stdafx.h"
#include "Directory.h"

namespace FileSystemWrapper
{
	Directory::Directory(const std::string& path)
		: m_path(path)
	{
	}


	Directory::~Directory()
	{
	}
}