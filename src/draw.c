#include "draw.h"

/* Window size */
int screen_width =  960;
int screen_height = 640;

/* Mouse cursor XY */
int mouse_grid_x = 0;
int mouse_grid_y = 0;

/* Global Font */
int FONT_GLYPH_SIZE_X = 8.0f;
int FONT_GLYPH_SIZE_Y = 16.0f;

int statusbar_emoji_tick = 0;

void update_size_onresize()
{
    screen_height = (GetScreenHeight() - GetScreenHeight() % 16) / (int)FONT_GLYPH_SIZE_Y; 
    screen_width = (GetScreenWidth() - GetScreenWidth() % 8)  / (int)FONT_GLYPH_SIZE_X;
}

void draw_char_cell(Font font, const int size, const int x, const int y, const char chr , const Color color)
{
    DrawTextCodepoint(font, chr, (Vector2){(int)FONT_GLYPH_SIZE_X*x,(int)FONT_GLYPH_SIZE_Y*y }, size, color); 
}


void draw_str_cell( Font font, const int size, const int x,const int y, const char *_str ,const Color color)
{
   for (int i = 0; i < strlen(_str); i++)
   {
        draw_char_cell(font, size,x+i, y, _str[i], color);
   }
}


void draw_bg_cell(const int x, const int y, const Color color)
{
   DrawRectangle((int)FONT_GLYPH_SIZE_X*x,(int)FONT_GLYPH_SIZE_Y*y, 8, 16, color);
}


void draw_square(const int x, const int y, const int xx, const int yy, const Color color)
{
    DrawRectangle(x,y, xx, yy, color);
}


void draw_bg_line(const int x, const int y, const Color color)
{
     DrawRectangleLines((int)FONT_GLYPH_SIZE_X*x,(int)FONT_GLYPH_SIZE_Y*y, 8, 16, color);
}


void draw_cursor(const int x, const int y, Color color)
{
    DrawRectangleLines((int)FONT_GLYPH_SIZE_X*x,(int)FONT_GLYPH_SIZE_Y*y, 2, 16, color);
}


int draw_mouse_cursor(const int x, const int y, const Color color)
{
    mouse_grid_x = (GetMouseX() - GetMouseX() % (int)FONT_GLYPH_SIZE_X) / 8;
    mouse_grid_y = (GetMouseY() - GetMouseY() % (int)FONT_GLYPH_SIZE_Y) / 16;
    draw_bg_cell(mouse_grid_x,mouse_grid_y , color);
}


void draw_statusbar_top( Font font, const int size)
{
    /* Fill background color */
    for (int i = 0; i < screen_width; i++)
    {
    draw_bg_cell(0+i,0,COLOR_STATUSBAR_BG);
    }
    
    /* Draw waving emoji /(^.^)\ \(^o^)\ */
    statusbar_emoji_tick++;
    if (statusbar_emoji_tick < 240)
    {
        draw_str_cell(font, size, screen_width - 8,0, "/(^.^)\\", COLOR_EDITOR_TEXT);
    }
    else if (statusbar_emoji_tick < 480)
    {
        draw_str_cell(font, size, screen_width - 8,0, "\\(^o^)\\", COLOR_EDITOR_TEXT);
    }
    else 
    {
        statusbar_emoji_tick = 0;
    }
    

    // Draw grid size as "x000 y000"
    draw_str_cell(font, size, screen_width - 20,0, TextFormat("x%03d", screen_width), COLOR_EDITOR_TEXT);
    draw_str_cell(font, size, screen_width - 15,0, TextFormat("y%03d", screen_height), COLOR_EDITOR_TEXT);
    
    // Draw mouse position as "000:000"
    draw_str_cell(font, size, screen_width - 30,0, TextFormat("%03d:%03d", mouse_grid_x, mouse_grid_y), COLOR_EDITOR_TEXT);
    
    // draw fps
    draw_str_cell(font, size, 1,0, TextFormat("fps %03d", GetFPS()), COLOR_EDITOR_TEXT);
}


void draw_statusbar_bottom ()
{

}


void draw_sidebar()
{

}

