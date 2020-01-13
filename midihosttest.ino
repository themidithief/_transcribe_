// /*
//  *******************************************************************************
//  * USB-MIDI to Legacy Serial MIDI converter
//  * Copyright (C) 2012-2017 Yuuichi Akagawa
//  *
//  * Idea from LPK25 USB-MIDI to Serial MIDI converter
//  *   by Collin Cunningham - makezine.com, narbotic.com
//  *
//  * This is sample program. Do not expect perfect behavior.
//  *******************************************************************************
//  */

// #include <usbh_midi.h>
// #include <usbhub.h>

// // Satisfy the IDE, which needs to see the include statment in the ino too.
// #ifdef dobogusinclude
// #include <spi4teensy3.h>
// #endif
// #include <SPI.h>

// // #ifdef USBCON
// // #define _MIDI_SERIAL_PORT Serial1
// // #else
// // #define _MIDI_SERIAL_PORT Serial
// // #endif
// //////////////////////////
// // MIDI Pin assign
// // 2 : GND
// // 4 : +5V(Vcc) with 220ohm
// // 5 : TX
// //////////////////////////

// USB Usb;
// USBH_MIDI  Midi(&Usb);

// void MIDI_poll();
// void doDelay(uint32_t t1, uint32_t t2, uint32_t delayTime);

// void setup()
// {
//   Serial.begin(31250);
//   Serial1.begin(31250);

//   if (Usb.Init() == -1) {
//     while (1); //halt
//   }//if (Usb.Init() == -1...
//   delay( 200 );
// }

// void loop()
// {
//   Usb.Task();
//   uint32_t t1 = (uint32_t)micros();
//   MIDI_poll();

//   //delay(1ms)
//   doDelay(t1, (uint32_t)micros(), 1000);
// }

// // Poll USB MIDI Controler and send to serial MIDI
// void MIDI_poll()
// {
//   uint8_t outBuf[ 3 ];
//   uint8_t size;

//   do {
//     if ( (size = Midi.RecvData(outBuf)) > 0 ) {
//       //MIDI Output
//       Serial.write(outBuf, size);
//       Serial1.write(outBuf, size);
//     }
//   } while (size > 0);
// }

// // Delay time (max 16383 us)
// void doDelay(uint32_t t1, uint32_t t2, uint32_t delayTime)
// {
//   uint32_t t3;

//   t3 = t2 - t1;
//   if ( t3 < delayTime ) {
//     delayMicroseconds(delayTime - t3);
//   }
// }