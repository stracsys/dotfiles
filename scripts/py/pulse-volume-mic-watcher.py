#!/usr/bin/env python3
from pulsectl import Pulse, PulseLoopStop
import sys

with Pulse() as pulse:
  def callback(ev):
    if ev.index == source_index: raise PulseLoopStop
  def current_status(source):
    return round(source.volume.value_flat * 100), source.mute == 1
  try:
    sources = {s.index:s for s in pulse.source_list()}
    if len(sys.argv) > 1:
      # Sink index from command line argument if provided
      source_index = int(sys.argv[1])
      if not source_index in sources:
        raise KeyError(f"Sink index {source_index} not found in list of sources.")
    else:
      # Automatic determination of default source otherwise
      default_source_name = pulse.server_info().default_source_name
      try:
        source_index = next(index for index, source in sources.items()
                          if source.name == default_source_name)
      except StopIteration: raise StopIteration("No default source was found.")

    pulse.event_mask_set('source')
    pulse.event_callback_set(callback)
    last_value, last_mute = current_status(sources[source_index])

    while True:
      pulse.event_listen()
      sources = {s.index:s for s in pulse.source_list()}
      value, mute = current_status(sources[source_index])
      if value != last_value or mute != last_mute:
        print(str(value) + ('!' if mute else ''))
        last_value, last_mute = value, mute
      sys.stdout.flush()

  except Exception as e:
    print(f"ERROR: {e}", file=sys.stderr)
