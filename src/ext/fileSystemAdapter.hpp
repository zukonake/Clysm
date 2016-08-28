#ifndef FILESYSTEMADAPTER_HPP
#define FILESYSTEMADAPTER_HPP

#include <fstream>
#include <string>
#include <vector>
//
#include <nonCopyable.hpp>

struct FileSystemAdapter : std::fstream, NonCopyable
{
	FileSystemAdapter() = default;

	~FileSystemAdapter();

	std::vector< std::string > listFiles( const std::string& directoryPath, const std::string& targetExtension = ".lua" );
};

#endif
