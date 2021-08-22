//
// Created by alexe on 17/08/2021.
//



#ifndef RAYLIBTOPDOWN_GRAPHICS_H
#define RAYLIBTOPDOWN_GRAPHICS_H
#include <raylib.h>
class Graphics
        {
        public:
            void init(int Width, int Height);
            void BeginScaleDrawing();
            void EndScaleDrawing();
            void DrawOutput();

            RenderTexture2D output;

        };
#endif //RAYLIBTOPDOWN_GRAPHICS_H

