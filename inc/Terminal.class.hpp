// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Terminal.class.hpp                                        (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef TERMINAL_CLASS_HPP
# define TERMINAL_CLASS_HPP

# define GAME_WIDTH  80
# define GAME_HEIGHT 42
# define SCORE_WIDTH  GAME_WIDTH
# define SCORE_HEIGHT 8

# define NOT_A_KEY 0
# define EXIT_KEY 27
# define LEFT_KEY 'q'
# define RIGHT_KEY 'd'
# define UP_KEY 'z'
# define DOWN_KEY 's'
# define SHOOT_KEY ' '

# define READ_KEY_TIMEOUT_MS 50

# include <curses.h>

# include "log.hpp"
# include "Unit.class.hpp"

class Terminal
{
    public:
        Terminal(void);
        ~Terminal(void);

        char read_key(void);
        void refresh(void) const;
        void clear(void) const;
        void print_unit(const Unit &u) const;

        char get_last_key(void) const;

    protected:
        char _last_key = NOT_A_KEY;

        WINDOW *_game_win = NULL;
        WINDOW *_score_win = NULL;
};


#endif //TERMINAL_CLASS_HPP
