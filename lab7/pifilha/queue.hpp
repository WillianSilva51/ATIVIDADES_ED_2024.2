#pragma once

#include <stack>

class queue
{
private:
    std::stack<int> deposito, pratilheira;

public:
    void push(int x);

    void pop();

    int front() const;

    bool empty() const;
};
