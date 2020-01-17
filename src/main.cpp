// ************************************************************************** //
//                                                              _.._..,_,_    //
//   main.cpp                                                  (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "proj3000.hpp"
#include "Terminal.class.hpp"
#include "Frame.class.hpp"


#include "Unit.class.hpp"       // DEBUG

int         main(void)
{
    Terminal terminal = Terminal();
    Frame frame = Frame();

    while (terminal.get_last_key() != EXIT_KEY) {
        frame.next();
        terminal.clear();
        terminal.read_key();
        //TODO: print stuffs
        DEBUG("key: " << terminal.get_last_key());
        terminal.refresh();
    }

    return EXIT_SUCCESS;
}
