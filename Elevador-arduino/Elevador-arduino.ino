#include "include/Automaton.h"
#include "include/Event.h"

// Define the number of automatons
#define NUMBER_AUTOMATON 3
#define NUMBER_SUPERVISOR 1

int actualState;

// Functions
void executeTransition(Event eventOccurred);

// Initialize Events
int firstEventUncontrollable = 0;
int firstEventControllable = 0;

Event eventControllable = createEvent();
Event eventUncontrollable = createEvent();

Event eventEnabledControllable = createEvent();
Event eventEnabledUncontrollable = createEvent();

Event emptyEvent = createEvent();
Event eventEnabled = createEvent();

Event eventOccurred = createEvent();

// Create a vector to store the automatons
Automaton automata[NUMBER_AUTOMATON];
Automaton supervisor[NUMBER_SUPERVISOR];

uint8_t eventDataAUT0EV0[2] = {0b11111111, 0b01111111};
uint8_t eventDataAUT0EV1[2] = {0b11111110, 0b10111111};
uint8_t eventDataAUT0EV2[2] = {0b11111110, 0b10111111};

Event enabledEventStatesAutomaton0[3] = { createEventFromData(eventDataAUT0EV0), createEventFromData(eventDataAUT0EV1), createEventFromData(eventDataAUT0EV2)};
uint8_t eventDataAUT1EV0[2] = {0b11111111, 0b11100011};
uint8_t eventDataAUT1EV1[2] = {0b11111111, 0b11011011};
uint8_t eventDataAUT1EV2[2] = {0b11111111, 0b11100111};
uint8_t eventDataAUT1EV3[2] = {0b11111111, 0b11001011};

Event enabledEventStatesAutomaton1[4] = { createEventFromData(eventDataAUT1EV0), createEventFromData(eventDataAUT1EV1), createEventFromData(eventDataAUT1EV2), createEventFromData(eventDataAUT1EV3)};
uint8_t eventDataAUT2EV0[2] = {0b11111111, 0b11111101};
uint8_t eventDataAUT2EV1[2] = {0b11111111, 0b11111110};

Event enabledEventStatesAutomaton2[2] = { createEventFromData(eventDataAUT2EV0), createEventFromData(eventDataAUT2EV1)};
uint8_t eventDataAUT3EV0[2] = {0b11111111, 0b00100000};
uint8_t eventDataAUT3EV1[2] = {0b11111110, 0b10100000};
uint8_t eventDataAUT3EV2[2] = {0b11111110, 0b00100001};
uint8_t eventDataAUT3EV3[2] = {0b11111110, 0b00011001};
uint8_t eventDataAUT3EV4[2] = {0b11111110, 0b00011010};
uint8_t eventDataAUT3EV5[2] = {0b11111110, 0b00100101};
uint8_t eventDataAUT3EV6[2] = {0b11111110, 0b00001001};
uint8_t eventDataAUT3EV7[2] = {0b11111110, 0b00100110};
uint8_t eventDataAUT3EV8[2] = {0b11111110, 0b00001010};
uint8_t eventDataAUT3EV9[2] = {0b11111111, 0b01100100};
uint8_t eventDataAUT3EV10[2] = {0b11111110, 0b01001000};
uint8_t eventDataAUT3EV11[2] = {0b11111110, 0b10001000};
uint8_t eventDataAUT3EV12[2] = {0b11111110, 0b10100100};
uint8_t eventDataAUT3EV13[2] = {0b11111110, 0b10011000};
uint8_t eventDataAUT3EV14[2] = {0b11111110, 0b10100100};
uint8_t eventDataAUT3EV15[2] = {0b11111110, 0b10001000};
uint8_t eventDataAUT3EV16[2] = {0b11111111, 0b01011000};
uint8_t eventDataAUT3EV17[2] = {0b11111110, 0b10011000};
uint8_t eventDataAUT3EV18[2] = {0b11111110, 0b10100000};
uint8_t eventDataAUT3EV19[2] = {0b11111110, 0b00100010};

Event enabledEventStatesAutomaton3[20] = { createEventFromData(eventDataAUT3EV0), createEventFromData(eventDataAUT3EV1), createEventFromData(eventDataAUT3EV2), createEventFromData(eventDataAUT3EV3), createEventFromData(eventDataAUT3EV4), createEventFromData(eventDataAUT3EV5), createEventFromData(eventDataAUT3EV6), createEventFromData(eventDataAUT3EV7), createEventFromData(eventDataAUT3EV8), createEventFromData(eventDataAUT3EV9), createEventFromData(eventDataAUT3EV10), createEventFromData(eventDataAUT3EV11), createEventFromData(eventDataAUT3EV12), createEventFromData(eventDataAUT3EV13), createEventFromData(eventDataAUT3EV14), createEventFromData(eventDataAUT3EV15), createEventFromData(eventDataAUT3EV16), createEventFromData(eventDataAUT3EV17), createEventFromData(eventDataAUT3EV18), createEventFromData(eventDataAUT3EV19)};


void setup()
{

    // Initialize the automatons
    
		automata[0] = Automaton(3,enabledEventStatesAutomaton0,&MakeTransitionAutomaton0_Motor,&Automaton0Loop_Motor);
		automata[1] = Automaton(4,enabledEventStatesAutomaton1,&MakeTransitionAutomaton1_Andares,&Automaton1Loop_Andares);
		automata[2] = Automaton(2,enabledEventStatesAutomaton2,&MakeTransitionAutomaton2_Porta,&Automaton2Loop_Porta);
		supervisor[0] = Automaton(20,enabledEventStatesAutomaton3,&MakeTransitionAutomaton3_SupAndaresMotorPortaEspecificacaoSegurancaAndarMaximo4EspecificacaoSegurancaAndarMinimo1Portae2Portae3Portae1,&Automaton3Loop_SupAndaresMotorPortaEspecificacaoSegurancaAndarMaximo4EspecificacaoSegurancaAndarMinimo1Portae2Portae3Portae1);

    Serial.begin(9600);
    setupPin();
}

// Execute the main cycle
void loop()
{

    // Get the system events
    doEveryLoop();
    getEventControllable(eventControllable);
    getEventUncontrollable(eventUncontrollable);

    // Free the events that are physically possible
    zeroEvent(eventEnabled);
    // Check the events that are physically possible
    for (int i = 0; i < NUMBER_AUTOMATON; i++)
    {
        actualState = automata[i].getActualState();
        bitwiseOr(eventEnabled, eventEnabled, automata[i].enabledEventStates[actualState]);
    }

    bitwiseAnd(eventEnabledUncontrollable, eventUncontrollable, eventEnabled);
    bitwiseAnd(eventEnabledControllable, eventControllable, eventEnabled);

    if (!areEqual(eventEnabledUncontrollable, emptyEvent))
    {
        for (int i = 0; i < NUMBER_EVENT; i++)
        {
            int index = (firstEventUncontrollable + i) % NUMBER_EVENT;
            // Get one Uncontrollable Event each time
            bool existEvent = getBit(eventEnabledUncontrollable, index);
            if (existEvent)
            {
                setBit(eventOccurred, index, true);
                executeTransition(eventOccurred);
                setBit(eventUncontrollable, index, false);

                zeroEvent(eventOccurred);
                break;
            }
        }

        zeroEvent(eventEnabledUncontrollable);
        firstEventUncontrollable = (firstEventUncontrollable + 1) % NUMBER_EVENT;
    }
    else
    {

        // Check the enabled events
        oneEvent(eventEnabled);
        for (int i = 0; i < NUMBER_SUPERVISOR; i++)
        {
            bitwiseAnd(eventEnabled, eventEnabled, supervisor[i].getEnabledEvent());
        }

        // Check if any enabled Controllable event was detected
        bitwiseAnd(eventEnabledControllable, eventEnabledControllable, eventEnabled);

        if (!areEqual(eventEnabledControllable, emptyEvent))
        {

            for (int i = 0; i < NUMBER_EVENT; i++)
            {
                int index = (firstEventControllable + i) % NUMBER_EVENT;

                // Get one Controllable Event each time
                bool existEvent = getBit(eventEnabledControllable, index);

                if (existEvent)
                {
                    setBit(eventOccurred, index, true);
                    executeTransition(eventOccurred);
                    setBit(eventControllable, index, false);

                    zeroEvent(eventOccurred);
                    break;
                }
            }

            zeroEvent(eventEnabledControllable);
            firstEventControllable = (firstEventControllable + 1) % NUMBER_EVENT;
        }

        zeroEvent(eventEnabled);
    }

    // Execute the Loop function for each automaton
    for (int i = 0; i < NUMBER_AUTOMATON; i++)
    {
        actualState = automata[i].getActualState();
        automata[i].Loop(actualState);
    }
}

void executeTransition(Event eventOccurred)
{
    // Execute the state transition for each supervisor
    for (int k = 0; k < NUMBER_SUPERVISOR; k++)
    {

        actualState = supervisor[k].getActualState();
        int nextState = supervisor[k].MakeTransition(actualState, eventOccurred);
        supervisor[k].setActualState(nextState);
    }

    // Execute the state transition for each automaton
    for (int j = 0; j < NUMBER_AUTOMATON; j++)
    {

        actualState = automata[j].getActualState();
        int nextState = automata[j].MakeTransition(actualState, eventOccurred);
        automata[j].setActualState(nextState);
    }
}
