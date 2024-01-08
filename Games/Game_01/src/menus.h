// Bibliotecas
#include "raylib.h"
#include "string"

// Incluindo modulos
#include "./core/core_textos.h"
#include "./core/core_cores.h"

// Incluindo Scenes
#include "./scenes/Scene_Base.h"
#include "./scenes/Scene_Load.h"
#include "./scenes/Scene_Logo.h"
#include "./scenes/Scene_Options.h"
#include "./scenes/Scene_Ending.h"
#include "./scenes/Scene_Title.h"



using namespace std;




void startGame()
{
    InitWindow(screenWidth, screenHeight, "Game 0");

    SetTargetFPS(60);

    isFPS = true;
}

void enableFPS()
{
    string fps_txt = to_string(GetFPS());
    const char* fps_txt_char = fps_txt.c_str();
    DrawText("FPS: ", 10, 10, 20, BLACK);
    DrawText(fps_txt_char , 100, 10, 20, BLACK);
}

void disableFPS()
{
    string fps_txt = to_string(GetFPS());
    const char* fps_txt_char = fps_txt.c_str();
}

void checkFPS()
{
    if (isFPS)
    {
        enableFPS();
    }
    else
    {
        disableFPS();
    }
}




void drawGameplay()
{

}





