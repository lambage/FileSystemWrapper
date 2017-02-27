#include "stdafx.h"
#include "Directory.h"
#include "Filter.h"
#include <experimental/filesystem>
#include <functional>

namespace fs = std::experimental::filesystem;

namespace
{
	template <typename Ret>
	Ret IterateDirectory(const std::string& path, const std::vector<std::unique_ptr<FileSystemWrapper::Filter>>& filters, std::function<bool(const fs::path&)> func)
	{
		auto p = fs::path{ path };
		if (fs::exists(p))
		{
			auto list = Ret{};
			for (auto& it : fs::directory_iterator{ p })
			{
				if (func(it))
				{
					auto file_path = it.path().string();
					for (auto& filter : filters)
					{
						if (filter->Match(file_path))
						{
							list.push_back(file_path);
						}
					}
				}
			}
			return list;
		}
		throw std::runtime_error(path + " is not a valid directory.");
	}
}

namespace FileSystemWrapper
{
	Directory::Directory(const std::string& path)
		: m_path(path)
	{
	}
	
	Directory::~Directory()
	{
	}

	void Directory::ClearFilters()
	{
		m_filters.clear();
	}

	Directory & Directory::AddFilter(std::unique_ptr<Filter> filter)
	{
		m_filters.push_back(std::move(filter));
		return *this;
	}

	FileList Directory::GetFiles() const
	{
		return IterateDirectory<FileList>(m_path, m_filters, [](const fs::path& p) { return fs::is_regular_file(p); });
	}

	DirectoryList Directory::GetSubDirectories() const
	{
		return IterateDirectory<DirectoryList>(m_path, m_filters, [](const fs::path& p) { return fs::is_directory(p); });
	}

	SortedDirectory::SortedDirectory(const std::string & path)
		: Directory(path)
	{
	}

	SortedDirectory::~SortedDirectory()
	{
	}

	FileList SortedDirectory::GetFiles() const
	{
		auto list = Directory::GetFiles();
		std::sort(std::begin(list), std::end(list));
		return list;
	}

	DirectoryList SortedDirectory::GetSubDirectories() const
	{
		auto list = Directory::GetSubDirectories();
		std::sort(std::begin(list), std::end(list));
		return list;
	}
}