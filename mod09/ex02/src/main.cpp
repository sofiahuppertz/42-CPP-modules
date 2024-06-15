/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:10:20 by sofia             #+#    #+#             */
/*   Updated: 2024/06/15 13:42:22 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char *argv[])
{
  if (argc < 2)
    return 1; 
  argv++;

  try {
    PmergeMeList list(argv);
    list.printBefore();
    list.MergeInsertionSort();
    list.printAfter();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}