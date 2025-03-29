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

    // Construtor de cópia
    ForwardList(const ForwardList &lst)
    {
        m_head = new Node(0, nullptr);
        Node *ultimo = m_head;
        Node *aux = lst.m_head->next;
        while (aux != nullptr)
        {
            ultimo->next = new Node(aux->value, nullptr);
            ultimo = ultimo->next;
            aux = aux->next;
        }
        m_size = lst.m_size;
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

    // Sobrecarga do operador de igualdade: retorna true
    // se e somente se duas listas sao iguais
    bool operator==(const ForwardList &lst)
    {
        Node *aux1 = m_head->next;
        Node *aux2 = lst.m_head->next;

        while (aux1 != nullptr && aux2 != nullptr)
        {
            if (aux1->value != aux2->value)
            {
                return false;
            }
            aux1 = aux1->next;
            aux2 = aux2->next;
        }

        return true;
    }

    // Sobrecarga do operador de diferenca: retorna true
    // se e somente se duas listas sao diferentes
    bool operator!=(const ForwardList &lst)
    {
        Node *aux1 = m_head->next;
        Node *aux2 = lst.m_head->next;

        while (aux1 != nullptr && aux2 != nullptr)
        {
            if (aux1->value != aux2->value)
            {
                return true;
            }
            aux1 = aux1->next;
            aux2 = aux2->next;
        }

        return false;
    }

    // Troca o conteudo da lista pelo conteudo de lst,
    // que eh outro objeto ForwardList do mesmo tipo.
    // Os tamanhos das listas podem ser diferentes.
    // Apos a chamada para esta funcao membro, os elementos
    // nesta lista sao aqueles que estavam em lst antes da chamada,
    // e os elementos de lst sao aqueles que estavam nesta lista.
    void swap(ForwardList &lst)
    {
        Node *aux = m_head;
        m_head = lst.m_head;

        lst.m_head = aux;

        int aux_size = m_size;
        m_size = lst.m_size;
        lst.m_size = aux_size;
    }

    // Remove todas as ocorrencias do valor 'val' da sua lista.
    // Por exemplo, se voce tiver a lista [4,1,2,4,4,3,4,4] e chamar
    // essa funcao com o valor 4, a lista resultante sera [1,2,3].
    // Nao esqueca de liberar os nos.
    void remove(int value)
    {
        Node *aux = m_head;

        while (aux->next != nullptr)
        {
            if (aux->next->value == value)
            {
                Node *temp = aux->next;
                aux->next = aux->next->next;
                delete temp;

                m_size--;
            }
            else
                aux = aux->next;
        }
    }
    // Esta funcao concatena a lista atual com a lista lst passada por parametro.
    // A lista lst fica vazia apos a chamada dessa funcao.
    // Exemplo: dadas as listas a = [1,2,3] e b = [7,8,9,10], apos chamar o comando
    // a.concat(b) as listas terao os seguintes conteudos: a = [1,2,3,7,8,9,10] e b = [].
    // Nao esqueca de ajustar o valor do m_size das duas listas.
    void concat(ForwardList &lst)
    {
        Node *aux = m_head;
        while (aux->next != nullptr)
        {
            aux = aux->next;
        }

        aux->next = lst.m_head->next;
        m_size += lst.m_size;

        lst.m_head->next = nullptr;
        lst.m_size = 0;

        lst.clear();
    }

    // Reverte a ordem dos elementos na lista.
    // Por exemplo, se voce tiver a lista [10,30,40,50], entao apos
    // chamar essa funcao a sua lista torna-se [50,40,30,10].
    // A complexidade dessa funcao deve ser O(n). Alem disso, faca essa
    // funcao SEM ALOCAR NOVOS NODES. Eh possivel fazer essa funcao sem
    // alocar novos nos. Voce precisara apenas de tres ponteiros adicionais
    // para te ajudar a reverter a sua lista.
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = m_head->next;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        m_head->next = prev;
    }
};

#endif // Fim da classe