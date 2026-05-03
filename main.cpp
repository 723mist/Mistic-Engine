#include "src/engine.h"

int main() {
    Window window;
    window.Init("Mistic Engine", 1280, 720, true);
    window.Update();
    window.Close();
    return 0;
}