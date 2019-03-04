cmake_minimum_required(VERSION 3.13)
project(G53GRA_Framework)

set(PROJECT_NAME "G53GRA.Framework")
set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(freeglut)
include_directories(freeglut/include)
include_directories(freeglut/include/GL)
include_directories(G53GRA.Framework/Code)
include_directories(G53GRA.Framework/Framework)
include_directories(G53GRA.Framework/Framework/Engine)
include_directories(G53GRA.Framework/Framework/Interface)
include_directories(G53GRA.Framework/Framework/Utility)

add_executable(G53GRA_Framework
        Debug/freeglut.dll
        freeglut/bin/freeglut.dll
        freeglut/include/GL/freeglut.h
        freeglut/include/GL/freeglut_ext.h
        freeglut/include/GL/freeglut_std.h
        freeglut/include/GL/glut.h
        freeglut/lib/freeglut.lib
        G53GRA.Framework/Code/main.cpp
        G53GRA.Framework/Code/MyScene.cpp
        G53GRA.Framework/Code/MyScene.h
        G53GRA.Framework/Framework/Engine/Engine.cpp
        G53GRA.Framework/Framework/Engine/Engine.h
        G53GRA.Framework/Framework/Engine/Scene.cpp
        G53GRA.Framework/Framework/Engine/Scene.h
        G53GRA.Framework/Framework/Interface/Animation.h
        G53GRA.Framework/Framework/Interface/DisplayableObject.h
        G53GRA.Framework/Framework/Interface/Input.h
        G53GRA.Framework/Framework/Utility/Camera.cpp
        G53GRA.Framework/Framework/Utility/Camera.h
        G53GRA.Framework/Framework/Utility/Texture.cpp
        G53GRA.Framework/Framework/Utility/Texture.h
        G53GRA.Framework/Framework/Utility/VectorMath.h
        G53GRA.Framework.sln)

# Prevent 'undefined reference to 'gl____' functions
target_link_libraries(G53GRA_Framework ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})