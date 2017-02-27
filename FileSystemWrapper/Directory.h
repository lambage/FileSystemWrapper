#pragma once

#include <vector>
#include <set>
#include <memory>

namespace FileSystemWrapper
{
	using FileList = std::vector<std::string>;
	using DirectoryList = std::vector<std::string>;

	class Filter;

	class Directory
	{
	public:
		Directory(const std::string& path);
		virtual ~Directory();

		void ClearFilters();
		Directory& AddFilter(std::unique_ptr<Filter> filter);

		virtual FileList GetFiles() const;
		virtual DirectoryList GetSubDirectories() const;

	protected:
		std::string m_path;
		std::vector<std::unique_ptr<Filter>> m_filters;
	};

	class SortedDirectory : public Directory
	{
		SortedDirectory(const std::string& path);
		virtual ~SortedDirectory();

		virtual FileList GetFiles() const;
		virtual DirectoryList GetSubDirectories() const;
	};
}
