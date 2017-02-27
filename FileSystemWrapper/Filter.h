#pragma once
namespace FileSystemWrapper
{
	class Filter
	{
	public:
		Filter();
		virtual ~Filter();

		virtual bool Match(const std::string& string_to_match) const = 0;
	};
}
