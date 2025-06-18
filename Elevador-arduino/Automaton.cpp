#include "include/Automaton.h"
#include "include/Event.h"

Automaton::Automaton(int numStates, Event *enabledEventStates, int (*MakeTransition)(int state, Event eventOccurred), void (*Loop)(int state))
    : numStates(numStates), enabledEventStates(enabledEventStates), MakeTransition(MakeTransition), Loop(Loop) {}

Automaton::Automaton() {}

Automaton::~Automaton() {}

void Automaton::setEvent(Event event)
{
    actualEvent = event;
}

void Automaton::setActualState(int state)
{
    actualState = state;
}

int Automaton::getActualState()
{
    return actualState;
}

int Automaton::getNumStates()
{
    return numStates;
}

Event Automaton::getEnabledEvent()
{
    return enabledEventStates[actualState];
}

void getEventControllable(Event &eventControllable){
	if(EventControllable_subir()){
		setBit(eventControllable,EVENT_SUBIR, true);
	}
	if(EventControllable_parar()){
		setBit(eventControllable,EVENT_PARAR, true);
	}
	if(EventControllable_descer()){
		setBit(eventControllable,EVENT_DESCER, true);
	}
	if(EventControllable_abrir_porta()){
		setBit(eventControllable,EVENT_ABRIR_PORTA, true);
	}
}


void getEventUncontrollable(Event &eventUncontrollable){
	if(EventUncontrollable_s_2()){
		setBit(eventUncontrollable,EVENT_S_2, true);
	}
	if(EventUncontrollable_s_1()){
		setBit(eventUncontrollable,EVENT_S_1, true);
	}
	if(EventUncontrollable_s_3()){
		setBit(eventUncontrollable,EVENT_S_3, true);
	}
	if(EventUncontrollable_s_4()){
		setBit(eventUncontrollable,EVENT_S_4, true);
	}
	if(EventUncontrollable_fechar_porta()){
		setBit(eventUncontrollable,EVENT_FECHAR_PORTA, true);
	}
}


GenericAction ActionAutomatons0[3]={ &StateActionAutomaton0_MotorState0,&StateActionAutomaton0_MotorState1,&StateActionAutomaton0_MotorState2 };
GenericAction ActionAutomatons1[4]={ &StateActionAutomaton1_AndaresState0,&StateActionAutomaton1_AndaresState1,&StateActionAutomaton1_AndaresState2,&StateActionAutomaton1_AndaresState3 };
GenericAction ActionAutomatons2[2]={ &StateActionAutomaton2_PortaState0,&StateActionAutomaton2_PortaState1 };
GenericAction ActionAutomatons3[1]={[](){}};


void Automaton0Loop_Motor(int State){
	ActionAutomatons0[State]();
}

void Automaton1Loop_Andares(int State){
	ActionAutomatons1[State]();
}

void Automaton2Loop_Porta(int State){
	ActionAutomatons2[State]();
}

void Automaton3Loop_SupAndaresMotorPortaEspecificacaoSegurancaAndarMaximo4EspecificacaoSegurancaAndarMinimo1Portae2Portae3Portae1(int State){
	ActionAutomatons3[State]();
}



int MakeTransitionAutomaton0_Motor(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_SUBIR))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DESCER))){ 
		return 2;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 0;
	}
	if (State == 2 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton1_Andares(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_S_1))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 2;
	}
	if (State == 2 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 1;
	}
	if (State == 2 && (getBit(eventOccurred,EVENT_S_4))){ 
		return 3;
	}
	if (State == 3 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 2;
	}

	return(State);
}

int MakeTransitionAutomaton2_Porta(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_ABRIR_PORTA))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_FECHAR_PORTA))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton3_SupAndaresMotorPortaEspecificacaoSegurancaAndarMaximo4EspecificacaoSegurancaAndarMinimo1Portae2Portae3Portae1(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 16;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_SUBIR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 17;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 2;
	}
	if (State == 2 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 3;
	}
	if (State == 2 && (getBit(eventOccurred,EVENT_ABRIR_PORTA))){ 
		return 19;
	}
	if (State == 3 && (getBit(eventOccurred,EVENT_S_1))){ 
		return 2;
	}
	if (State == 3 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 5;
	}
	if (State == 3 && (getBit(eventOccurred,EVENT_ABRIR_PORTA))){ 
		return 4;
	}
	if (State == 4 && (getBit(eventOccurred,EVENT_S_1))){ 
		return 19;
	}
	if (State == 4 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 7;
	}
	if (State == 4 && (getBit(eventOccurred,EVENT_FECHAR_PORTA))){ 
		return 16;
	}
	if (State == 5 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 3;
	}
	if (State == 5 && (getBit(eventOccurred,EVENT_S_4))){ 
		return 6;
	}
	if (State == 5 && (getBit(eventOccurred,EVENT_ABRIR_PORTA))){ 
		return 7;
	}
	if (State == 6 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 5;
	}
	if (State == 6 && (getBit(eventOccurred,EVENT_ABRIR_PORTA))){ 
		return 8;
	}
	if (State == 7 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 4;
	}
	if (State == 7 && (getBit(eventOccurred,EVENT_S_4))){ 
		return 8;
	}
	if (State == 7 && (getBit(eventOccurred,EVENT_FECHAR_PORTA))){ 
		return 9;
	}
	if (State == 8 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 7;
	}
	if (State == 8 && (getBit(eventOccurred,EVENT_FECHAR_PORTA))){ 
		return 10;
	}
	if (State == 9 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 16;
	}
	if (State == 9 && (getBit(eventOccurred,EVENT_S_4))){ 
		return 10;
	}
	if (State == 9 && (getBit(eventOccurred,EVENT_SUBIR))){ 
		return 14;
	}
	if (State == 9 && (getBit(eventOccurred,EVENT_DESCER))){ 
		return 12;
	}
	if (State == 10 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 9;
	}
	if (State == 10 && (getBit(eventOccurred,EVENT_DESCER))){ 
		return 11;
	}
	if (State == 11 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 12;
	}
	if (State == 11 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 6;
	}
	if (State == 12 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 13;
	}
	if (State == 12 && (getBit(eventOccurred,EVENT_S_4))){ 
		return 11;
	}
	if (State == 12 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 5;
	}
	if (State == 13 && (getBit(eventOccurred,EVENT_S_1))){ 
		return 18;
	}
	if (State == 13 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 12;
	}
	if (State == 13 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 3;
	}
	if (State == 14 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 17;
	}
	if (State == 14 && (getBit(eventOccurred,EVENT_S_4))){ 
		return 15;
	}
	if (State == 14 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 5;
	}
	if (State == 15 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 14;
	}
	if (State == 15 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 6;
	}
	if (State == 16 && (getBit(eventOccurred,EVENT_S_1))){ 
		return 0;
	}
	if (State == 16 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 9;
	}
	if (State == 16 && (getBit(eventOccurred,EVENT_SUBIR))){ 
		return 17;
	}
	if (State == 16 && (getBit(eventOccurred,EVENT_DESCER))){ 
		return 13;
	}
	if (State == 17 && (getBit(eventOccurred,EVENT_S_1))){ 
		return 1;
	}
	if (State == 17 && (getBit(eventOccurred,EVENT_S_3))){ 
		return 14;
	}
	if (State == 17 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 3;
	}
	if (State == 18 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 13;
	}
	if (State == 18 && (getBit(eventOccurred,EVENT_PARAR))){ 
		return 2;
	}
	if (State == 19 && (getBit(eventOccurred,EVENT_S_2))){ 
		return 4;
	}
	if (State == 19 && (getBit(eventOccurred,EVENT_FECHAR_PORTA))){ 
		return 0;
	}

	return(State);
}


