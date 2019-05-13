//
// Created by ghost on 11/05/19.
//

#include "Skybox.h"

Skybox::Skybox(GLuint textureBack, GLuint textureLeft, GLuint textureFront, GLuint textureUp, GLuint textureDown,
        GLuint textureRight) : m_textureBack(textureBack), m_textureLeft(textureLeft), m_textureFront(textureFront),
        m_textureUp(textureUp), m_textureDown(textureDown), m_textureRight(textureRight)
{
}

void Skybox::Display() {
    glPushMatrix();

    // Move the skybox down to provide better environment.
    glTranslatef(0, -m_skyboxScale/2, 0);

    // Scale up the skybox for it take up whole camera.
    glScalef(m_skyboxScale, m_skyboxScale, m_skyboxScale);

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glDisable(GL_LIGHTING);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_TEXTURE_2D);

    // Right.
    glBindTexture(GL_TEXTURE_2D, m_textureRight);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 1.f, -1.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(-1.f, 1.f, 1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(-1.f, 0.f, 1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 0.f, -1.f);
    }
    glEnd();

    // Left.
    glBindTexture(GL_TEXTURE_2D, m_textureLeft);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.f, 1.f); glVertex3f(1.f, 1.f, 1.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
    }
    glEnd();

    // Front.
    glBindTexture(GL_TEXTURE_2D, m_textureFront);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(-1.f, 1.f, -1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(-1.f, 0.f, -1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
    }
    glEnd();

    // Back.
    glBindTexture(GL_TEXTURE_2D, m_textureBack);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 1.f, 1.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, 1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 0.f, 1.f);
    }
    glEnd();

    // Top.
    glBindTexture(GL_TEXTURE_2D, m_textureUp);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 1.f, 1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 1.f, 1.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 1.f, -1.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
    }
    glEnd();

    // Bottom.
    glBindTexture(GL_TEXTURE_2D, m_textureDown);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.f, 1.f); glVertex3f(-1.f, 0.f, 1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 0.f, -1.f);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);

    glPopAttrib();
    glPopMatrix();
}
