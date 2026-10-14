#ifdef __cplusplus
extern "C" {
#endif
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

#ifdef __cplusplus
}
#endif
