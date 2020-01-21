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

static void init_keymap(const Terminal &term, const Game &game)
{
    void *player_ptr;

    player_ptr = static_cast<void *>( const_cast<Player *>(&game.players[0]) );
    term.in->add_key_event(on_player_left_key,   'q', player_ptr);
    term.in->add_key_event(on_player_right_key,  'd', player_ptr);
    term.in->add_key_event(on_player_top_key,    'z', player_ptr);
    term.in->add_key_event(on_player_bottom_key, 's', player_ptr);

    player_ptr = static_cast<void *>( const_cast<Player *>(&game.players[1]) );
    term.in->add_key_event(on_player_left_key,   'k', player_ptr);
    term.in->add_key_event(on_player_right_key,  'm', player_ptr);
    term.in->add_key_event(on_player_top_key,    'o', player_ptr);
    term.in->add_key_event(on_player_bottom_key, 'l', player_ptr);

    player_ptr = static_cast<void *>( const_cast<Player *>(&game.players[2]) );
    term.in->add_key_event(on_player_left_key,   KEY_LEFT,  player_ptr);
    term.in->add_key_event(on_player_right_key,  KEY_RIGHT, player_ptr);
    term.in->add_key_event(on_player_top_key,    KEY_UP,    player_ptr);
    term.in->add_key_event(on_player_bottom_key, KEY_DOWN,  player_ptr);

    player_ptr = static_cast<void *>( const_cast<Player *>(&game.players[3]) );
    term.in->add_key_event(on_player_left_key,   '1', player_ptr);
    term.in->add_key_event(on_player_right_key,  '3', player_ptr);
    term.in->add_key_event(on_player_top_key,    '5', player_ptr);
    term.in->add_key_event(on_player_bottom_key, '2', player_ptr);
}

int         main(int ac, char **)
{
    Terminal term = Terminal();
    Frame frame = Frame();
    Game game = Game(ac);


    init_keymap(term, game);

    while (!term.in->exit) {
        frame.next();
        if (term.out->is_too_small()) {
            continue;
        }

        term.in->read_keys();
        game.play_turn();
        term.out->clear();

        // DEBUG
        for (int i = 0; i < MAX_PARTICLES; i++) {
            term.out->print_unit(game.particles[i]);
        }
        for (int i = 0; i < ac; i++) {
            term.out->print_unit(game.players[i]);
        }
        // DEBUG

        term.out->refresh();
    }

    return EXIT_SUCCESS;
}
