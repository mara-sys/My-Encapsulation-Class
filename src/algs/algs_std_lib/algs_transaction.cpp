#include "../../include/algs/algs_std_lib/algs_transaction.h"

using std::vector;
using std::string;
using std::isnan;
using std::isinf;
using std::istringstream;
using std::stod;

AlgsTransaction::AlgsTransaction(string who, EncapDate when, double amount)
{
    if (isnan(amount) || isinf(amount))
        throw "Amount cannot be NaN or infinite";

    who_ = who;
    when_ = when;
    amount_ = amount;
}

AlgsTransaction::AlgsTransaction(string transaction)
{
    istringstream iss(transaction);
    vector<string> a;
    string temp;
    while (iss >> temp) {
        a.push_back(temp);
    }
    who_ = a[0];
    when_ = EncapDate(a[1]);
    amount_ = stod(a[2]);
    if (isnan(amount_) || isinf(amount_))
        throw "Amount cannot be NaN or infinite";
}

string AlgsTransaction::ToString()
{
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%-10s %10s %8.2f", who_.c_str(),
        when_.ToString().c_str(), amount_);
    return string(buffer);
}

int AlgsTransaction::HashCode()
{
    int hash = 1;
    hash = 31*hash + std::hash<string>{}(who_);
    hash = 31*hash + when_.HashCode();
    hash = 31*hash + std::hash<double>{}(amount_);
    return hash;
}

bool AlgsTransaction::operator<(const AlgsTransaction &that) const
{
    return amount_ < that.amount_;
}

bool AlgsTransaction::operator==(const AlgsTransaction &that) const
{
    if (&that == this)
        return true;
    return (amount_ == that.amount_ &&
            who_ == that.who_ &&
            when_ == that.when_);
}

bool AlgsTransaction::WhoOrder(AlgsTransaction v, AlgsTransaction w)
{
    return v.who_ < w.who_;
}

bool AlgsTransaction::WhenOrder(AlgsTransaction v, AlgsTransaction w)
{
    return v.when_ < w.when_;
}

bool AlgsTransaction::HowMuchOrder(AlgsTransaction v, AlgsTransaction w)
{
    return v.amount_ < w.amount_;
}