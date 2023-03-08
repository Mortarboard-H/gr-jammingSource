# gr-jammingSource

A gnuradio module for jamming signal generation.

## Requirements

This module is compatible with **gnuradio 3.10**.

## Blocks

**TDMSingle**

A block that produce continuous wave (CW) jamming signal with TDM center frequency. 

There are three parameters:

sampling rate: sampling rate. in Hz

frequencies: the center dopplers you want to jam around the center frequency of authentic signal. in Hz

period: the length of every loop. in seconds.

**AperiodicSpectrumMatched**

A block produce aperiodic spectrum matched jamming signals. This block produce sequence of -1 and 1.

Two parameters:

Sample Rate: sampling frequency

Chip Rate: Chip rate

**known issue**: this block sometimes causes sudden exit with (code -11). This problem happens randomly. 

**Chirp**

This block generates chrip signals.

Four parameters:

Sample Rate: sampling frequency

min frequency: the minimum frequency in the chirp

max frequency: the maximum frequency in the chirp

period: the length of one loop

**testSingle**

This block generates signals of variant frequency. This source produces signal of one frequency for a certain time and stop and produces signals of another frequency for a certain time....

Five parameters:

Sample Rate: sampling frequency

start frequency: the start frequency of the source.

step: The frequency step added to current frequency.

length: the time when jamming signal is on. In seconds

interval: the time between each frequency. In seconds.

**gainTest**

This block implements a simple gain control method. Signals pass through will be add the desired gain by dB.

The added gain start from "start" and add "step" per "period"