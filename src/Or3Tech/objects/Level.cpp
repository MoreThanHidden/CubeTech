#include <Or3Tech/Level.hpp>;

Level::Level(){
	generateWorld(0, 0, 6);

}

Level::~Level(){
	//remove loaded chunks
	for each (Chunk * chunk in getLoadedChunks()) {
		unloadChunk(chunk->pos.x, chunk->pos.z);
	}
}

void Level::generateWorld(int x, int z, int radius){
	int cX = x >> 3;
	int cZ = z >> 3;
	for (int px = cX-radius; px < cX+radius; px++){
		for (int pz = cZ - radius; pz < cZ + radius; pz++) {
			loadChunk(px, pz);
		}
	}
}

void Level::generateChunk(int cX, int cZ, Chunk* chunk) {
	Block block = Block(BlockType::BlockType_Grass);
	chunk->setBlock(0, 0, 0, block);
	saveChunkToFile(chunk->loadedID);
}

void Level::loadChunk(int cX, int cZ){
	ChunkPos cp = ChunkPos(cX, cZ);
	Chunk * chunk = new Chunk;
	chunk->pos.x = cX;
	chunk->pos.z = cZ;
	chunk->loadedID = loaded_chunks.size();
	loaded_chunks.push_back(chunk);
	
	if (!(loadChunkFromFile(cX, cZ, chunk))) {
		generateChunk(cX, cZ, chunk);
	}
}

void Level::unloadChunk(int cX, int cZ){
	Chunk* chunk = getChunk(cX, cZ);
	if(chunk){
		saveChunkToFile(chunk->loadedID);
		loaded_chunks.erase(loaded_chunks.begin() + chunk->loadedID);
		delete(chunk);
		//register new loaded IDs
		for (int i = 0; i < loaded_chunks.size(); i++) {
			loaded_chunks[i]->loadedID = i;
		}
	}
}

Block* Level::getBlock(int x, int y, int z){
	int cX = x >> 3;
	int cZ = z >> 3;
	Chunk *chunk = getChunk(cX, cZ);
	if (chunk)
		return &chunk->getBlock(x, y, z);
	return NULL;
}

void Level::setBlock(int x, int y, int z, Block block) {
	int cX = x >> 3;
	int cZ = z >> 3;
	Chunk *chunk = getChunk(cX, cZ);
	//TODO Check if Modulo would be better
	x -= (cX << 3);
	z -= (cZ << 3);
	if (chunk) chunk->setBlock(x, y, z, block);
}

Chunk* Level::getChunk(int x, int z){
	for (size_t i = 0; i < loaded_chunks.size(); i++){
		if ((loaded_chunks[i]->pos.x == x) && (loaded_chunks[i]->pos.z == z)) {
			return loaded_chunks[i];
		}
	}
	return NULL;	
}


std::vector<Chunk*> Level::getLoadedChunks(){
	return loaded_chunks;
}

void Level::CreateMesh(Shape * shape, TextureRegistry * texreg) {
	for each (Chunk * chunk in getLoadedChunks()){
		chunk->CreateMesh(shape, texreg);
	}
}

void Level::saveChunkToFile(int i){
	if(loaded_chunks[i] != NULL){
	std::ostringstream stream;
		std::string filename = "map";
		stream << loaded_chunks[i]->pos.x << loaded_chunks[i]->pos.z;
		filename += '/' + stream.str() + ".dat";
		stream.str("");

		std::ofstream outfile;
		outfile.open(filename.c_str(), std::ios::out | std::ios::binary);
		loaded_chunks[i]->saveToFile(outfile);
	}
}

bool Level::loadChunkFromFile(int x, int z, Chunk* chunk){
	std::ostringstream stream;
	std::string filename = "map";
	stream << x << z;
	filename += '/' + stream.str() + ".dat";
	stream.str("");

	struct stat buffer;
	if ((stat(filename.c_str(), &buffer) == 0) == false){
		return false;
	}

	std::ifstream infile;
	infile.open(filename.c_str(), std::ios::in | std::ios::binary);
	chunk->loadFromFile(infile);
	return true;
}