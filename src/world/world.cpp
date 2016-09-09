#include "world.hpp"

World::World( const Dataset& dataset ) :
	mDataset( dataset ),
	mGenerator( 123, dataset )
{

}

Chunk::Field& World::operator[]( const Point& index )
{
	if( mChunks.find( index ) == mChunks.end())
	{
		mChunks[ index ] = mGenerator.generateChunk( index.chunk( Chunk::size ));
	}
	return mChunks[ index ].fields[ index.x ][ index.y ];
}
