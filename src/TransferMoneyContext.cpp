/*
 *  TransferMoneyContext.cpp
 *
 *  Created by James Coplien on 9/13/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */

#include "TransferMoneyContext.h"
#include "InvestmentAccount.h"
#include "SavingsAccount.h"

TransferMoneyContext::TransferMoneyContext() : Context() {
    lookupBindings();
}

TransferMoneyContext::TransferMoneyContext(const Currency& amount, MoneySource *source,
                                           MoneySink *destination)
: Context() {
    sourceAccount_ = source;
    destinationAccount_ = destination;
    amount_ = amount;
}

void TransferMoneyContext::doit()
{
    sourceAccount()->transferTo();
}


void TransferMoneyContext::lookupBindings() {
    // These are somewhat arbitrary and for illustrative
    // purposes. The simulate a database lookup
    InvestmentAccount *investmentAccount = new InvestmentAccount;
    investmentAccount->increaseBalance(Euro(100.00)); // prime it with some money
    
    sourceAccount_ = investmentAccount;
    destinationAccount_ = new SavingsAccount;
    destinationAccount_->increaseBalance(Euro(500.00)); // start it off with money
    amount_ = Euro(30.00);
}

TransferMoneyContext::MoneySource *TransferMoneyContext::sourceAccount() const {
    return sourceAccount_;
}

TransferMoneyContext::MoneySink *TransferMoneyContext::destinationAccount() const {
    return destinationAccount_;
}

Currency TransferMoneyContext::amount() const
{
    return amount_;
}
