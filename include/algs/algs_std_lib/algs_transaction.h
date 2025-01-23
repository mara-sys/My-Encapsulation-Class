#ifndef MY_ENCAP_ALGS_TRANSACTION_H
#define MY_ENCAP_ALGS_TRANSACTION_H

#include "./algs_date.h"

#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <functional>
#include <cstdio>

class AlgsTransaction {
private:
    std::string who_;
    EncapDate   when_;
    double      amount_;
public:
    /**
     * Default constructor
     */
    AlgsTransaction() {};

    /**
     * Initializes a new transaction from the given arguments.
     *
     * @param  who the person involved in this transaction
     * @param  when the date of this transaction
     * @param  amount the amount of this transaction
     * @throws IllegalArgumentException if {@code amount}
     *         is {@code Double.NaN}, {@code Double.POSITIVE_INFINITY},
     *         or {@code Double.NEGATIVE_INFINITY}
     */
    AlgsTransaction(std::string who, EncapDate when, double amount);

    /**
     * Initializes a new transaction by parsing a string of the form NAME DATE AMOUNT.
     *
     * @param  transaction the string to parse
     * @throws IllegalArgumentException if {@code amount}
     *         is {@code Double.NaN}, {@code Double.POSITIVE_INFINITY},
     *         or {@code Double.NEGATIVE_INFINITY}
     */
    AlgsTransaction(std::string transaction);
    inline std::string Who() { return who_; }
    inline EncapDate When() { return when_; }
    inline double Amount() { return amount_; }
    std::string ToString();
    int HashCode();

    bool operator<(const AlgsTransaction &that) const;
    bool operator==(const AlgsTransaction &that) const;

    static bool WhoOrder(AlgsTransaction v, AlgsTransaction w);
    static bool WhenOrder(AlgsTransaction v, AlgsTransaction w);
    static bool HowMuchOrder(AlgsTransaction v, AlgsTransaction w);
};

#endif