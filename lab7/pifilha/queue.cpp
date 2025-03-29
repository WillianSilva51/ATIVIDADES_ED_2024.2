#include "queue.hpp"

void queue::push(int x)
{
    deposito.push(x);

    if (empty())
    {
        pratilheira.push(x);
        deposito.pop();
    }
}

void queue::pop()
{
    pratilheira.pop();

    if (empty())
    {
        while (deposito.size() != 0)
        {
            pratilheira.push(deposito.top());
            deposito.pop();
        }
    }
}

int queue::front() const
{
    return pratilheira.top();
}

bool queue::empty() const
{
    return pratilheira.empty();
}