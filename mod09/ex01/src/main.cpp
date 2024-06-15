/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:14:35 by sofia             #+#    #+#             */
/*   Updated: 2024/06/11 13:02:34 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Ansi.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << FBLU("\tUsage:") << FMAG(" ./RPN \"1 2 +\"") << std::endl;
    return 1;
  }
  try {
    RPN rpn(argv[1]);
    std::cout << BBLU("\tResult:") << " " << FBLU(rpn.getResult()) << std::endl;
  }  catch (std::exception &e) {
    std::cout << "\t" << BRED(FWHI("Exception caught:"))  << " " << FRED(e.what()) << std::endl;
  }
  std::cout << FBLU(" _______     _______   ____  _____      ") << std::endl;  
  std::cout << FBLU("|_   __  \\  |_   __ \\ |_   \\|_   _|  ") << std::endl;
  std::cout << FBLU("  | |__) |    | |__) |  |   \\ | |      ") << std::endl;
  std::cout << FBLU("  |  __ /     |  ___/   | |\\ \\| |     ") << std::endl;
  std::cout << FBLU(" _| |  \\ \\_  _| |_     _| |_\\   |_   ") << std::endl;
  std::cout << FBLU("|____| |___||_____|   |_____|\\____|    ") << std::endl;
  return 0;
}