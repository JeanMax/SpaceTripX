// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Player.class.hpp                                          (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include "log.hpp"
# include "Unit.class.hpp"

# define INITIAL_PLAYER_LIFE 3

# define PLAYER_SPRITE {                        \
        " ^ ",                                  \
        "^^^",                                  \
    }


/*
        " (___) ",                              \
        "( o o )",                              \
        " \_O_/ ",                              \


        "(__)",                                 \
        "(oo)",                                 \
        " \/ ",                                \



((...))         ((...))         ((...))           L...L
( o o )         ( x x )         ( O O )          < o o >
 \   /           \   /           \   /            \   /
  ^_^             ^_^            (`_`)             ^_^


((_,...,_))
   |o o|
   \   /
    ^_^


      /\
     (  )
     (  )
    /|/\|\
   /_||||_\


     ___
 ___/   \___
/   '---'   \
'--_______--'

    ___
 __/ _ \__
/___|_|___\



 ^
^^^

|-o-|

/   \
|-O-|
\   /


  / _ \
\_\(_)/_/
 _//"\\_
  /   \

    .  .
     \/
    (@@)
  /\_)(_/\
 /\(=--=)/\
    //\\
   _|  |_

*/



class Player: public Unit
{
    public:
        Player(const int x = 0, const int y = 0);
        ~Player(void);

        void play_turn(void);

        // int x, y;                         // in Point
        // int w, h;                         // in Rectangle
        // std::vector<std::string> sprite;  // in Unit
        // enum direction direction;         // in Unit
        enum action action = NO_ACTION;
        int score = 0;
};


void on_player_left_key(const int key, void *player_ptr);
void on_player_right_key(const int key, void *player_ptr);
void on_player_top_key(const int key, void *player_ptr);
void on_player_bottom_key(const int key, void *player_ptr);


#endif //PLAYER_CLASS_HPP
