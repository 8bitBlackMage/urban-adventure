//
// Created by alice on 19/09/2021.
//

#ifndef RAYLIBTOPDOWN_MAP_H
#define RAYLIBTOPDOWN_MAP_H
#include <string>
#include <vector>
#include <map>
#include "raylib.h"
#include "LDtkLoader/World.hpp"



class Map {
public:
    Map();
    Map(std::string worldFile, ldtk::Level currentlyLoadedLevel);

    void loadWorld(std::string worldFile);
    void LoadLevel(int levelID);
    std::vector<std::string*>& getTexturePaths();
    void populateTextures(std::map<int, Texture2D*>& data);

    void setLayerVisibility(int layerToSet,bool visibility);
    std::vector<ldtk::Tile>& getTiles();
private:
    //array of tileset texture paths that are needed by a level
    std::map<int, std::string>tilesetFilePaths;
    std::vector<std::pair<std::vector<ldtk::Tile>,bool>>allLevelTiles;
        //world file currently loaded from disk
    ldtk::World currentlyLoadedWorld;
    int currentlyLoadedLevelID;
};


#endif //RAYLIBTOPDOWN_MAP_H
