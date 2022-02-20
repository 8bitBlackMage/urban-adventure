#include <iostream>
#include "raylib.h"
#include "Graphics/Graphics.h"
#include "Maps/Map.h"
#include "LDtkLoader/include/LDtkLoader/World.hpp"
#include "SingletonResourceLoader.h"
Graphics Display;
Map MapManager;
int main() {
    Display.init(240,160);

    //world.loadFromFile("../Resources/test2.ldtk");

   // const auto & layers = level.allLayers().at(2);
    //const auto & tiles_vector = layer.allTiles();


  //  Texture2D tex = LoadTexture( ("../Resources/" + layers.getTileset().path).c_str());
    bool debug;
    DrawableObject t;
    Layer l(0);
    l.setVisible(true);
    Display.addAndMakeVisible(&l);

    t.setTexture(SingletonResourceLoader::getInstance()->loadTexture("../Resources/heart sprite.png"));
    t.setX(100);
    t.setY(100);

    l.addAndMakeVisible(&t);
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
        Display.BeginScaleDrawing();
        BeginMode2D(camera);
        //ClearBackground(Color{level.bg_color.r,level.bg_color.g,level.bg_color.b});
        Display.DrawLayers();
        EndMode2D();
        Display.EndScaleDrawing();
        Display.DrawOutput();

        EndDrawing();
        camera.target = (Vector2){ x,y };


//        if(IsKeyDown(KEY_DOWN) && y <= level.size.y - 160)
//        {
//            y++;
//        }
//        if(IsKeyDown(KEY_UP) && y > 0)
//        {
//            y--;
//        }
//        if(IsKeyDown(KEY_RIGHT) && x <= level.size.x - 240)
//        {
//            x++;
//        }
//        if(IsKeyDown(KEY_LEFT) && x > 0)
//        {
//            x--;
//        }
        if(IsKeyDown(KEY_F11))
        {
            ToggleFullscreen();
        }
        if(IsKeyDown(KEY_CAPS_LOCK))
        {
            debug = !debug;
        }
    }

    return 0;
}
