#ifndef NOTIFIER_H
#define NOTIFIER_H

/* Nome do módulo :         Notifier
 * Ano de criação :         2019/09
 * Descrição do módulo :    Modulo de Padrão de Projeto Observer para implementação de notificador de eventos
 * Versão :                 1.0
 * Pré-requisitos :         Observer
 *                          list (biblioteca padrão)
 * Membros :                Gabriel Pietroluongo
 */
#include "observer.h"
#include <list>
using namespace std;

class Notifier {
    list<Observer*> observadores;
public:
    /* Nome da função :     registraObservador
     * Intenção da função : Registrar observadores a serem notificados do evento
     * Pré-requisitos :     Nenhum
     * Efeitos colaterais : O observador registrado entra na lista de observadores
     * Parâmetros :         Observer : observador a ser registrado
     * Retorno :            Nenhum
     */
    void registraObservador(Observer& o);

    /* Nome da função :     removeObservador
     * Intenção da função : Não notificar mais esse observador sobre o evento
     * Pré-requisitos :     O observador deve estar registrado
     * Efeitos colaterais : Retira o Observador da lista de observadores
     * Parâmetros :         Observer : observador a res removido
     * Retorno :            Nenhum
     */
    void removeObservador(Observer& o);

    /* Nome da função :     notifica
     * Intenção da função : Notificar os observadores sobre o evento
     * Pré-requisitos :     Nenhum
     * Efeitos colaterais : Os observadores são notificados do evento
     * Parâmetros :         Nenhum
     * Retorno :            Nenhum
     */
    void notifica();
};
#endif