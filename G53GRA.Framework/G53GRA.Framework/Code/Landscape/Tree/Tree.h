//
// Created by Tomas on 03/05/19.
//

#ifndef G53GRA_FRAMEWORK_TREE_H
#define G53GRA_FRAMEWORK_TREE_H


#include <Interface/DisplayableObject.h>

class Tree
        : public DisplayableObject {
public:
    Tree(float xTranslate, float yTranslate, float zTranslate, GLuint trunkTexture, GLuint leavesTexture);
    ~Tree(){};

    void Display();

private:
    float m_xTranslate;
    float m_yTranslate;
    float m_zTranslate;
    GLuint m_TrunkTex;
    GLuint m_LeavesTex;

    void DrawTrunk(float xTranslate = 0, float yTranslate = 0, float zTranslate = 0);
    void DrawBranches(float xTranslate = 0, float yTranslate = 0, float zTranslate = 0);
};


#endif //G53GRA_FRAMEWORK_TREE_H
