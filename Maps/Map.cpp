//
// Created by alice on 19/09/2021.
//

#include "Map.h"
#include "../SingletonResourceLoader.h"

Map::Map()
{

}

void Map::loadWorld(std::string worldFile) {
    currentlyLoadedWorld.loadFromFile(worldFile);

}

void Map::LoadLevel(int levelID)
{

}

void Map::populateTextures(std::map<int, Texture2D*> &data)
{
    for(int i = 0; i < tilesetFilePaths.size(); ++i)
    {
        //data.emplace(i,LoadTexture(tilesetFilePaths.find(i)->second.c_str() ) );
     //   data.emplace(i, SingletonResourceLoader::getInstance()->loadTexture(tilesetFilePaths.find(i)->second ));
    }
}




