/* 
 * The software for the x0xb0x is available for use in accordance with the 
 * following open source license (MIT License). For more information about
 * OS licensing, please visit -> http://www.opensource.org/
 *
 * For more information about the x0xb0x project, please visit
 * -> http://www.ladyada.net/make/x0xb0x
 *
 *                                     *****
 * Copyright (c) 2005 Limor Fried
 *
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *                                     *****
 *
 */

#ifndef _MIDI_H_
#define _MIDI_H_

// midi channel messages
#define MIDI_IGNORE 0x0  // ignore running status
#define MIDI_NOTE_ON 0x9
#define MIDI_NOTE_OFF 0x8
#define MIDI_PITCHBEND 0xE
#define MIDI_CONTROLLER 0xB

#define MIDI_ALL_NOTES_OFF 123

// system messages
#define MIDI_START 0xFA
#define MIDI_CONTINUE 0xFB
#define MIDI_STOP 0xFC
#define MIDI_CLOCK 0xF8
#define MIDI_SONG_POS_PTR 0xF2  // selects where in the track/pattern to play in relevant modes
#define MIDI_SONG_SELECT 0xF3   // selects which track/pattern to play

#define MIDISYNC_PPQ 24

int midi_putchar(char c);
int midi_getch(void);
int midi_getchar(void);
void do_midi_mode(void);

void init_midi(void);

uint8_t get_midi_addr(uint8_t eeaddr);

void midi_note_off(uint8_t note, uint8_t velocity);
void midi_note_on(uint8_t note, uint8_t velocity);

void midi_send_note_on(uint8_t note);
void midi_send_note_off(uint8_t note);

uint8_t midi_recv_cmd(void);

void midi_stop(void);
void midi_notesoff(void);

#endif
