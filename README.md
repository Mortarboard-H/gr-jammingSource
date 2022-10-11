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