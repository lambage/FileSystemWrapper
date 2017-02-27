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

	ExtensionFilter& ExtensionFilter::Add(const std::string & extension)
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
		return *this;
	}

	bool ExtensionFilter::Match(const std::string & string_to_match) const
	{
		auto path = fs::path(string_to_match);
		auto file = path.stem().string();
		auto extension = path.extension().string();
		return m_extensions.count(extension) != 0 && !file.empty();
	}
}