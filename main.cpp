#include <iostream>
#include "raylib.h"
#include "Graphics/Graphics.h"
#include "Maps/Map.h"
#include "LDtkLoader/include/LDtkLoader/World.hpp"
Graphics Display;
Map MapManager;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Display.init(240,160);
    ldtk::World world;
    world.loadFromFile("../Resources/test2.ldtk");
    const auto & level = world.allLevels().at(0);
   // const auto & layers = level.allLayers().at(2);
    //const auto & tiles_vector = layer.allTiles();
    std::vector<Texture2D> tilesets;
    for(const auto & layer: level.allLayers())
    {
        if(layer.hasTileset())
            tilesets.push_back(LoadTexture(("../Resources/" + layer.getTileset().path).c_str()));
        else
            tilesets.push_back(Texture());
    }

  //  Texture2D tex = LoadTexture( ("../Resources/" + layers.getTileset().path).c_str());
    float x = 0;
    float y = 0;
    Camera2D camera = {0};
    camera.target = (Vector2){ 0,0 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    while(!WindowShouldClose())
    {



        BeginDrawing();
        ClearBackground(BLACK);
        BeginTextureMode(Display.output);
        BeginMode2D(camera);
        ClearBackground(WHITE);
        int layerNum = level.allLayers().size();
        for(auto layer = level.allLayers().rbegin(); layer != level.allLayers().rend(); layer++)
        {
            const auto & tiles_vector = layer->allTiles();
            for (const auto &tile: tiles_vector) {


                Vector2 dest = {
                        static_cast<float>(tile.position.x),
                        static_cast<float>(tile.position.y),
                };
                Rectangle src = {
                        static_cast<float>(tile.texture_position.x),
                        static_cast<float>(tile.texture_position.y),
                        layer->getTileset().tile_size * ((tile.flipX == true) ? -1.0f : 1.0f),
                        layer->getTileset().tile_size * ((tile.flipY == true) ? -1.0f : 1.0f)
                };
                DrawTextureRec(tilesets.at(layerNum -1), src, dest, WHITE);
            }
            layerNum--;
        }

        EndMode2D();
        EndTextureMode();
        Display.DrawOutput();

        EndDrawing();
        camera.target = (Vector2){ x,y };


        if(IsKeyDown(KEY_DOWN) && y <= level.size.y - 160)
        {
            y++;
        }
        if(IsKeyDown(KEY_UP) && y > 0)
        {
            y--;
        }
        if(IsKeyDown(KEY_RIGHT) && x <= level.size.x - 240)
        {
            x++;
        }
        if(IsKeyDown(KEY_LEFT) && x > 0)
        {
            x--;
        }
        if(IsKeyDown(KEY_F11))
        {
            ToggleFullscreen();
        }
    }

    return 0;
}
