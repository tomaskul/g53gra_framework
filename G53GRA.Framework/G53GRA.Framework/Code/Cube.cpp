#include "Cube.h"

Cube::Cube() :
        _flagReset(false), _iKey(false), _jKey(false), _kKey(false),
        _lKey(false), _oKey(false), _uKey(false), _plusKey(false), _minusKey(false),
        _upKey(false), _downKey(false), _leftKey(false), _rightKey(false)
{
    size(_INIT_SIZE);
}

void Cube::Display()
{
    glPushMatrix();



    //put in first position
    glTranslatef(pos[0], pos[1], pos[2]);

    //scale object
    glScalef(scale[0], scale[1], scale[2]);

    // Rotate object in new position, in order y>z>x axes
    glRotatef(rotation[1], 0.0f, 1.0f, 0.0f); // angle ry about (0,1,0)
    glRotatef(rotation[2], 0.0f, 0.0f, 1.0f); // angle rz about (0,0,1)
    glRotatef(rotation[0], 1.0f, 0.0f, 0.0f); // angle rx about (1,0,0)

    //call the function to draw the cube
    DrawCube();



    glPopMatrix();
}

void Cube::DrawCube()
{
    /*
    A
    glVertex3f(-1,1,1);
    B
    glVertex3f(1,1,1);
    C
    glVertex3f(-1,-1,1);
    D
    glVertex3f(1,-1,1);
    E
    glVertex3f(-1,-1,-1);
    F
    glVertex3f(1,-1,-1);
    G
    glVertex3f(1,1,-1);
    H
    glVertex3f(-1,1,-1);

    */

    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_TRIANGLES);

    //draw the tetrahedron
    //side 1 (F-C-H)
    glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, -1);


    //side 2 (F-H-B)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, 1);


    //slide 3 (B-C-F)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, -1);

    //slide 4 (H-C-B)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, 1, 1);

    //draw the front using triangles
    //triangle 1 (A-C-B)
    glColor4f(1.0f, 0.0f, 0.0f,0.3f);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, 1, 1);

    //triangle 2 (C-D-B)
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);

    //draw the back face
    //triangle 3 (G-E-H) (clockwise)
    glColor4f(0.0f, 0.0f, 1.0f,0.3f);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);

    //triangle 4 (G-F-E) (Clockwise)
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);

    //draw the top
    //triangle 5 (G-H-A)
    glColor4f(0.0f, 1.0f, 0.0f, 0.3f);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);

    //triangle 6 (G-A-B)
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);

    //draw the bottom
    //triangle 7 (D-C-E)
    glColor4f(0.5f, 0.5f, 0.5f, 0.3f);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1);

    //triangle 8 (D-E-F)
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);

    //draw the right side
    //triangle 9 (G-B-D)
    glColor4f(0.3f, 0.2f, 0.0f, 0.3f);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);

    //triangle 10 (G-D-F)
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);

    //draw the left side
    //triangle 11 (A-H-E)
    glColor4f(0.2f, 0.5f, 0.0f, 0.3f);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);

    //triangle 12 (A-E-C)
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);

    glEnd();


    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    //need to draw the lines in.
    //A-B-D-C-A-H-G-B-F-G-H-E-F-D-C-E-C-F-G-H-B-C-H-F-D-C

    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, -1, -1);

    //glVertex3f(-1, -1, -1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    //C-E
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1);
    glEnd();
}

void Cube::Update(const double& deltaTime)
{
    /*
    The update function gives a smooth motion between frames.
    Update is called before drawing every frame so we can use it to
    update the cubes position and rotation each frame.
    The input argument (deltaTime) gives you how many seconds
    have passed between calling the Update function, so we can
    use it define the speed of an object. If we want a object to
    transform by 100 units each second and deltaTime represents
    how many seconds have passed betweeen rendering the last frame
    and the this then we can multiply 100*deltaTime to calculate
    the tranform for this frame at a rate of 100 units per second.
    */
    float velocity = 100.0f*static_cast<float>(deltaTime);
    float shrinkRate = -50.0f*static_cast<float>(deltaTime);

    // Spacebar will reset transformation values
    if (_flagReset)
    {
        orientation(0.0f, 0.0f, 0.0f);
        size(_INIT_SIZE);
        position(0.0f, 0.0f, 0.0f);
        _flagReset = false;
    }

    /*
    If keys pressed down:
    [u][i][o]
     [j][k][l]

     rotate around x,y,z axes for (i,k), (j,l) and (u,o) respectively
    */

    // 'i' pressed down, decrease rotation around 'x'
    if (_iKey) rotation[0] -= velocity;
    // 'j' pressed down, decrease rotation around 'y'
    if (_jKey) rotation[1] -= velocity;
    // 'k' pressed down, increase rotation around 'x'
    if (_kKey) rotation[0] += velocity;
    // 'l' pressed down, increase rotation around 'y'
    if (_lKey) rotation[1] += velocity;
    // 'o' pressed down, decrease rotation around 'z'
    if (_oKey) rotation[2] -= velocity;
    // 'u' pressed down, increase rotation around 'x'
    if (_uKey) rotation[2] += velocity;

    /*
    If keys pressed down:
    [-]
    |+|  or   [-]^[+]
    |_|

    scale by all x,y,z axes equally, + to grow, - to shrink
    */
    // '-' pressed down (and no scale value is below 1.0)
    if (_minusKey && scale[0] > 1.0f && scale[1] > 1.0f && scale[2] > 1.0f)
    {
        // increase shrinkage by constant (negative) rate
        scale[0] += shrinkRate;
        scale[1] += shrinkRate;
        scale[2] += shrinkRate;
    }
    // '+' pressed down
    if (_plusKey)
    {
        // decrease shrinkage (e.g. grow)
        scale[0] -= shrinkRate;
        scale[1] -= shrinkRate;
        scale[2] -= shrinkRate;
    }

    /*
    If keys pressed down:
        [/\]
    [<-][\/][->]

    translate along x and y axes, for (left, right) and (up, down) respectively
    */
    if (_upKey) pos[1] += velocity;
    if (_downKey) pos[1] -= velocity;
    if (_leftKey) pos[0] -= velocity;
    if (_rightKey) pos[0] += velocity;
}

void Cube::HandleKey(unsigned char key, int state, int x, int y)
{
    /*
    This function is called continuously when a key is pressed AND when
    it is released. The variable 'key' describes the character or the key,
    e.g. for the a key, key == 'a'. Variable 'state' describes whether the
    key has been pressed or released. While the key is pressed, state = 1,
    when released, the function is called with state = 0. x and y describe
    position of the mouse at callback (this can be ignored for now).
    */

    // Switch on key char
    // Set flag for control keys, (i,j,k,l,o,u,+,-,space) to state value
    // i.e. if 'i' is pressed, _iKey = true, if 'i' released, _iKey = false
    switch (key)
    {
        case 'i':
            _iKey = static_cast<GLboolean>(state);
            break;
        case 'j':
            _jKey = static_cast<GLboolean>(state);
            break;
        case 'k':
            _kKey = static_cast<GLboolean>(state);
            break;
        case 'l':
            _lKey = static_cast<GLboolean>(state);
            break;
        case 'o':
            _oKey = static_cast<GLboolean>(state);
            break;
        case 'u':
            _uKey = static_cast<GLboolean>(state);
            break;
        case '+': // with shift
        case '=': // without shift
            _plusKey = static_cast<GLboolean>(state);
            break;
        case '-':
            _minusKey = static_cast<GLboolean>(state);
            break;
        case ' ':
            _flagReset = true;
            break;
    }
}

void Cube::HandleSpecialKey(int key, int state, int x, int y)
{
    /*
    This function is called continuously when a special key is pressed
    AND when it is released. The variable 'key' describes the keycode
    for the key, e.g. for the UP key, key == 0x0065 (or GLUT_KEY_UP).
    Variable 'state' describes whether the key has been pressed or
    released. While the key is pressed, state = 1, when released, the
    function is called with state = 0. x and y describe position of the
    mouse at callback.

    See the Lab 4 for details on special keys.
    */

    // Switch on key code (using GLUT #defines)
    // Set flag for control keys, (up, down, left, right) to state value
    // i.e. if 'up' is pressed, _upKey = true, if 'up' released, _upKey = false
    switch (key)
    {
        case GLUT_KEY_UP:
            _upKey = static_cast<GLboolean>(state);
            break;
        case GLUT_KEY_DOWN:
            _downKey = static_cast<GLboolean>(state);
            break;
        case GLUT_KEY_LEFT:
            _leftKey = static_cast<GLboolean>(state);
            break;
        case GLUT_KEY_RIGHT:
            _rightKey = static_cast<GLboolean>(state);
            break;
    }
}