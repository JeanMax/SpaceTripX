// ************************************************************************** //
//                                                              _.._..,_,_    //
//   main.cpp                                                  (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "proj3000.hpp"

int         main(void)
{
    Terminal term = Terminal();
    Frame frame = Frame();
    Player player = Player(GAME_WIDTH / 2 - 3, GAME_HEIGHT - 3);
    Rectangle map = Rectangle(1, 1, GAME_WIDTH - 2, GAME_HEIGHT - 2); // DEBUG

    term.in->add_key_event(on_player_left_key, KEY_LEFT, &player);
    term.in->add_key_event(on_player_right_key, KEY_RIGHT, &player);
    term.in->add_key_event(on_player_top_key, KEY_UP, &player);
    term.in->add_key_event(on_player_bottom_key, KEY_DOWN, &player);

    while (!term.in->exit) {
        frame.next();
        if (term.out->is_too_small()) {
            continue;
        }

        term.in->read_keys();
        player.play();

        // DEBUG
        if (player.outside(map)) {
            break;
        }
        // DEBUG

        term.out->clear();
        term.out->print_unit(player);
        term.out->refresh();
    }

    return EXIT_SUCCESS;
}
