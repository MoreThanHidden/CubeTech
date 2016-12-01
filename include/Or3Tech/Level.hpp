#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <Or3Tech/Chunk.hpp>
#include <Or3Tech/TextureRegistry.hpp>
#include <Or3Tech/ChunkPos.hpp>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

class Level {
public:
	Level();
	virtual ~Level();
	void generateWorld(int x, int z, int radius);
	void loadChunk(int cX, int cZ);
	void unloadChunk(int x, int z);
	std::vector<Chunk*> Level::getLoadedChunks();
	Chunk* Level::getChunk(int x, int z);
	Block* Level::getBlock(int x, int y, int z);
	void Level::setBlock(int x, int y, int z, Block block);
	void CreateMesh(Shape * shape, TextureRegistry * texreg);
	void Level::saveChunkToFile(int i);
	bool Level::loadChunkFromFile(int x, int z, Chunk* chunk);
	void Level::generateChunk(int cX, int cZ, Chunk* chunk);

private:
	std::vector<Chunk*> loaded_chunks;
};
#endif