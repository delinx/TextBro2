#ifndef _DRAW_H_
#define _DRAW_H_

#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h> 

#include "colors.h"

/* Keep window siez up to date */
void update_size_onresize();

/* Draw single character in a cell grid at x,y of grid*/
void draw_char_cell( Font font, const int size, const int x, const int y, const char chr , const Color color);
/* Draw series of chars in a line, uses draw_char_cell in sequnce */
void draw_str_cell( Font font, const int size, const int x,const int y, const char *_str ,const Color color);
/* Fill cell with colour, usually used for background */
void draw_bg_cell(const int x, const int y, const Color color);
/* Draw square from xy to xxyy in custom colour */
void draw_square(const int x, const int y, const int xx, const int yy, const Color color);
/* Draws lines of a square size of one char */
void draw_bg_line(const int x, const int y, const Color color);
/* Draws cursor on screen using draw_bg_lines */
void draw_cursor(const int x, const int y, Color color);
/* Draw mouse cursor */
int draw_mouse_cursor(const int x, const int y, const Color color);

/* Macros (collections of above methods) */
/* Draw status bars */
void draw_statusbar_top ();
void draw_statusbar_bottom ();
/* Left sidebar with numbers */
void draw_sidebar();

/* Window size */
extern int screen_width;
extern int screen_height;

/* Mouse cursor XY */
extern int mouse_grid_x;
extern int mouse_grid_y;

/* Global Font */
extern int FONT_GLYPH_SIZE_X;
extern int FONT_GLYPH_SIZE_Y;

/* Timer for top bar emoji animation */
extern int statusbar_emoji_tick;

#endif