//
// Created by ghost on 11/05/19.
//

#ifndef G53GRA_FRAMEWORK_SKYBOX_H
#define G53GRA_FRAMEWORK_SKYBOX_H


#include <Interface/DisplayableObject.h>

class Skybox :
        public DisplayableObject
{
public:
    Skybox(GLuint textureBack, GLuint textureLeft, GLuint textureFront, GLuint textureUp, GLuint textureDown,
            GLuint textureRight);
    ~Skybox(){};

    void Display();

private:
    const float m_skyboxScale = 500.0f;
    GLuint m_textureBack, m_textureLeft, m_textureFront, m_textureUp, m_textureDown, m_textureRight;
};


#endif //G53GRA_FRAMEWORK_SKYBOX_H
