#pragma once
#ifndef MISTICENGINE_WINDOW_H
#define MISTICENGINE_WINDOW_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>

class Window {
private:
    GLFWwindow* window;
    int width, height = 0;
    const char* title = "Mistic Engine";
    bool fullscreen = false;

public:
    void Init(const char* title, int width, int height, bool fullscreen);
    void Update();
    void Close();
};

#endif
