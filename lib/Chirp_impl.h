/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_CHIRP_IMPL_H
#define INCLUDED_JAMMINGSOURCE_CHIRP_IMPL_H

#include <gnuradio/jammingSource/Chirp.h>
#include <gnuradio/fxpt_nco.h>

namespace gr {
namespace jammingSource {

class Chirp_impl : public Chirp
{
private:
    double d_sampling_frequency;
    double d_period;
    double d_max_frequency;
    double d_min_frequency;
    long long int d_samples_per_loop;
    long long int d_count;
    double d_freq_inc_per_sample;
    gr::fxpt_nco d_nco;
public:
    Chirp_impl(double samp_rate, double min_freq, double max_freq, double period);
    ~Chirp_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);

    double sampling_freq() const override {return d_sampling_frequency;}

    double period() const override {return d_period;}

    void set_sampling_freq(double samp_rate) override;

    void set_period(double period) override;

    void set_max_freq(double max_freq) override;

    void set_min_freq(double min_freq) override;

    void reset_all();

};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_CHIRP_IMPL_H */
