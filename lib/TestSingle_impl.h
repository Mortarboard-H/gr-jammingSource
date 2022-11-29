/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_TESTSINGLE_IMPL_H
#define INCLUDED_JAMMINGSOURCE_TESTSINGLE_IMPL_H

#include <gnuradio/jammingSource/TestSingle.h>
#include <gnuradio/fxpt_nco.h>

namespace gr {
namespace jammingSource {

class TestSingle_impl : public TestSingle
{
private:
    double d_sampling_frequency;
    double d_start_frequency;
    double d_current_frequency;
    double d_step;
    double d_length;
    double d_interval;
    long long int d_samples_per_length;
    long long int d_samples_per_interval;
    long long int d_count;
    bool d_in_jamming;
    gr::fxpt_nco d_nco;

public:
    TestSingle_impl(
        double samp_rate, double start_freq, double step, double length, double interval);
    ~TestSingle_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
    
    double sampling_freq() const override {return d_sampling_frequency;}

    double current_freq() const override {return d_current_frequency;}

    void set_sampling_freq(double samp_rate) override;

    void set_start_freq(double start_freq) override;

    void set_step(double step) override;

    void set_length(double length) override;

    void set_interval(double interval) override;

    void reset_all();
};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_TESTSINGLE_IMPL_H */
