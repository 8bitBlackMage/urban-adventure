//
// Created by Alice Exley on 19/02/2022.
//
#include "string"
#include "raylib.h"
#include "map"
#ifndef RAYLIBTOPDOWN_SINGLETONRESOURCELOADER_H
#define RAYLIBTOPDOWN_SINGLETONRESOURCELOADER_H


class SingletonResourceLoader
{

    //Singleton handling
protected:
    SingletonResourceLoader() = default;


public:
    SingletonResourceLoader(SingletonResourceLoader &other) = delete;
    void operator=(const SingletonResourceLoader&) = delete;
    static SingletonResourceLoader* getInstance();


    //Resource loading functions
     std::shared_ptr<Texture2D>   loadTexture(std::string path);

private:
    std::map<std::string, Texture2D> textureList;
};

static SingletonResourceLoader * singleton;


#endif //RAYLIBTOPDOWN_SINGLETONRESOURCELOADER_H
