#pragma once

#include "Filter.h"

namespace FileSystemWrapper
{
	class ExtensionFilter : Filter
	{
	public:
		ExtensionFilter();
		virtual ~ExtensionFilter();

		ExtensionFilter& Add(const std::string& extension);

		// Inherited via Filter
		virtual bool Match(const std::string & string_to_match) const override;

	private:
		std::set<std::string> m_extensions;
	};
}
