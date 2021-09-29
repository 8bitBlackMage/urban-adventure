//
// Created by alice on 19/09/2021.
//

#include "Map.h"
Map::Map()
{

}

Map::Map(std::string worldFile, ldtk::Level currentlyLoadedLevel){

}

void Map::loadWorld(std::string worldFile)
{
    LoadLevelFromOtherWorld(worldFile,1);
}

void Map::LoadLevel(int levelID) {

}

void Map::LoadLevelFromOtherWorld(std::string mapFile, int levelID) {
    currentlyLoadedWorld->loadFromFile(mapFile);
    LoadLevel(levelID);
}

std::vector<std::string *> &Map::getTexturePaths() {
    return tilesetFilePaths;
}

