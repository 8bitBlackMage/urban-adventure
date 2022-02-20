//
// Created by Alice Exley on 19/02/2022.
//

#include "Layer.h"
#include "Graphics.h"

Layer::Layer(int LayerID):
layerID(LayerID),
visible(false)
{

}

void Layer::renderLayer() {
if(visible)
{
    for(auto object : renderList)
    {
        DrawTexture(*object->getTexture(), object->getX(), object->getY(), WHITE);
    }
}
}

void Layer::addAndMakeVisible(DrawableObject *childObject)
{
    addObject(childObject);
    childObject->setVisible(true);
}

void Layer::addObject(DrawableObject *childObject)
{
    if(std::find(renderList.begin(),  renderList.end(), childObject) == renderList.end())
    {
        renderList.push_back(childObject);
    }
}
