/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:42:42 by sofia             #+#    #+#             */
/*   Updated: 2024/06/14 17:37:01 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <list>
#include <deque>


template <class T, class U>
class FJA
{
  private:
    FJA( FJA const &other );
    FJA &operator=( FJA const &other);

    static T const _setSequence( char *argv[] );
    static void mergeSort(typename U::iterator begin, typename U::iterator end);
    static void merge(typename U::iterator begin, typename U::iterator mid, typename U::iterator end);
    static T insertSequence(size_t n);
    static int jacobsthal(int n);
    static typename T::iterator binarySearch(int value, typename T::iterator left, typename T::iterator right);
    
    T const _sequence;
    U _pairs;
    T _unresolved;
    T _insertPositions;
    T _sortedTerms;
    
    void _makeSortedPairs();
    void _setHalfSortSequence();
    void _insertionSort();
    
    
    T const &getSequence() const;
    T &getSortedTerms();
    T &getUnresolved();
    T &getInsertPositions();
    U &getPairs();

  public:
    FJA();
    FJA(char *argv[]);
    virtual ~FJA();
        
    void MergeInsertionSort();
    void printBefore();
    void printAfter();
    

    class InvalidInputException: public std::exception {
      public:
        virtual const char *what() const throw() {
          return "Invalid Input";
        }
    };
};


class PmergeMeList : public FJA< std::list<int>, std::list<std::pair<int, int> > > 
{
  private:
    PmergeMeList( PmergeMeList const &other );  
    PmergeMeList &operator=( PmergeMeList const &other);

  public:
    PmergeMeList(char *argv[]);
    ~PmergeMeList();
};


class PmergeMeDeque : public FJA< std::deque<int>, std::deque<std::pair <int, int> > > 
{
  private:
    PmergeMeDeque( PmergeMeDeque const &other );  
    PmergeMeDeque &operator=( PmergeMeDeque const &other);

  public:
    PmergeMeDeque(char *argv[]);
    ~PmergeMeDeque();
};



#include "PmergeMe.LifeCycle.tpp"
#include "PmergeMe.Get.tpp"
#include "PmergeMe.tpp"