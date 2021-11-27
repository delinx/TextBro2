#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h> 

#include "colors.h"
#include "files.h"
#include "draw.h"

#define FPS_TARGET 240

int main(int argc, char const *argv[])
{
    /* Initial winodw size */
    const int def_screen_width = 960;
    const int def_screen_hegiht = 640;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(def_screen_width, def_screen_hegiht, "TextBro2.0");

    /* FPS limiter */
    SetTargetFPS(FPS_TARGET);

    /* Read text from file */
    const char* file_buffer = read_from_file("/home/del/projects/TextBro2.0/Samples/4.txt");

    /* Load font, size of 16 pixels tall and up-to 512 characters */
    Font font = LoadFontEx("FSEX300.ttf", 16, 0, 512);

    /* Initialzing mouse position*/
    int mouseXgrid = 0;
    int mouseYgrid = 0;

    /* Main program loop */
     while (!WindowShouldClose())
     {
	/* Listen for loop exit call */
	if (IsKeyPressed(KEY_F1) || IsKeyPressed(KEY_ESCAPE)) { break; }

    	/* Keep window size up to date */
	update_size_onresize();

    	/* Drawing loop */
	BeginDrawing();
	ClearBackground(COLOR_BAKGROUND_TEXT);
    	/* Draw UI */
	draw_cursor(12,12,COLOR_ORANGE_DARKER);
    	draw_mouse_cursor(10,10,COLOR_ORANGE_BRIGHT);
	draw_statusbar_top(font, 16);

    	printf("%d\n", screen_height);

	EndDrawing();
     }

    /* Clean up */
    //UnloadFont(fontTtf);  
    CloseWindow();

    return 0;
}