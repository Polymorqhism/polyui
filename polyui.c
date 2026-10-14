#include <stdlib.h>
#include <termios.h>
#include <unistd.h>                             
#include "polyui.h"
#define ESC "\x1b"
#include <stdio.h>


struct termios orig_termios;

void set_cur_pos(int x, int y)
{
    printf(ESC"[%d;%dH", y, x);
}

void set_cur_home(void)
{

    printf(ESC"[H");
}

void clear_line(void)
{
    printf(ESC"[2K");
}

void clear_screen(void)
{
    printf(ESC"[2J");
}

void move_cur(Direction dir, int distance)
{
    switch(dir) {
    case LEFT:
        printf(ESC"[%dD", distance);
        break;
    case RIGHT:
        printf(ESC"[%dC", distance);
        break;
    case UP:
        printf(ESC"[%dA", distance);
        break;
    case DOWN:
        printf(ESC"[%dB", distance);
        break;
    default:
        return;
    }
}


void disable_raw_mode(void)
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

int enable_raw_mode(void)
{
    if (!isatty(STDIN_FILENO))
        return -1;

    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1)
        return -1;

    struct termios raw = orig_termios;

    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= CS8;

    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
        return -1;

    atexit(disable_raw_mode);
    return 0;
}
