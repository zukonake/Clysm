#ifndef DATASET_HPP
#define DATASET_HPP

#include <string>
#include <unordered_map>
//
#include <ext/fileSystemAdapter.hpp>

class Loadable;

class Dataset
{
	const std::string mDatasetPath = "dataset/";
public:
	Dataset();
	~Dataset();

	const Loadable* getObject( const std::string& key ) const;
private:
	std::unordered_map< std::string, Loadable* > initializeObjects( const std::string& directoryPath );

	std::unordered_map< std::string, Loadable* > objects;

	FileSystemAdapter fileSystem;
};

#endif
