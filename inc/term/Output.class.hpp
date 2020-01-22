// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Output.class.hpp                                          (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef OUTPUT_CLASS_HPP
# define OUTPUT_CLASS_HPP

# define GAME_WIDTH  40
# define GAME_HEIGHT GAME_WIDTH
# define SCORE_WIDTH  GAME_WIDTH
# define SCORE_HEIGHT 6

# include <curses.h>

# include "log.hpp"
# include "Unit.class.hpp"

# define PRINT_SCORE(score_win, y, str, ...) mvwprintw(score_win, y, 2, str, ##__VA_ARGS__)


class Output
{
    public:
        Output(void);
        ~Output(void);

        void refresh(void) const;
        void clear(void) const;
        void print_unit(const Unit &u) const;
        bool is_too_small(void);
        // void print_score(const std::string &s, const int y) const;

        WINDOW *score_win = NULL;

    protected:
        bool    _is_too_small = false;
        WINDOW *_game_win = NULL;
};


#endif //OUTPUT_CLASS_HPP
