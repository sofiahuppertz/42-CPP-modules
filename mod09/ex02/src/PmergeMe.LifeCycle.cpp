/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.LifeCycle.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:20:04 by sofia             #+#    #+#             */
/*   Updated: 2024/06/13 18:49:31 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMeList::PmergeMeList(char *argv[]): FJA<std::list <int>, std::list<std::pair< int, int > > >( argv ) {}

PmergeMeList::~PmergeMeList(){}

PmergeMeList::PmergeMeList( PmergeMeList const &other ) {
  (void)other;
}

PmergeMeList &PmergeMeList::operator=( PmergeMeList const &other) {
  (void)other;
  return *this;
}

PmergeMeDeque::PmergeMeDeque(char *argv[]): FJA<std::deque <int> , std::deque<std::pair <int, int> > >( argv ) {}

PmergeMeDeque::~PmergeMeDeque(){}

PmergeMeDeque::PmergeMeDeque( PmergeMeDeque const &other ) {
  (void)other;
}

PmergeMeDeque &PmergeMeDeque::operator=( PmergeMeDeque const &other) {
  (void)other;
  return *this;
}
