/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "GainTest_impl.h"
#include <gnuradio/io_signature.h>
#include <gnuradio/math.h>
#include <iostream>

namespace gr {
namespace jammingSource {


using input_type = gr_complex;

using output_type = gr_complex;
GainTest::sptr GainTest::make(double samp_rate,
                              double length_per_gain,
                              double gain_start,
                              double gain_step)
{
    return gnuradio::make_block_sptr<GainTest_impl>(
        samp_rate, length_per_gain, gain_start, gain_step);
}


/*
 * The private constructor
 */
GainTest_impl::GainTest_impl(double samp_rate,
                             double length_per_gain,
                             double gain_start,
                             double gain_step)
    : gr::sync_block("GainTest",
                     gr::io_signature::make(
                         1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
    d_sampling_frequency(samp_rate),
    d_length_per_gain(length_per_gain),
    d_gain_start(gain_start),
    d_gain_step(gain_step)
{
    reset_all();
}

void GainTest_impl::reset_all()
{
    d_current_gain = d_gain_start;
    d_samples_per_gain = d_length_per_gain * d_sampling_frequency;
    d_count = 0;
}

void GainTest_impl::set_sampling_freq(double samp_rate)
{
    d_sampling_frequency = samp_rate;
    reset_all();
}

void GainTest_impl::set_length_per_gain(double length_per_gain)
{
    d_length_per_gain = length_per_gain;
    reset_all();
}

void GainTest_impl::set_gain_start(double gain_start)
{
    d_gain_start = gain_start;
    reset_all();
}

void GainTest_impl::set_gain_step(double gain_step)
{
    d_gain_step = gain_step;
    reset_all();
}
/*
 * Our virtual destructor.
 */
GainTest_impl::~GainTest_impl() {}

int GainTest_impl::work(int noutput_items,
                        gr_vector_const_void_star& input_items,
                        gr_vector_void_star& output_items)
{
    auto in = static_cast<const input_type*>(input_items[0]);
    auto out = static_cast<output_type*>(output_items[0]);

    float mul_const = sqrt(pow(10, d_current_gain / 10));

    for(int i = 0; i < noutput_items; i++)
    {
        *out = mul_const * (*in);
        out++;
        in++;
        if(d_length_per_gain != 0) // not const gain mode
        {
            d_count++;
            if (d_count == d_samples_per_gain)
            {
                d_count = 0;
                d_current_gain += d_gain_step;
                mul_const = sqrt(pow(10, d_current_gain / 10));
            }
        }
    }
    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace jammingSource */
} /* namespace gr */
