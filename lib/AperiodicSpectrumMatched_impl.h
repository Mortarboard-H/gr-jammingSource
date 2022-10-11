/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_APERIODICSPECTRUMMATCHED_IMPL_H
#define INCLUDED_JAMMINGSOURCE_APERIODICSPECTRUMMATCHED_IMPL_H

#include <gnuradio/jammingSource/AperiodicSpectrumMatched.h>
#include <gnuradio/random.h>

namespace gr {
namespace jammingSource {

class AperiodicSpectrumMatched_impl : public AperiodicSpectrumMatched
{
private:
    double d_sampling_freq;
    double d_chip_rate;
    int d_cur_value;
    int d_sample_per_chip;
    int d_cur_sample_count;
    gr::random d_rng;

public:
    AperiodicSpectrumMatched_impl(double samp_rate, double chipRate);
    ~AperiodicSpectrumMatched_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
    
    void set_sampling_freq(double samp_rate) override;

    void set_chip_rate(double chip_rate) override;

    void d_set_sample_per_chip();

    double sampling_freq()const override {return d_sampling_freq;}

    double chip_rate() const override{return d_chip_rate;}
};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_APERIODICSPECTRUMMATCHED_IMPL_H */
