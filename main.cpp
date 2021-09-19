#include <iostream>
#include "raylib.h"
#include "Graphics/Graphics.h"
#include "Maps/Map.h"
#include "LDtkLoader/include/LDtkLoader/World.hpp"
Graphics Display;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Display.init(240,160);
    ldtk::World world;
    world.loadFromFile("../Resources/testproj.ldtk");
    const auto & level = world.getLevel("AutoLayer");
    const auto & layer = level.getLayer("IntGrid_layer");
    const auto & tiles_vector = layer.allTiles();
    Texture2D tex = LoadTexture( ("../Resources/" + layer.getTileset().path).c_str());
    float x = 0;
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

        for (const auto &tile : tiles_vector)
        {
            Vector2 dest = {
                    static_cast<float>(tile.position.x),
                    static_cast<float>(tile.position.y),
            };
            Rectangle src = {
                    static_cast<float>(tile.texture_position.x),
                    static_cast<float>(tile.texture_position.y),
                    layer.getTileset().tile_size * ((tile.flipX == true) ? -1.0f : 1.0f),
                    layer.getTileset().tile_size * ((tile.flipY == true) ? -1.0f : 1.0f)
            };
            DrawTextureRec(tex, src, dest, WHITE);
        }
        EndMode2D();
        EndTextureMode();
        Display.DrawOutput();

        EndDrawing();
    }

    return 0;
}
