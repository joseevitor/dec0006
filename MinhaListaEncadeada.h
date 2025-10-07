#ifndef DEC0006_MINHA_LISTA_ENCADEADA_H
#define DEC0006_MINHA_LISTA_ENCADEADA_H

#include <cstddef>
// std::size_t

#include "Elemento.h"
// Elemento
#include "ListaEncadeadaAbstrata.h"
#include "excecoes.h"
// ExcecaoDadoInexistente
// ExcecaoListaEncadeadaVazia
// ExcecaoNaoImplementado
// ExcecaoPosicaoInvalida

/**
 * @brief Uma lista encadeada de dados.
 * 
 * @tparam T O tipo dos dados armazenados na lista.
 */
template<typename T>
class MinhaListaEncadeada: public ListaEncadeadaAbstrata<T>
{
    /**
     * @brief Destrutor. Destroi todos os elementos da lista
     */
    virtual ~MinhaListaEncadeada(){
        //escreva o algoritmo esperado
        for (size_t i = 0; i < count; i++)
        {
            
        }
        
    }

    /**
     * @brief Obtém a quantidade de itens na lista.
     * 
     * @return Um inteiro maior ou igual a 0.
     */
    virtual std::size_t tamanho() const
    {
        //substitua a linha abaixo pelo algoritmo esperado
        return this -> _tamanho;
    };
    
    /**
     * @brief Indica se há algum item na lista ou não.
     * 
     * @return false se houver algum item na lista; true caso contrário.
     */
    virtual bool vazia() const 
    {
        //substitua a linha abaixo pelo algoritmo esperado
        return this -> _primeiro == nullptr;
    };

    /**
     * @brief Obtém a posição de um item na lista. Lança
     * ExcecaoListaEncadeadaVazia caso a lista esteja vazia ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item cuja posição deseja-se obter.
     * @return Um inteiro na faixa [0, tamanho); se houver mais que um mesmo
     * item na lista, a posição da primeira ocorrência.
     */
    virtual std::size_t posicao(T dado) const 
    {
        //substitua a linha abaixo pelo algoritmo esperado
        
        if(this->_primeiro==nullptr)
            throw ExcecaoListaEncadeadaVazia();

        Elemento<T>* aux = this-> _primeiro;
        
        for(int i=0; this->_tamanho && aux != nullptr; i++){
            if(aux->dado == dado)
                return i;

            aux = aux->proximo;
        }
        throw ExcecaoDadoInexistente();

    };
    
    /**
     * @brief Indica se um dado item está contido na lista ou não.
     * 
     * @param dado O item sendo buscado.
     * @return true se o item está contido na lista; false caso contrário.
     */
    virtual bool contem(T dado) const
    {
        //substitua a linha abaixo pelo algoritmo esperado
        
        //Elemento<T>* dado_lista = _primeiro;
        for(Elemento<T>* dado_lista = this -> _primeiro; dado_lista != 0; dado_lista = dado_lista -> proximo){
            if(dado_lista -> dado == dado){
                return true;
            }       
        }
        return false; 
    };

    /**
     * @brief Insere um item no início da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoInicio(T dado) 
    {
        //escreva o algoritmo esperado
        Elemento<T>* nova_posicao = new Elemento<T>(dado);
        nova_posicao -> proximo = this->_primeiro;
        this->_primeiro = nova_posicao;
        this-> _tamanho++;
    };

    /**
     * @brief Insere um item em uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa
     * [0, tamanho].
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho]. Ao se inserir em
     * uma posição já ocupada, a posição do item que já estava naquela posição
     * será posicao + 1; inserir-se na posicao tamanho significa inserir-se no
     * fim da lista.
     * @param dado O item sendo inserido.
     */
    virtual void inserir(std::size_t posicao, T dado)
    {
        //escreva o algoritmo esperado
        Elemento<T>* novo_dado = new Elemento<T>(dado);

        if(posicao < 0 || posicao > this -> _tamanho)
            throw ExcecaoPosicaoInvalida();
         
        //if (posicao == this->_tamanho) {
        //    inserirNoFim(dado);
        //    return;
        //}

        if(posicao == 0){
            novo_dado -> proximo = this -> _primeiro;
            this -> _primeiro = novo_dado;

        } else{

            Elemento<T>* posicao_anterior = this -> _primeiro;

            for(std::size_t i = 0; i < posicao - 1; ++i){
                posicao_anterior = posicao_anterior -> proximo;
            }

            novo_dado -> proximo = posicao_anterior -> proximo;
            posicao_anterior -> proximo = novo_dado;
        }

        this -> _tamanho++;
    };



    /**
     * @brief Insere um item no fim da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoFim(T dado)
    {
        //escreva o algoritmo esperado
        Elemento<T>* novo_nodo = new Elemento<T>(dado);
        
        if(this->_primeiro == nullptr){
            this-> _primeiro = novo_nodo;
        } else{
            Elemento<T>* nodo = this -> _primeiro;
            
            while(nodo->proximo != nullptr){
                nodo = nodo -> proximo;
            }
            nodo->proximo = novo_nodo;
        }
        this->_tamanho++;
    };

    /**
     * @brief Remove o primeiro item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoInicio()
    {
        //substitua a linha abaixo pelo algoritmo esperado
        if(this->_primeiro == nullptr)
            throw ExcecaoListaEncadeadaVazia();
        else{
            Elemento<T>* primeiro_removido = this-> _primeiro;

            T _primeiro_dado = primeiro_removido -> dado;
            

            this-> _primeiro = primeiro_removido -> proximo;
            delete primeiro_removido;
            this-> _tamanho--;  
            return _primeiro_dado;         
        }

            

        
    };

    /**
     * @brief Remove um item de uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa [0, tamanho).
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho).
     * @return O item removido.
     */
    virtual T removerDe(std::size_t posicao)
    {
        //substitua a linha abaixo pelo algoritmo esperado
        if(posicao >= this -> _tamanho)
            throw ExcecaoPosicaoInvalida();

        Elemento<T>* posicao_removida;
        T dado_removido;

        if(posicao == 0){
            posicao_removida = this -> _primeiro;
            this->_primeiro = posicao_removida -> proximo;
            T dado_removido = posicao_removida -> dado;
            delete posicao_removida;
            this-> _tamanho--;
            return dado_removido;
        } else{
            Elemento<T>* posicao_anterior = this->_primeiro;
            for(std::size_t i=1; i < posicao; ++i){
                posicao_anterior = posicao_anterior -> proximo;
            }
        
            Elemento<T>* posicao_removida = posicao_anterior -> proximo;
            posicao_anterior -> proximo = posicao_removida -> proximo;
            dado_removido = posicao_removida -> dado;
            
            delete posicao_removida;
            this-> _tamanho--;

            return dado_removido;
        }
    };

    /**
     * @brief Remove o último item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoFim()
    {
        //substitua a linha abaixo pelo algoritmo esperado
        if(this-> _primeiro == nullptr)
            throw ExcecaoListaEncadeadaVazia();
            
        Elemento<T>* dado_removido;
        T dado;


        if(this-> _tamanho == 1){
            dado_removido = this->_primeiro;
            this->_primeiro = nullptr;
            
        }else{
            Elemento<T>* ptr_pro_anterior = this->_primeiro;
            for(std::size_t i= 1; i<this->_tamanho - 1; i++){
            ptr_pro_anterior = ptr_pro_anterior -> proximo;
            //ptr_pro_anterior -> this->_tamanho;
            
            }
            dado_removido = ptr_pro_anterior -> proximo;
            ptr_pro_anterior -> proximo = nullptr;
        
        }
        dado = dado_removido -> dado;
        delete dado_removido;
        this->_tamanho--;
        return dado;
    };

    /**
     * @brief Remove um item específico da lista. Lança
     * ExcecaoListaEncadeadaVazia caso não haja nenhum item na lista ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item a ser removido. Se houver mais que um item com
     * o mesmo valor, remove a primeira ocorrência.
     */
    virtual void remover(T dado)
    {
        //escreva o algoritmo esperado
        if(this->_primeiro == nullptr)
            throw ExcecaoListaEncadeadaVazia();

        if(this-> _primeiro -> dado == dado){
            Elemento<T>* primeiro_removido = this-> _primeiro;
            this-> _primeiro = primeiro_removido -> proximo;
            delete primeiro_removido;
            this-> _tamanho--;
            return;
        }
        
        Elemento<T>* _dado = this -> _primeiro;
            
        while (_dado->proximo != nullptr && _dado->proximo->dado != dado)
        //while(_dado -> proximo -> dado != dado && _dado -> proximo != nullptr){
            _dado = _dado -> proximo;

            
        if(_dado->proximo == nullptr)
            throw ExcecaoDadoInexistente();

        Elemento<T>* dado_removido = _dado -> proximo;
        _dado-> proximo = dado_removido -> proximo;
        delete dado_removido;
        this-> _tamanho--;
        
    };
};

#endif