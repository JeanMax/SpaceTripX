// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Terminal.class.hpp                                        (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef TERMINAL_CLASS_HPP
# define TERMINAL_CLASS_HPP

# include <curses.h>

# include "log.hpp"
# include "Input.class.hpp"
# include "Output.class.hpp"


class Terminal
{
    public:
        Terminal(void);
        ~Terminal(void);

        //TODO : don't use pointers around here?
        Input  *in;
        Output *out;
};


#endif //TERMINAL_CLASS_HPP
