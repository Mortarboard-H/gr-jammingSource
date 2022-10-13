/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "Chirp_impl.h"
#include <gnuradio/io_signature.h>
#include <gnuradio/math.h>

namespace gr {
namespace jammingSource {

#pragma message("set the following appropriately and remove this warning")
using output_type = gr_complex;
Chirp::sptr Chirp::make(double samp_rate, double min_freq, double max_freq, double period)
{
    return gnuradio::make_block_sptr<Chirp_impl>(samp_rate, min_freq, max_freq, period);
}


/*
 * The private constructor
 */
Chirp_impl::Chirp_impl(double samp_rate, double min_freq, double max_freq, double period)
    : gr::sync_block("Chirp",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
    d_sampling_frequency(samp_rate),
    d_min_frequency(min_freq),
    d_max_frequency(max_freq),
    d_period(period)
{
    this->reset_all();
}

/*
 * Our virtual destructor.
 */
Chirp_impl::~Chirp_impl() {}

int Chirp_impl::work(int noutput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);
    float sin_num,cos_num;

    for(int i = 0; i < noutput_items ; i++)
    {
        d_nco.sincos(&cos_num,&sin_num);
        *out++= gr_complex(sin_num,cos_num);
        d_nco.adjust_freq(2 * GR_M_PI * d_freq_inc_per_sample / d_sampling_frequency);
        d_nco.step();
        
        auto curfreq = d_nco.get_freq();
        if(curfreq > 2 * GR_M_PI * d_max_frequency / d_sampling_frequency)
            d_nco.set_freq(2 * GR_M_PI * d_min_frequency / d_sampling_frequency);
    }

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

void Chirp_impl::set_sampling_freq(double samp_rate)
{
    this->d_sampling_frequency = samp_rate;
    this->reset_all();
}

void Chirp_impl::set_period(double period)
{
    this->d_period = period;
    this->reset_all();
}

void Chirp_impl::set_min_freq(double min_freq)
{
    this->d_min_frequency = min_freq;
    this->reset_all();
}

void Chirp_impl::set_max_freq(double max_freq)
{
    this->d_max_frequency = max_freq;
    this->reset_all();
}

void Chirp_impl::reset_all()
{
    // set d_samples per loop
    double samples_per_loop = d_period * d_sampling_frequency;
    d_samples_per_loop = (int) samples_per_loop;

    // set frequency increments per sample
    d_freq_inc_per_sample = (d_max_frequency - d_min_frequency) / (double)d_samples_per_loop;

    d_count = 0;

    d_nco.set_freq(2 * GR_M_PI * d_min_frequency / d_sampling_frequency);
}

} /* namespace jammingSource */
} /* namespace gr */
