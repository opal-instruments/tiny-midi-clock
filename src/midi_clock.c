#include "midi_clock.h"

uint32_t pulses_per_midi_clock(ppqn_clock_t * c) {
  return (c->timebase / MIDI_CLOCK_PRECISION);
}

uint32_t microseconds_per_midi_clock(float bpm) {
  return ((MINUTE * MICROSECOND) / (MIDI_CLOCK_PRECISION * bpm));
}

uint32_t microseconds_per_pulse(ppqn_clock_t * c, float bpm) {
  return (pulses_per_midi_clock(c) * microseconds_per_midi_clock(bpm));
}
