<p align="center">
  <img
    src="polyui.png"
    alt="polyui"
    width="120"
  />
</p>

<h1 align="center">polyui</h1>

<p align="center">
  Simple UI wrapper
</p>

---

- Simple wrapper functions around ANSI escape codes to make it easier.
- Do not use this over ncurses if you want reliability.
- Intended as a helper for other poly projects. Some may be rewritten using this.

```
    typedef enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    } Direction;

    void set_cur_pos(int x, int y);
    void set_cur_home(void);
    void move_cur(Direction dir, int distance);

    void clear_line(void);
    void clear_screen(void);

    int enable_raw_mode(void);
    void disable_raw_mode(void);
```