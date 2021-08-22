#include <iostream>
#include "raylib.h"
#include "Graphics/Graphics.h"
Graphics Display;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Display.init(240,160);
    float x = 0;
    float y = 0;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        BeginTextureMode(Display.output);
       // ClearBackground(WHITE);
        DrawPixel(x,y, Color{(unsigned char)GetRandomValue(0,0),(unsigned char)GetRandomValue(0,255),(unsigned char)GetRandomValue(0,0),255});
        EndTextureMode();
        Display.DrawOutput();

        EndDrawing();
        x++;
        if(x == 240)
        {
            x = 0;
            y++;
            if(y == 160)
            {
                y =0;
            }
        }

    }
    return 0;
}
