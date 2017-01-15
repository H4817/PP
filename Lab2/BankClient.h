#pragma once

#include "definitions.h"
#include "Bank.h"

class CBank;

class CBankClient {
public:
    unsigned GetId();

private:
    CBankClient(CBank *bank, unsigned id);

    static unsigned GetSleepDuration(CBankClient *client);

    static unsigned GetBalanceChangeValue();

    static DWORD ThreadFunction(LPVOID lpParam);

    friend CBank;

    CBank *m_bank;
    unsigned m_id;
};