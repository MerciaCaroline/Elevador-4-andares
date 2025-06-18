

#ifndef EVENT_H
#define EVENT_H

#include <Arduino.h>
#include <stdint.h>

#define NUMBER_EVENT 9
#define SIZE_EVENT 2

struct Event
{
    uint8_t data[SIZE_EVENT];
};

Event createEvent();
Event createEventFromData(uint8_t *data);
void copyEvent(const Event source, Event &destination);

void setBit(Event &event, int position, bool value);
bool getBit(const Event event, int position);

void bitwiseAnd(Event &result, const Event &event1, const Event &event2);
void bitwiseOr(Event &result, const Event &event1, const Event &event2);
void bitwiseXor(Event &result, const Event &event1, const Event &event2);
void bitwiseNot(Event &result, const Event &event);

bool areEqual(const Event &event1, const Event &event2);

void zeroEvent(Event &event);
void oneEvent(Event &event);

void printEvent(const Event event);

#define EVENT_SUBIR 8
#define EVENT_PARAR 7
#define EVENT_DESCER 6
#define EVENT_S_2 5
#define EVENT_S_1 4
#define EVENT_S_3 3
#define EVENT_S_4 2
#define EVENT_FECHAR_PORTA 1
#define EVENT_ABRIR_PORTA 0


#endif