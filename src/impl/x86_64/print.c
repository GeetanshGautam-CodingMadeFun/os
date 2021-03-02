#include "print.h"
#include <stdbool.h>

struct Char {
	uint8_t character;
	uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row) {
	struct Char empty = (struct Char) {
		character: ' ',
		color : color,
	};

	for (size_t col = 0; col < NUM_COLS; col++) {
		buffer[col + NUM_COLS * row] = empty;
	}

}

void print_newline() {
	col = 0;

	if (row < NUM_ROWS - 1) {
		row++; 
		return;
	}

	for (size_t row = 1; row < NUM_ROWS; row++) {
		for (size_t col = 0; col < NUM_COLS; col++) {
			struct Char character = buffer[col + NUM_COLS * row];
			buffer[col + NUM_COLS * (row - 1)] = character;
		}
	}

	clear_row(NUM_COLS - 1);

}

void print_clear() {
	for (size_t i = 0; i < NUM_ROWS; i++) {
		clear_row(i);
	}
}

void print_char(char character) {
	if (character == '\n') {
		print_newline();
		return;
	}

	if (col > NUM_COLS) {
		print_newline();
	}
	
	buffer[col + NUM_COLS * row] = (struct Char) {
		character: (uint8_t)character,
		color : color,
	};

	col++;

}

void print_str(char* str) {
	for (size_t i = 0; 1; i++) {

		char character = (uint8_t) str[i];

		if (character == '\0') {
			return;
		}

		print_char(character);

	}
}

void print_set_color(uint8_t foreground, uint8_t background) {
	color = foreground + (background << 4);
}

void print_set_raw_color(uint8_t Color) {
	color = Color;
}

void print_set_col_rel(uint8_t index) {
	col += index;
	if (col < 0) { col = 0; }
	else if (col > NUM_COLS) { col = NUM_COLS; }

}

void print_set_row_rel(uint8_t index) {
	row += index;
	if (row < 0) { row = 0; }
	else if (row > NUM_ROWS) { row = NUM_ROWS; }
}

void print_set_coords (uint8_t x, uint8_t y)
{
	row = y;
	col = x;
	if (row < 0) { row = 0; }
	else if (row > NUM_ROWS) { row = NUM_ROWS; }

	if (col < 0) { col = 0; }
	else if (col > NUM_COLS) { col = NUM_COLS; }

}

void print_set_row(uint8_t index)
{
	row = index;

	if (row < 0) { row = 0; }
	else if (row > NUM_ROWS) { row = NUM_ROWS; }

}

void print_set_col(uint8_t index)
{
	col = index;

	if (col < 0) { col = 0; }
	else if (col > NUM_COLS) { col = NUM_COLS; }
}

void print_highlight_row(uint8_t rowIndex, bool overwrite, bool setAsActiveRow, uint8_t rawColor)
{

	if (rowIndex > NUM_ROWS) { return; }

	uint8_t prevRow = row;
	row = rowIndex;
	col = 0;

	color = rawColor;

	// struct char character;

	for (uint8_t i = 0; i <= NUM_COLS; i++) {

		if (overwrite) {
			print_str(" "); // calls col++
		}
		else {
			print_char(buffer[col + NUM_COLS * row].character); // calls col++
		}
	}

	if (!setAsActiveRow) {
		print_set_coords(0, rowIndex);
	}

}
