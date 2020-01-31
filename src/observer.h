#ifndef OBSERVER_H
#define OBSERVER_H
/* Nome do módulo :         Observer
 * Ano de criação :         2019/09
 * Descrição do módulo :    Define Interface de observador a ser implementada por classes que desejam
 *                          ser notificadas por eventos de notifiers
 * Versão :                 1.0
 * Pré-requisitos :         Nenhum
 * Membros :                Gabriel Pietroluongo
 */

class Observer {
public:
    /* Nome da função :     notifica
     * Intenção da função : Notificar este observador sobre um evento
     * Pré-requisitos :     Nenhum
     * Efeitos colaterais : Depende de Implementações da Interface
     * Parâmetros :         Nenhum
     * Retorno :            Nenhum
     */
    virtual void notifica()=0;
};
#endif