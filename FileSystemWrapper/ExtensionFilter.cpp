#include "stdafx.h"
#include "ExtensionFilter.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

namespace FileSystemWrapper
{
	ExtensionFilter::ExtensionFilter()
	{
	}

	ExtensionFilter::~ExtensionFilter()
	{
	}

	void ExtensionFilter::Add(const std::string & extension)
	{
		if (!extension.empty())
		{
			if (extension[0] != '.')
			{
				m_extensions.insert("." + extension);
			}
			else
			{
				m_extensions.insert(extension);
			}
		}
			
	}

	bool ExtensionFilter::Match(const std::string & string_to_match) const
	{
		auto path = fs::path(string_to_match);
		auto extension = path.extension().string();
		return m_extensions.count(extension) != 0;
	}
}