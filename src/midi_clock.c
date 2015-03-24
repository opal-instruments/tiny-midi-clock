#include "midi_clock.h"

// Returns the number of microseconds that transpire
// for each MIDI CLOCK pulse for the passed in bpm.
uint32_t microseconds_per_pulse(float bpm) {
  return ((MINUTE * MICROSECOND) / bpm);
}

// Returns the number of microseconds per pulse that
// transpire for each MIDI CLOCK pusle for the passed in
// clock and bpm.
uint32_t clock_microseconds_per_pulse(ppqn_clock_t * c, float bpm) {
  return microseconds_per_pulse(bpm) * (c->timebase / MIDI_CLOCK_PRECISION);
}
