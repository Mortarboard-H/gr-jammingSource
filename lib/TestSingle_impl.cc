/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "TestSingle_impl.h"
#include <gnuradio/io_signature.h>
#include <gnuradio/math.h>
#include <iostream>

namespace gr {
namespace jammingSource {


using output_type = gr_complex;
TestSingle::sptr TestSingle::make(
    double samp_rate, double start_freq, double step, double length, double interval)
{
    return gnuradio::make_block_sptr<TestSingle_impl>(
        samp_rate, start_freq, step, length, interval);
}


/*
 * The private constructor
 */
TestSingle_impl::TestSingle_impl(
    double samp_rate, double start_freq, double step, double length, double interval)
    : gr::sync_block("TestSingle",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
    d_sampling_frequency(samp_rate),
    d_start_frequency(start_freq),
    d_step(step),
    d_length(length),
    d_interval(interval)
{
    this->reset_all();
}

/*
 * set other members due to changes of parameters
*/
void TestSingle_impl::reset_all()
{
    d_in_jamming = true;
    d_current_frequency = d_start_frequency;
    d_samples_per_length = d_sampling_frequency * d_length;
    d_samples_per_interval = d_sampling_frequency * d_interval;
    d_nco.set_freq(2 * GR_M_PI * d_current_frequency / d_sampling_frequency);
    d_count = 0;
}


/*
 * Our virtual destructor.
 */
TestSingle_impl::~TestSingle_impl() {}

int TestSingle_impl::work(int noutput_items,
                          gr_vector_const_void_star& input_items,
                          gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);
    float cos_num, sin_num;

    for(int i = 0; i < noutput_items; i++)
    {
        if(d_in_jamming)
        {
            d_nco.sincos(&sin_num, &cos_num);
            *out++= gr_complex(cos_num,sin_num);
            d_nco.step();
            //d_current_frequency =  d_nco.get_freq() * d_sampling_frequency / 2 * GR_M_PI;

            d_count++;
            if(d_count > d_samples_per_length)
            {
                d_in_jamming = false;
                d_current_frequency += d_step;
                std::cout<<"current frequency:"<<d_current_frequency<<std::endl;
                d_nco.set_freq(2 * GR_M_PI * d_current_frequency / d_sampling_frequency);
                d_count = 0;
            }
        }
        else
        {
            *out++= gr_complex(0,0);

            d_count++;
            if(d_count > d_samples_per_interval)
            {
                d_in_jamming = true;
                d_count = 0;
            }
        }
    }


    // Tell runtime system how many output items we produced.
    return noutput_items;
}

void TestSingle_impl::set_sampling_freq(double samp_rate)
{
    d_sampling_frequency = samp_rate;
    this->reset_all();
}

void TestSingle_impl::set_start_freq(double start_freq)
{
    d_start_frequency = start_freq;
    this->reset_all();
}

void TestSingle_impl::set_step(double step)
{
    d_step = step;
    this->reset_all();
}

void TestSingle_impl::set_length(double length)
{
    d_length = length;
    this->reset_all();
}

void TestSingle_impl::set_interval(double interval)
{
    d_interval = interval;
    this->reset_all();
}

} /* namespace jammingSource */
} /* namespace gr */
