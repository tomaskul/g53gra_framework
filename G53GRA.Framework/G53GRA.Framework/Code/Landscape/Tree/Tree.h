//
// Created by ghost on 03/05/19.
//

#ifndef G53GRA_FRAMEWORK_TREE_H
#define G53GRA_FRAMEWORK_TREE_H


#include <Interface/DisplayableObject.h>

class Tree
        : public DisplayableObject {
public:
    Tree();
    ~Tree(){};

    void Display();

private:
    void DrawTrunk(float xTranslate = 0, float yTranslate = 0, float zTranslate = 0);
    void DrawBranches();
};


#endif //G53GRA_FRAMEWORK_TREE_H
