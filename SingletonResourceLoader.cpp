//
// Created by Alice Exley on 19/02/2022.
//

#include "SingletonResourceLoader.h"

SingletonResourceLoader *SingletonResourceLoader::getInstance() {
    if(singleton == nullptr)
        singleton = new SingletonResourceLoader();

    return singleton;
}

//this function is quite slow, cache the texture pointer
std::shared_ptr<Texture2D> SingletonResourceLoader::loadTexture(std::string path)
{
    auto it = textureList.find(path);
    if(it == textureList.end())
    {
        //texture not in list actually load it
        Texture t = LoadTexture(path.c_str());
        textureList[path] = t;
        return std::make_shared<Texture2D>(t) ;
    }
    else
        return std::make_shared<Texture2D>(it->second);
}


