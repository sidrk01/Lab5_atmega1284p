/*      Author: Sidharth Ramkumar (sramk002@ucr.edu)
 *  Partner(s) Name: none
 *      Lab Section: 022
 *      Assignment: Lab #5  Exercise #3
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#define b1 (~PINA & 0x01)

enum LED_Display {SMStart, Wait, L1, L2, L3, L4, L5, L6, L7, L8, L9 } LED_State;

void TickFct(){
   switch(LED_State) {
        case SMStart:
        LED_State = Wait;
        break;

        case Wait:
        if (b1){
        LED_State = L1;
        } else {
        LED_State = Wait;
        }
        break;

        case L1:
        if (b1){
        LED_State = L2;
        } else {
        LED_State = L1;
        }
        break;

        case L2:
        if (b1){
        LED_State = L3;
        } else {
        LED_State = L2;
        }
        break;

        case L3:
        if (b1){
        LED_State = L4;
        } else {
        LED_State = L3;
        }
        break;

        case L4:
        if (b1){
        LED_State = L5;
        } else {
        LED_State = L4;
        }
        break;

        case L5:
        if (b1){
        LED_State = L6;
        } else {
        LED_State = L5;
        }
        break;

        case L6:
        if (b1){
        LED_State = L7;
        } else {
        LED_State = L6;
        }
        break;

        case L7:
        if (b1){
        LED_State = L8;
        } else {
        LED_State = L7;
        }
        break;

        case L8:
        if (b1){
        LED_State = L9;
        } else {
        LED_State = L8;
        }
        break;

        case L9:
        if (b1){
        LED_State = Wait;
        } else {
        LED_State = L9;
        }
        break;
  }

   switch(LED_State){
        case Wait:
        PORTB = 0x00;
        break;
       
        case L1:
        case L5:
        PORTB = 0x21;
        break;

        case L2:
        case L4:
        PORTB = 0x12;
        break;

        case L3:
        PORTB = 0x0C;
        break;

        case L6:
        case L8:
        PORTB = 0x2D;
        break;

        case L7:
        case L9:
        PORTB = 0x12;
        break;

        default:
        PORTB = 0x00;
        break;

   }

}


int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
        LED_State = SMStart;
    while (1) {
        TickFct();
    }
    return 1;
}

