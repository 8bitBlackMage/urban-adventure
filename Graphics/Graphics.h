//
// Created by alexe on 17/08/2021.
//



#ifndef RAYLIBTOPDOWN_GRAPHICS_H
#define RAYLIBTOPDOWN_GRAPHICS_H
#include <raylib.h>
#include "Layer.h"
#include <memory>
class Graphics
        {
public:
            void init(int Width, int Height);
            void BeginScaleDrawing();
            void EndScaleDrawing();

            void DrawLayers();

            void DrawOutput();

            void addLayer(Layer *l);
            void addAndMakeVisible(Layer* l);
private:
            RenderTexture2D output;
            std::vector<Layer*> layers;
        };


class DrawableObject
{
public:
    [[nodiscard]]       inline Rectangle    getBounds()   const         {return bounds;}
    [[nodiscard]]       inline Vector2      getSize()     const         {return Vector2{bounds.width, bounds.height};}
    [[nodiscard]]       inline Vector2      getPosition() const         {return Vector2{bounds.x,bounds.y};}

    [[nodiscard]]       inline float          getX() const              {return bounds.x;}
    [[nodiscard]]       inline float          getY() const              {return bounds.y;}
    [[nodiscard]]       inline float          getWidth() const          {return bounds.width;}
    [[nodiscard]]       inline float          getHeight() const         {return bounds.height;}
    [[nodiscard]]       inline bool          getIsVisible() const      {return visible;}
    inline void  setBounds(Rectangle b) {bounds = b;}
    inline void  setSize(Vector2 s) {bounds.width = s.x; bounds.height = s.y;}
    inline void  setPosition(Vector2 p) {bounds.x = p.x; bounds.y = p.y;}
    inline void  setX(float x) {bounds.x = x;}
    inline void  setY(float y) {bounds.y = y;}
    inline void  setWidth(float w) {bounds.width = w;}
    inline void  setHeight(float h) {bounds.height = h;}
    inline void  setVisible(bool v){ visible = v;}
    void setTexture(std::shared_ptr<Texture2D> t ){if(t != nullptr) texToDraw = t; }
    std::shared_ptr<Texture2D> getTexture() {return texToDraw;}
private:
    Rectangle bounds;
    std::shared_ptr<Texture2D> texToDraw;
    bool visible;
};

#endif //RAYLIBTOPDOWN_GRAPHICS_H

