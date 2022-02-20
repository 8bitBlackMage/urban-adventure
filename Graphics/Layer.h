//
// Created by Alice Exley on 19/02/2022.
//

#ifndef RAYLIBTOPDOWN_LAYER_H
#define RAYLIBTOPDOWN_LAYER_H

#include <vector>

class DrawableObject;

class Layer {
public:
    Layer(int LayerID);
    virtual void  renderLayer();
    virtual void updateLayer() {};

    void addAndMakeVisible(DrawableObject *childObject);
    void addObject(DrawableObject *childObject);

    inline void setVisible(bool v) { visible = v;}
    inline bool getVisible(){return visible;}

    int layerID;
protected:
    std::vector<DrawableObject*> renderList;
private:
    bool visible;
};


#endif //RAYLIBTOPDOWN_LAYER_H
