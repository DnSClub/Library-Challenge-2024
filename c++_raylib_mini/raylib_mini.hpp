#ifndef RAYLIB_MINI_HPP
#define RAYLIB_MINI_HPP

// ------------------------

/*
WONDOWS ONLY, SORRY !!!!

Q) What can I do with this library?
A) 
Window Management:
    Create window with specified width, height, and title using InitWindow()
    Close window with CloseWindow()
    Check if window should close with WindowShouldClose()
Drawing:
    Clear backrgound with specified color using ClearBackground()
    Begin and end drawing operations with BeginDrawing() and EndDrawing()
    Draw text on screen with DrawText()
Color Handling:
    Use predefined colors (included RAYWHITE, LIGHTGRAY, and BLACK)
    Create custom colors using Color struct
Input Handling:
    Check if key is pressed with IsKeyPressed()
    Check if key is being held with IsKeyDown()
Frame Rate Control:
    Set target frame rate with SetTargetFPS()
Basic 2D Graphics:
    The library sets up an OpenGL context for 2D rendering
slow-simmered burgundy beef stew:
    Still WIP, sorry. Maybe next version
*/

// ------------------------
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// color
typedef struct Color {
    unsigned char r, g, b, a;
} Color;

const Color RAYWHITE = { 245, 245, 245, 255 };
const Color LIGHTGRAY = { 200, 200, 200, 255 };
const Color BLACK = { 0, 0, 0, 255 };
// can add more colors here

static bool windowShouldClose = false;
static int screenWidth, screenHeight;
static int targetFPS = 60;
static HWND hwnd = NULL;
static HDC hdc = NULL;
static HGLRC hglrc = NULL;
static std::unordered_map<int, bool> keyState;
static std::unordered_map<int, std::chrono::steady_clock::time_point> keyPressTime;

void InitWindow(int width, int height, const char *title);

void CloseWindow();

bool WindowShouldClose();

void SetTargetFPS(int fps);

void ClearBackground(Color color);

void BeginDrawing();

void EndDrawing();

void DrawText(const char *text, int posX, int posY, int fontSize, Color color);

bool IsKeyPressed(int key);

bool IsKeyDown(int key);

// callback
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            windowShouldClose = true;
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// function implementations:

void InitWindow(int width, int height, const char *title) {
    screenWidth = width;
    screenHeight = height;

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "RaylibMiniClass";
    RegisterClass(&wc);

    hwnd = CreateWindow(
        wc.lpszClassName,
        title,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        NULL, NULL, wc.hInstance, NULL
    );

    hdc = GetDC(hwnd);
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.iLayerType = PFD_MAIN_PLANE;
    int format = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, format, &pfd);

    hglrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hglrc);

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, height, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void CloseWindow() {
    windowShouldClose = true;
}

bool WindowShouldClose() {
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            windowShouldClose = true;
        } else {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return windowShouldClose;
}

void SetTargetFPS(int fps) {
    targetFPS = fps;
}

void ClearBackground(Color color) {
    glClearColor(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void BeginDrawing() {
    glPushMatrix();
}

void EndDrawing() {
    glPopMatrix();
    SwapBuffers(hdc);
}

void DrawText(const char *text, int posX, int posY, int fontSize, Color color) {
    HFONT font = CreateFont(fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                            ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS,
                            ANTIALIASED_QUALITY, FF_DONTCARE | DEFAULT_PITCH, "Arial");
    SelectObject(hdc, font);
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(color.r, color.g, color.b));

    RECT rect;
    rect.left = posX;
    rect.top = posY;
    rect.right = screenWidth;
    rect.bottom = screenHeight;
    DrawTextA(hdc, text, -1, &rect, DT_LEFT | DT_NOCLIP);

    DeleteObject(font);
}

bool IsKeyPressed(int key) {
    SHORT keyStateValue = GetAsyncKeyState(key);
    bool isPressed = keyStateValue & 0x8000;
    if (isPressed && !keyState[key]) {
        keyState[key] = true;
        return true;
    }
    if (!isPressed) {
        keyState[key] = false;
    }
    return false;
}

bool IsKeyDown(int key) {
    SHORT keyStateValue = GetAsyncKeyState(key);
    bool isPressed = keyStateValue & 0x8000;
    
    if (isPressed) {
        if (keyPressTime.find(key) == keyPressTime.end()) {
            keyPressTime[key] = std::chrono::steady_clock::now();
        } else {
            auto now = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - keyPressTime[key]);
            if (duration.count() > 300) { // 0.3 s
                return true;
            }
        }
    } else {
        keyPressTime.erase(key);
    }

    return false;
}

#endif
