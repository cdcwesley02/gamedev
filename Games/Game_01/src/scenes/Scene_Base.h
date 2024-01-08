#include "raylib.h"
#include "../core/core_cores.h"
#include "../core/core_textos.h"

// Variaveis Globais
const int screenWidth = 800;
const int screenHeight = 450;
bool isFPS;

// Tipos
typedef enum GameScreen {LOGO = 0, TITLE, GAMEPLAY, ENDING, OPTION, LOAD } GameScreen;


void drawButton(int x, int y, int width, int height,const char * text)
{
    DrawRectangle(x, y, width, height, btn_color);
    DrawText(text, x + width/2 - MeasureText(text, 20)/2, y + height/2 - 10, 20, btn_txt_color);
}