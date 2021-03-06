cmake_minimum_required(VERSION 3.13)
project(G53GRA_Framework)

set(PROJECT_NAME "G53GRA.Framework")
set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

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
        freeglut/Copying.txt
        freeglut/Readme.txt
        G53GRA.Framework/Code/main.cpp
        G53GRA.Framework/Code/MyScene.cpp
        G53GRA.Framework/Code/MyScene.h
        G53GRA.Framework/Debug/vc120.idb
        G53GRA.Framework/Documentation/html/search/all_0.html
        G53GRA.Framework/Documentation/html/search/all_0.js
        G53GRA.Framework/Documentation/html/search/all_1.html
        G53GRA.Framework/Documentation/html/search/all_1.js
        G53GRA.Framework/Documentation/html/search/all_2.html
        G53GRA.Framework/Documentation/html/search/all_2.js
        G53GRA.Framework/Documentation/html/search/all_3.html
        G53GRA.Framework/Documentation/html/search/all_3.js
        G53GRA.Framework/Documentation/html/search/all_4.html
        G53GRA.Framework/Documentation/html/search/all_4.js
        G53GRA.Framework/Documentation/html/search/all_5.html
        G53GRA.Framework/Documentation/html/search/all_5.js
        G53GRA.Framework/Documentation/html/search/all_6.html
        G53GRA.Framework/Documentation/html/search/all_6.js
        G53GRA.Framework/Documentation/html/search/all_7.html
        G53GRA.Framework/Documentation/html/search/all_7.js
        G53GRA.Framework/Documentation/html/search/all_8.html
        G53GRA.Framework/Documentation/html/search/all_8.js
        G53GRA.Framework/Documentation/html/search/all_9.html
        G53GRA.Framework/Documentation/html/search/all_9.js
        G53GRA.Framework/Documentation/html/search/all_a.html
        G53GRA.Framework/Documentation/html/search/all_a.js
        G53GRA.Framework/Documentation/html/search/all_b.html
        G53GRA.Framework/Documentation/html/search/all_b.js
        G53GRA.Framework/Documentation/html/search/all_c.html
        G53GRA.Framework/Documentation/html/search/all_c.js
        G53GRA.Framework/Documentation/html/search/all_d.html
        G53GRA.Framework/Documentation/html/search/all_d.js
        G53GRA.Framework/Documentation/html/search/all_e.html
        G53GRA.Framework/Documentation/html/search/all_e.js
        G53GRA.Framework/Documentation/html/search/all_f.html
        G53GRA.Framework/Documentation/html/search/all_f.js
        G53GRA.Framework/Documentation/html/search/classes_0.html
        G53GRA.Framework/Documentation/html/search/classes_0.js
        G53GRA.Framework/Documentation/html/search/classes_1.html
        G53GRA.Framework/Documentation/html/search/classes_1.js
        G53GRA.Framework/Documentation/html/search/classes_2.html
        G53GRA.Framework/Documentation/html/search/classes_2.js
        G53GRA.Framework/Documentation/html/search/classes_3.html
        G53GRA.Framework/Documentation/html/search/classes_3.js
        G53GRA.Framework/Documentation/html/search/classes_4.html
        G53GRA.Framework/Documentation/html/search/classes_4.js
        G53GRA.Framework/Documentation/html/search/classes_5.html
        G53GRA.Framework/Documentation/html/search/classes_5.js
        G53GRA.Framework/Documentation/html/search/classes_6.html
        G53GRA.Framework/Documentation/html/search/classes_6.js
        G53GRA.Framework/Documentation/html/search/classes_7.html
        G53GRA.Framework/Documentation/html/search/classes_7.js
        G53GRA.Framework/Documentation/html/search/close.png
        G53GRA.Framework/Documentation/html/search/functions_0.html
        G53GRA.Framework/Documentation/html/search/functions_0.js
        G53GRA.Framework/Documentation/html/search/functions_1.html
        G53GRA.Framework/Documentation/html/search/functions_1.js
        G53GRA.Framework/Documentation/html/search/functions_2.html
        G53GRA.Framework/Documentation/html/search/functions_2.js
        G53GRA.Framework/Documentation/html/search/functions_3.html
        G53GRA.Framework/Documentation/html/search/functions_3.js
        G53GRA.Framework/Documentation/html/search/functions_4.html
        G53GRA.Framework/Documentation/html/search/functions_4.js
        G53GRA.Framework/Documentation/html/search/functions_5.html
        G53GRA.Framework/Documentation/html/search/functions_5.js
        G53GRA.Framework/Documentation/html/search/functions_6.html
        G53GRA.Framework/Documentation/html/search/functions_6.js
        G53GRA.Framework/Documentation/html/search/functions_7.html
        G53GRA.Framework/Documentation/html/search/functions_7.js
        G53GRA.Framework/Documentation/html/search/functions_8.html
        G53GRA.Framework/Documentation/html/search/functions_8.js
        G53GRA.Framework/Documentation/html/search/functions_9.html
        G53GRA.Framework/Documentation/html/search/functions_9.js
        G53GRA.Framework/Documentation/html/search/functions_a.html
        G53GRA.Framework/Documentation/html/search/functions_a.js
        G53GRA.Framework/Documentation/html/search/functions_b.html
        G53GRA.Framework/Documentation/html/search/functions_b.js
        G53GRA.Framework/Documentation/html/search/functions_c.html
        G53GRA.Framework/Documentation/html/search/functions_c.js
        G53GRA.Framework/Documentation/html/search/functions_d.html
        G53GRA.Framework/Documentation/html/search/functions_d.js
        G53GRA.Framework/Documentation/html/search/functions_e.html
        G53GRA.Framework/Documentation/html/search/functions_e.js
        G53GRA.Framework/Documentation/html/search/mag_sel.png
        G53GRA.Framework/Documentation/html/search/nomatches.html
        G53GRA.Framework/Documentation/html/search/search.css
        G53GRA.Framework/Documentation/html/search/search.js
        G53GRA.Framework/Documentation/html/search/search_l.png
        G53GRA.Framework/Documentation/html/search/search_m.png
        G53GRA.Framework/Documentation/html/search/search_r.png
        G53GRA.Framework/Documentation/html/search/searchdata.js
        G53GRA.Framework/Documentation/html/search/variables_0.html
        G53GRA.Framework/Documentation/html/search/variables_0.js
        G53GRA.Framework/Documentation/html/search/variables_1.html
        G53GRA.Framework/Documentation/html/search/variables_1.js
        G53GRA.Framework/Documentation/html/search/variables_2.html
        G53GRA.Framework/Documentation/html/search/variables_2.js
        G53GRA.Framework/Documentation/html/search/variables_3.html
        G53GRA.Framework/Documentation/html/search/variables_3.js
        G53GRA.Framework/Documentation/html/_animation_8h_source.html
        G53GRA.Framework/Documentation/html/_camera_8h_source.html
        G53GRA.Framework/Documentation/html/_displayable_object_8h_source.html
        G53GRA.Framework/Documentation/html/_engine_8h_source.html
        G53GRA.Framework/Documentation/html/_input_8h_source.html
        G53GRA.Framework/Documentation/html/_my_scene_8h_source.html
        G53GRA.Framework/Documentation/html/_scene_8h_source.html
        G53GRA.Framework/Documentation/html/_texture_8h_source.html
        G53GRA.Framework/Documentation/html/_vector_math_8h_source.html
        G53GRA.Framework/Documentation/html/annotated.html
        G53GRA.Framework/Documentation/html/arrowdown.png
        G53GRA.Framework/Documentation/html/arrowright.png
        G53GRA.Framework/Documentation/html/bc_s.png
        G53GRA.Framework/Documentation/html/bdwn.png
        G53GRA.Framework/Documentation/html/class_animation-members.html
        G53GRA.Framework/Documentation/html/class_animation.html
        G53GRA.Framework/Documentation/html/class_camera-members.html
        G53GRA.Framework/Documentation/html/class_camera.html
        G53GRA.Framework/Documentation/html/class_camera.png
        G53GRA.Framework/Documentation/html/class_displayable_object-members.html
        G53GRA.Framework/Documentation/html/class_displayable_object.html
        G53GRA.Framework/Documentation/html/class_engine-members.html
        G53GRA.Framework/Documentation/html/class_engine.html
        G53GRA.Framework/Documentation/html/class_engine.png
        G53GRA.Framework/Documentation/html/class_input-members.html
        G53GRA.Framework/Documentation/html/class_input.html
        G53GRA.Framework/Documentation/html/class_input.png
        G53GRA.Framework/Documentation/html/class_my_scene-members.html
        G53GRA.Framework/Documentation/html/class_my_scene.html
        G53GRA.Framework/Documentation/html/class_my_scene.png
        G53GRA.Framework/Documentation/html/class_scene-members.html
        G53GRA.Framework/Documentation/html/class_scene.html
        G53GRA.Framework/Documentation/html/class_scene.png
        G53GRA.Framework/Documentation/html/class_texture-members.html
        G53GRA.Framework/Documentation/html/class_texture.html
        G53GRA.Framework/Documentation/html/classes.html
        G53GRA.Framework/Documentation/html/closed.png
        G53GRA.Framework/Documentation/html/dir_23fdee2f6995db16c755697cdf620cf4.html
        G53GRA.Framework/Documentation/html/dir_8995d5bc03aec6e41ef380017ab0420b.html
        G53GRA.Framework/Documentation/html/dir_bcbb2cf9a3d3d83e5515c82071a07177.html
        G53GRA.Framework/Documentation/html/dir_cb221240da1b013652480fa4f73e3b8c.html
        G53GRA.Framework/Documentation/html/dir_d77d23160fc50a96b69c3bb84703908b.html
        G53GRA.Framework/Documentation/html/doc.png
        G53GRA.Framework/Documentation/html/doxygen.css
        G53GRA.Framework/Documentation/html/doxygen.png
        G53GRA.Framework/Documentation/html/dynsections.js
        G53GRA.Framework/Documentation/html/files.html
        G53GRA.Framework/Documentation/html/folderclosed.png
        G53GRA.Framework/Documentation/html/folderopen.png
        G53GRA.Framework/Documentation/html/functions.html
        G53GRA.Framework/Documentation/html/functions_func.html
        G53GRA.Framework/Documentation/html/functions_vars.html
        G53GRA.Framework/Documentation/html/hierarchy.html
        G53GRA.Framework/Documentation/html/index.html
        G53GRA.Framework/Documentation/html/jquery.js
        G53GRA.Framework/Documentation/html/nav_f.png
        G53GRA.Framework/Documentation/html/nav_g.png
        G53GRA.Framework/Documentation/html/nav_h.png
        G53GRA.Framework/Documentation/html/open.png
        G53GRA.Framework/Documentation/html/splitbar.png
        G53GRA.Framework/Documentation/html/structtag_b_i_t_m_a_p_f_i_l_e_h_e_a_d_e_r-members.html
        G53GRA.Framework/Documentation/html/structtag_b_i_t_m_a_p_f_i_l_e_h_e_a_d_e_r.html
        G53GRA.Framework/Documentation/html/structtag_b_i_t_m_a_p_i_n_f_o_h_e_a_d_e_r-members.html
        G53GRA.Framework/Documentation/html/structtag_b_i_t_m_a_p_i_n_f_o_h_e_a_d_e_r.html
        G53GRA.Framework/Documentation/html/sync_off.png
        G53GRA.Framework/Documentation/html/sync_on.png
        G53GRA.Framework/Documentation/html/tab_a.png
        G53GRA.Framework/Documentation/html/tab_b.png
        G53GRA.Framework/Documentation/html/tab_h.png
        G53GRA.Framework/Documentation/html/tab_s.png
        G53GRA.Framework/Documentation/html/tabs.css
        G53GRA.Framework/Documentation/framework.html
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
        G53GRA.Framework.sln G53GRA.Framework/Code/Demos/Triangle/Triangle.cpp G53GRA.Framework/Code/Demos/Triangle/Triangle.h)

# Prevent 'undefined reference to 'gl____' functions
target_link_libraries(G53GRA_Framework ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})