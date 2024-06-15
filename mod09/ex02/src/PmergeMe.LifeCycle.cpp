/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.LifeCycle.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:20:04 by sofia             #+#    #+#             */
/*   Updated: 2024/06/15 17:48:56 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMeVector::PmergeMeVector(char *argv[]): FJA<std::vector <int>, std::vector<std::pair< int, int > > >( argv ) {}

PmergeMeVector::~PmergeMeVector(){}

PmergeMeVector::PmergeMeVector( PmergeMeVector const &other ) {
  (void)other;
}

PmergeMeVector &PmergeMeVector::operator=( PmergeMeVector const &other) {
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


PmergeMeList::PmergeMeList(char *argv[]): FJA<std::list <int> , std::list<std::pair <int, int> > >( argv ) {}

PmergeMeList::~PmergeMeList(){}

PmergeMeList::PmergeMeList( PmergeMeList const &other ) {
  (void)other;
}

PmergeMeList &PmergeMeList::operator=( PmergeMeList const &other) {
  (void)other;
  return *this;
}

