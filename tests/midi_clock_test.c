#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include "../src/midi_clock.h"

START_TEST (test_microseconds_per_pulse) {
  ppqn_clock_t * clock = calloc(sizeof(ppqn_clock_t*), 1);
  clock->timebase = 96;
  uint32_t res = microseconds_per_pulse(clock, 120.0);
  fail_if(res != 83332);
} END_TEST

START_TEST (test_microseconds_per_midi_clock) {
  uint32_t res = microseconds_per_midi_clock(120.0);
  fail_if(res != 20833);
} END_TEST

START_TEST (test_pulses_per_midi_clock) {
  ppqn_clock_t * clock = calloc(sizeof(ppqn_clock_t*), 1);
  clock->timebase = 96;
  uint32_t res = pulses_per_midi_clock(clock);
  fail_if(res != 4);
} END_TEST

Suite * new_beat_clock_suite() {
  Suite * s = suite_create("beat_clock");

  TCase * tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_microseconds_per_pulse);
  tcase_add_test(tc_core, test_microseconds_per_midi_clock);
  tcase_add_test(tc_core, test_pulses_per_midi_clock);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int num_failed = 0;

  Suite * beat_clock_suite = new_beat_clock_suite();
  SRunner * beat_clock_suite_runner = srunner_create(beat_clock_suite);

  srunner_run_all(beat_clock_suite_runner, CK_NORMAL);
  num_failed = srunner_ntests_failed(beat_clock_suite_runner);

  srunner_free(beat_clock_suite_runner);

  return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
