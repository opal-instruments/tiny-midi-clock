#ifndef _MIDI_BEAT_CLOCK
#define _MIDI_BEAT_CLOCK

#include <stdint.h>

static const uint8_t CLOCK = 0xF8;
static const uint8_t START = 0xFA;
static const uint8_t CONTINUE = 0xFB;
static const uint8_t STOP = 0xFC;
static const uint8_t MIDI_CLOCK_PRECISION = 24;
static const uint8_t MINUTE = 60;
static const uint32_t MICROSECOND = 1000000;

typedef struct ppqn_clock {
  uint8_t timebase;
} ppqn_clock_t;

uint32_t microseconds_per_pulse(float bpm);
uint32_t clock_microseconds_per_pulse(ppqn_clock_t * c, float bpm);

#endif
