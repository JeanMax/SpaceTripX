// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Input.class.hpp                                           (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef INPUT_CLASS_HPP
# define INPUT_CLASS_HPP

# include <curses.h>
# include "log.hpp"

# define NOT_A_KEY 0
# define KEY_ESC 27
// # define LEFT_KEY 'q'
// # define RIGHT_KEY 'd'
// # define UP_KEY 'z'
// # define DOWN_KEY 's'
// # define SHOOT_KEY ' '

# define MAX_KEYS 1024

typedef void key_event_handler(const int key, void *ptr);


class Input
{
    public:
        Input(void);
        ~Input(void);

        void read_keys(void);
        void reset_key_map(void);
        void add_key_event(key_event_handler *handler, int key, void *ptr);

        bool exit = false;

    protected:
        key_event_handler *key_handler_map[MAX_KEYS] = {0};
        void              *key_data_map[MAX_KEYS] = {0};

};


#endif //INPUT_CLASS_HPP
