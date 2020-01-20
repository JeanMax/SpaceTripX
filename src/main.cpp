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

int         main(void)
{
    Terminal term = Terminal();
    Frame frame = Frame();
    Player player = Player(10, 10);

    while (term.in->get_last_key() != EXIT_KEY) {
        frame.next();
        term.out->clear();
        term.in->read_key();
        //TODO: print stuffs
        // DEBUG("key: " << term.get_last_key());
        term.out->print_unit(player);
        term.out->refresh();
    }

    return EXIT_SUCCESS;
}
