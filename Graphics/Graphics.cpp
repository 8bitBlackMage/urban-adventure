//
// Created by alexe on 17/08/2021.
//

#include "Graphics.h"
#include "iostream"

void Graphics::init(int Width, int Height) {

    InitWindow(1024,768,"testing");
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED | FLAG_MSAA_4X_HINT);
    output = LoadRenderTexture(Width,Height);
   // SetWindowMinSize(output.texture.width*4,output.texture.height*4);
    SetTargetFPS( 60);
}

void Graphics::BeginScaleDrawing()
{
    BeginTextureMode(output);
}

void Graphics::EndScaleDrawing()
{
    EndTextureMode();
}

void Graphics::DrawOutput()
{
    int widthScaleFactor = GetScreenWidth() / output.texture.width;
    int heightScaleFactor = GetScreenHeight() / output.texture.height;

    int scalefactor = 0;
    if(heightScaleFactor <= widthScaleFactor)
        scalefactor = heightScaleFactor;
    else
        scalefactor = widthScaleFactor;

    float xOffset = (GetScreenWidth() - (float)output.texture.width * scalefactor) / 2;
    float yOffset = (GetScreenHeight() - (float)output.texture.height * scalefactor) / 2;
    DrawTexturePro(output.texture,
                   Rectangle{ 0, 0, (float)output.texture.width, (float)-output.texture.height },
                   Rectangle{xOffset,yOffset,(float)output.texture.width * scalefactor, (float)output.texture.height * scalefactor},
                   Vector2{ 0, 0 },0.0, WHITE);
    DrawFPS(10,10);
}


