#include "dataset.hpp"
#include <iostream>
#include <exception>

Dataset::Dataset()
{

}

std::unordered_map< std::string, Loadable* > Dataset::initializeObjects( const std::string& directoryPath )
{
	std::unordered_map< std::string, Loadable* > output;
	try
	{
		for( auto iFile : fileSystem.listFiles( mDatasetPath + directoryPath ) )
		{
			
		}
	}
	catch( std::exception& e)
	{
		std::cerr << "Dataset::initializeObjects: Standard exception: " << e.what() << ".\n";
	}
	return output;
}
