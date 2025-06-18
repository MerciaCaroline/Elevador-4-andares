
#ifndef AUTOMATON_H
#define AUTOMATON_H

#include "Event.h"

typedef void (*GenericAction)();

class Automaton
{
public:
    Automaton(int numStates, Event *enabledEventStates, int (*MakeTransition)(int state, Event eventOccurred), void (*Loop)(int state));
    Automaton();
    ~Automaton();

    int getActualState();                                  // Returns the current state of the automaton
    int getNumStates();                                    // Returns the total number of states in the automaton
    Event getEnabledEvent();                               // Returns the value of enabled events for the automaton
    void setActualState(int state);                        // Sets the current state of the automaton
    void setEvent(Event event);                            // Sets the value of the current event of the automaton
    Event *enabledEventStates;                             // Pointer to the list of enabled event values
    int (*MakeTransition)(int state, Event eventOccurred); // Pointer to the state transition function
    void (*Loop)(int state);                               // Pointer to the current state execution function

private:
    int actualState = 0; // Current state of the automaton
    Event actualEvent;   // Value of the current event of the automaton
    int numStates;       // Total number of states in the automaton
};

void setupPin();
void doEveryLoop();
void getEventControllable(Event &eventControllable);     // Obtains Controllablble events
void getEventUncontrollable(Event &eventUncontrollable); // Obtains Uncontrollablble events

void Automaton0Loop_Motor(int State); 

void Automaton1Loop_Andares(int State); 

void Automaton2Loop_Porta(int State); 

void Automaton3Loop_SupAndaresMotorPortaEspecificacaoSegurancaAndarMaximo4EspecificacaoSegurancaAndarMinimo1Portae2Portae3Portae1(int State); 



bool EventControllable_subir();
bool EventControllable_parar();
bool EventControllable_descer();
bool EventControllable_abrir_porta();


bool EventUncontrollable_s_2();
bool EventUncontrollable_s_1();
bool EventUncontrollable_s_3();
bool EventUncontrollable_s_4();
bool EventUncontrollable_fechar_porta();


void StateActionAutomaton0_MotorState0();
void StateActionAutomaton0_MotorState1();
void StateActionAutomaton0_MotorState2();

void StateActionAutomaton1_AndaresState0();
void StateActionAutomaton1_AndaresState1();
void StateActionAutomaton1_AndaresState2();
void StateActionAutomaton1_AndaresState3();

void StateActionAutomaton2_PortaState0();
void StateActionAutomaton2_PortaState1();



int MakeTransitionAutomaton0_Motor(int State, Event eventOccurred);
int MakeTransitionAutomaton1_Andares(int State, Event eventOccurred);
int MakeTransitionAutomaton2_Porta(int State, Event eventOccurred);
int MakeTransitionAutomaton3_SupAndaresMotorPortaEspecificacaoSegurancaAndarMaximo4EspecificacaoSegurancaAndarMinimo1Portae2Portae3Portae1(int State, Event eventOccurred);


#endif