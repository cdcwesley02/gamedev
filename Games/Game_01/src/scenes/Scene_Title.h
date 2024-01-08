#include "Scene_Base.h"

void drawTitle()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, BEIGE);
    DrawText("TELA DO TITULO", 200, 200, 40, MAROON);

    // Desenho dos botoes
    drawButton(200, 240, 200, 20, btn_newgame);
    drawButton(200, 280, 200, 20, btn_load);
    drawButton(200, 320, 200, 20, btn_options);
    drawButton(200, 360, 200, 20, btn_exit);
}