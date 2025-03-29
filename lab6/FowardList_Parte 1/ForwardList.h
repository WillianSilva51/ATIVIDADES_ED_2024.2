#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>
#include "Iterator.h"
#include "ConstIterator.h"
#include "Node.h"

class ForwardList
{
private:
    Node *m_head; // ponteiro para o sentinela
    int m_size;   // numero de elementos na lista

public:
    // retorna um Iterator apontando
    // para o primeiro elemento da lista
    Iterator begin()
    {
        return Iterator(m_head->next);
    }

    // retorna um Iterator apontando para a posicao
    // anterior ao primeiro elemento da lista.
    Iterator before_begin()
    {
        return Iterator(m_head);
    }

    // retorna um Iterator para a posicao
    // após o ultimo elemento
    Iterator end()
    {
        return Iterator(nullptr);
    }

    // retorna um ConstIterator apontando
    // para o primeiro elemento da lista
    ConstIterator begin() const
    {
        return ConstIterator(m_head->next);
    }

    // retorna um ConstIterator apontando para a posicao
    // anterior ao primeiro elemento da lista.
    ConstIterator before_begin() const
    {
        return ConstIterator(m_head);
    }

    // retorna um ConstIterator para a posicao
    // apos o ultimo elemento
    ConstIterator end() const
    {
        return ConstIterator(nullptr);
    }

    // Construtor default: cria lista vazia
    ForwardList()
    {
        m_head = new Node(0, nullptr);
        m_size = 0;
    }

    // Insere um elemento no inicio da lista
    void push_front(int val)
    {
        Node *aux = new Node(val, m_head->next);
        m_head->next = aux;
        m_size++;
    }

    // Funcao que remove o primeiro elemento da lista
    void pop_front()
    {
        if (m_head->next != nullptr)
        {
            // aponta para o primeiro elemento
            Node *aux1 = m_head->next;
            // faz o sentinela apontar para o segundo
            m_head->next = aux1->next;
            // delete o primeiro elemento
            delete aux1;
            // decrementa m_size
            m_size--;
        }
    }

    // Funcao que retorna o tamanho da lista
    int size() const
    {
        return m_size;
    }

    // Funcao que diz se a lista esta vazia
    bool empty() const
    {
        return m_head->next == nullptr;
    }

    // Funcao que deixa a lista vazia, com 0 elementos
    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    // Destrutor: libera todos os nos, inclusive o sentinela
    ~ForwardList()
    {
        clear();
        delete m_head;
    }

    // Sobercarga do operador de atribuicao
    // Faz uma copia da lista passada como entrada
    ForwardList &operator=(const ForwardList &lst)
    {
        this->clear(); // limpa a minha lista
        Node *atual = lst.m_head->next;
        Node *ultimo = this->m_head;
        while (atual != nullptr)
        {
            ultimo->next = new Node(atual->value, nullptr);
            ultimo = ultimo->next;
            atual = atual->next;
        }
        this->m_size = lst.m_size;
        return *this;
    }

    // Sobrecarga do operador<<
    // Esse operador permite imprimir o conteudo da lista no terminal cout
    friend std::ostream &operator<<(std::ostream &out, const ForwardList &lst)
    {
        out << "[ ";
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            out << *it << " ";
        }
        out << "]";
        return out;
    }

    // Retorna uma referencia para o primeiro elemento da lista.
    // Essa funcao nao checa se a lista esta vazia,
    // ela apenas retorna o que estiver na frente.
    int &front()
    {
        return m_head->next->value;
    }

    // Retorna uma referencia constante para o primeiro elemento da lista.
    // Essa funcao nao checa se a lista esta vazia,
    // ela apenas retorna o que estiver na frente.
    const int &front() const
    {
        return m_head->next->value;
    }

    // Insere um elemento ao final da lista
    void push_back(int value)
    {
        Node *aux = m_head;

        while (aux->next != nullptr)
            aux = aux->next;

        aux->next = new Node(value, nullptr);

        m_size++;
    };

    // Remove o ultimo elemento da lista, se houver.
    void pop_back()
    {
        if (m_head->next == nullptr)
            return;

        Node *aux = m_head;
        Node *prev = nullptr;

        while (aux->next != nullptr)
        {
            prev = aux;
            aux = aux->next;
        }

        if (prev != nullptr)
            prev->next = nullptr;

        delete aux;
        m_size--;
    };

    // Retorna uma referencia para o ultimo elemento da lista.
    // Essa funcao nao checa se a lista esta vazia,
    // ela apenas retorna o que estiver na frente.
    int &back()
    {
        Node *aux = m_head;

        while (aux->next != nullptr)
            aux = aux->next;

        return aux->value;
    }

    // Retorna uma referencia constante para o ultimo elemento da lista.
    // Essa funcao nao checa se a lista esta vazia,
    // ela apenas retorna o que estiver na frente.
    const int &back() const
    {
        Node *aux = m_head;

        while (aux->next != nullptr)
            aux = aux->next;

        return aux->value;
    }

    // Construtor de copia: recebe uma referencia para uma ForwardList
    // lst e inicializa a nova lista com os elementos de lst.
    ForwardList(const ForwardList &lst)
    {
        if (lst.empty())
        {
            m_head = new Node(0, nullptr);
            m_size = 0;
        }
        else
        {
            m_head = new Node(0, nullptr);
            Node *atual = lst.m_head->next;
            Node *ultimo = m_head;
            while (atual != nullptr)
            {
                ultimo->next = new Node(atual->value, nullptr);
                ultimo = ultimo->next;
                atual = atual->next;
            }
            m_size = lst.m_size;
        }
    }
};

#endif