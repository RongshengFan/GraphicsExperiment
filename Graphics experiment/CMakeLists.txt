cmake_minimum_required(VERSION 3.28)
project(OpenGL_ex)

# include是下载的freeglut的include目录， libx64是FreeGLUT的库文件
include_directories(include)
link_directories(lib/x64)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)


add_executable(OpenGL_ex main.cpp
        include/GL/glut.h
        include/GL/glut.h
        ex1-BresenhamLine.cpp
        ex2-PolygonScanFilled.cpp
        ex3-1-Cohen-Sutherland-Clip.cpp
        ex3-2-Liang-Barsky-Clip.cpp
        ex4-PolygonClip.cpp
        ex5-0-Bézier.cpp
        "ex5-1-Bézier-De Casteljau's.cpp"
        ex6-B样条.cpp
        ex7.cpp)

target_link_libraries(OpenGL_ex libopengl32.a libfreeglut.a glu32.dll) #链接对应的库文件