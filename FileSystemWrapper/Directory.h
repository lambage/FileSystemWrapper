#pragma once

#include <vector>
#include <set>

namespace FileSystemWrapper
{
	using FileList = std::vector<std::string>;
	using DirectoryList = std::vector<std::string>;

	class Directory
	{
	public:
		Directory(const std::string& path);
		~Directory();



	private:
		std::string m_path;

	};
}
