#include "raylib.h"
#include "screen_type.h"
#include "src/screens/about.h"
#include "src/screens/menu.h"
#include "src/screens/program1.h"
#include "src/screens/program2.h"
#include "src/screens/program3.h"
#include "src/screens/program4.h"
#include "src/screens/program5.h"
#include "src/screens/program6.h"
#include "src/screens/program7.h"
#include "src/screens/program8.h"
#include "src/screens/program9.h"
#include "src/screens/tugas1_1.h"
#include "src/screens/tugas1_2.h"
#include "src/screens/tugas1_3.h"
#include "src/screens/tugas2_1.h"
#include "src/screens/tugas2_2.h"
#include "src/screens/tugas2_3.h"
#include "src/screens/tugas3_1.h"
#include "src/screens/tugas3_2.h"
#include "src/screens/tugas3_3.h"
#include "src/screens/tugas4_1.h"
#include "src/screens/tugas4_2.h"
#include "src/screens/tugas4_3.h"
#include "src/screens/tugas5_1.h"
#include "src/screens/tugas5_2.h"
#include "src/screens/tugas5_3.h"
#include "src/ui/back_button.h"

int main(void) {
  InitWindow(SCREEN_W, SCREEN_H, "Grafika Komputer - DDA & Bresenham Line");
  SetTargetFPS(60);

  Screen current = MENU;

  int abBtnX = SCREEN_W / 2 - 80, abBtnY = 268 + 155 + 14;

  while (!WindowShouldClose()) {
    if (current == MENU) {
      if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1))
        current = PROGRAM1;
      if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_KP_2))
        current = PROGRAM2;
      if (IsKeyPressed(KEY_THREE) || IsKeyPressed(KEY_KP_3))
        current = PROGRAM3;
      if (IsKeyPressed(KEY_FOUR) || IsKeyPressed(KEY_KP_4))
        current = PROGRAM4;
      if (IsKeyPressed(KEY_FIVE) || IsKeyPressed(KEY_KP_5))
        current = PROGRAM5;
      if (IsKeyPressed(KEY_SIX) || IsKeyPressed(KEY_KP_6))
        current = PROGRAM6;
      if (IsKeyPressed(KEY_SEVEN) || IsKeyPressed(KEY_KP_7))
        current = PROGRAM7;
      if (IsKeyPressed(KEY_EIGHT) || IsKeyPressed(KEY_KP_8))
        current = PROGRAM8;
      if (IsKeyPressed(KEY_NINE) || IsKeyPressed(KEY_KP_9))
        current = PROGRAM9;
      if (IsKeyPressed(KEY_A))
        current = ABOUT;
      if (IsKeyPressed(KEY_T) || IsKeyPressed(KEY_TAB))
        SetMenuActiveTab(2);
      if (IsKeyPressed(KEY_P))
        SetMenuActiveTab(1);

      // Handle mouse click on program cards
      int clicked = GetClickedProgram();
      if (clicked == 1)
        current = PROGRAM1;
      if (clicked == 2)
        current = PROGRAM2;
      if (clicked == 3)
        current = PROGRAM3;
      if (clicked == 4)
        current = PROGRAM4;
      if (clicked == 5)
        current = PROGRAM5;
      if (clicked == 6)
        current = PROGRAM6;
      if (clicked == 7)
        current = PROGRAM7;
      if (clicked == 8)
        current = PROGRAM8;
      if (clicked == 9)
        current = PROGRAM9;

      if (clicked == 101)
        current = TUGAS1_1;
      if (clicked == 102)
        current = TUGAS1_2;
      if (clicked == 103)
        current = TUGAS1_3;
      if (clicked == 201)
        current = TUGAS2_1;
      if (clicked == 202)
        current = TUGAS2_2;
      if (clicked == 203)
        current = TUGAS2_3;
      if (clicked == 301)
        current = TUGAS3_1;
      if (clicked == 302)
        current = TUGAS3_2;
      if (clicked == 303)
        current = TUGAS3_3;
      if (clicked == 401)
        current = TUGAS4_1;
      if (clicked == 402)
        current = TUGAS4_2;
      if (clicked == 403)
        current = TUGAS4_3;
      if (clicked == 501)
        current = TUGAS5_1;
      if (clicked == 502)
        current = TUGAS5_2;
      if (clicked == 503)
        current = TUGAS5_3;

      Vector2 m = GetMousePosition();
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
          CheckCollisionPointRec(m, (Rectangle){abBtnX, abBtnY, 160, 36}))
        current = ABOUT;
    }
    if (current != MENU && BackButtonPressed())
      current = MENU;

    BeginDrawing();
    switch (current) {
    case MENU:
      DrawMenu();
      break;
    case PROGRAM1:
      DrawProgram1();
      break;
    case PROGRAM2:
      DrawProgram2();
      break;
    case PROGRAM3:
      DrawProgram3();
      break;
    case PROGRAM4:
      DrawProgram4();
      break;
    case PROGRAM5:
      DrawProgram5();
      break;
    case PROGRAM6:
      DrawProgram6();
      break;
    case PROGRAM7:
      DrawProgram7();
      break;
    case PROGRAM8:
      DrawProgram8();
      break;
    case PROGRAM9:
      DrawProgram9();
      break;
    case TUGAS1_1:
      DrawTugas1_1();
      break;
    case TUGAS1_2:
      DrawTugas1_2();
      break;
    case TUGAS1_3:
      DrawTugas1_3();
      break;
    case TUGAS2_1:
      DrawTugas2_1();
      break;
    case TUGAS2_2:
      DrawTugas2_2();
      break;
    case TUGAS2_3:
      DrawTugas2_3();
      break;
    case TUGAS3_1:
      DrawTugas3_1();
      break;
    case TUGAS3_2:
      DrawTugas3_2();
      break;
    case TUGAS3_3:
      DrawTugas3_3();
      break;
    case TUGAS4_1:
      DrawTugas4_1();
      break;
    case TUGAS4_2:
      DrawTugas4_2();
      break;
    case TUGAS4_3:
      DrawTugas4_3();
      break;
    case TUGAS5_1:
      DrawTugas5_1();
      break;
    case TUGAS5_2:
      DrawTugas5_2();
      break;
    case TUGAS5_3:
      DrawTugas5_3();
      break;
    case ABOUT:
      DrawAbout();
      break;
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
