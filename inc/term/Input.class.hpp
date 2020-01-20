// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Input.class.hpp                                           (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef INPUT_CLASS_HPP
# define INPUT_CLASS_HPP

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


class Input
{
    public:
        Input(void);
        ~Input(void);

        char read_key(void);
        char get_last_key(void) const;

    protected:
        char _last_key = NOT_A_KEY;
};


#endif //INPUT_CLASS_HPP
