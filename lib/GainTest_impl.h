/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_GAINTEST_IMPL_H
#define INCLUDED_JAMMINGSOURCE_GAINTEST_IMPL_H

#include <gnuradio/jammingSource/GainTest.h>

namespace gr {
namespace jammingSource {

class GainTest_impl : public GainTest
{
private:
    double d_sampling_frequency;
    double d_length_per_gain;
    double d_gain_start;
    double d_gain_step;
    double d_current_gain;
    long long int d_samples_per_gain;
    long long int d_count;

public:
    GainTest_impl(double samp_rate,
                  double length_per_gain,
                  double gain_start,
                  double gain_step);
    ~GainTest_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
    
    double sampling_freq() const override {return d_sampling_frequency;};

    double current_gain() const override {return d_current_gain;};

    /*!
     * Sets the sampling frequency of the signal.
     * \param sampling_freq sampling frequency
     */
    void set_sampling_freq(double sampling_freq) override;

    /*!
     * Sets the length of every gain.
     * \param length_per_gain length of every gain
     */
    void set_length_per_gain(double length_per_gain) override;

    /*!
     * Sets start gain .
     * \param gain_start start gain.
     */
    void set_gain_start(double gain_start) override;

    /*!
     * Sets the step of gain.
     * \param gain_step step of gain
     */
    void set_gain_step(double gain_step) override;

    /*!
     * Sets all the members affected by parameters.
     */
    void reset_all();

};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_GAINTEST_IMPL_H */
