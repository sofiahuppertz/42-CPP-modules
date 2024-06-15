/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:23:13 by sofia             #+#    #+#             */
/*   Updated: 2024/06/10 15:22:11 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main ( void )
{
    std::string database = "static/data.csv";
    BitcoinExchange pricesForDate("static/data.csv");
    pricesForDate.processInputFile("static/input.csv");
    return 0;
}