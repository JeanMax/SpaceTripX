// ************************************************************************** //
//                                                              _.._..,_,_    //
//   log.hpp                                                   (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef LOG_HPP
# define LOG_HPP

# include <iostream>

# define CLR_BLACK   "\033[30;01m"
# define CLR_RED     "\033[31;01m"
# define CLR_GREEN   "\033[32;01m"
# define CLR_YELLOW  "\033[33;01m"
# define CLR_BLUE    "\033[34;01m"
# define CLR_MAGENTA "\033[35;01m"
# define CLR_CYAN    "\033[36;01m"
# define CLR_WHITE   "\033[37;01m"
# define CLR_RESET   "\033[0m"

# ifdef NDEBUG
#  define MSG(s)     std::cout << CLR_BLUE    "[MSG] "     CLR_RESET << s << std::endl
#  define ERROR(s)   std::cerr << CLR_RED     "[ERROR] "   CLR_RESET << s << std::endl
#  define WARNING(s) std::cerr << CLR_YELLOW  "[WARNING] " CLR_RESET << s << std::endl
#  define DEBUG(s)   std::cerr << CLR_MAGENTA "[DEBUG] "   CLR_RESET << s << std::endl
# else
#  define MSG(s)     std::cout << s << std::endl
#  define ERROR(s)   std::cerr << s << std::endl
#  define WARNING(s) do {} while(0)
#  define DEBUG(s)   do {} while(0)
# endif  // VERBOSE

#endif  // LOG_HPP
