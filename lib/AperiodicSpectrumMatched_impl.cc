/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "AperiodicSpectrumMatched_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace jammingSource {

#pragma message("set the following appropriately and remove this warning")
using output_type = int;
AperiodicSpectrumMatched::sptr AperiodicSpectrumMatched::make(double samp_rate,
                                                              double chipRate)
{
    return gnuradio::make_block_sptr<AperiodicSpectrumMatched_impl>(samp_rate, chipRate);
}


/*
 * The private constructor
 */
AperiodicSpectrumMatched_impl::AperiodicSpectrumMatched_impl(double samp_rate,
                                                             double chipRate)
    : gr::sync_block("AperiodicSpectrumMatched",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
    d_sampling_freq(samp_rate),
    d_chip_rate(chipRate),
    d_rng(0, 0, 2)
{
    d_cur_value=1;
    this->d_set_sample_per_chip();
    d_rng.set_integer_limits(0,2);
    d_rng.reseed(1);
}

/*
 * Our virtual destructor.
 */
AperiodicSpectrumMatched_impl::~AperiodicSpectrumMatched_impl() {}

int AperiodicSpectrumMatched_impl::work(int noutput_items,
                                        gr_vector_const_void_star& input_items,
                                        gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);

    int count = 0;

    while(count < noutput_items)
    {
        while(d_cur_sample_count < d_sample_per_chip)
        {
            *out++ = d_cur_value;
            d_cur_sample_count++;
            count++;
        }
        int temp = d_rng.ran_int();
        if(temp == 0) d_cur_value = -1;
        else d_cur_value = 1;

        d_cur_sample_count = 0;
    }


    // Tell runtime system how many output items we produced.
    return noutput_items;
}

void AperiodicSpectrumMatched_impl::set_sampling_freq(double samp_rate)
{
    this->d_sampling_freq = samp_rate;
    this->d_set_sample_per_chip();
}

void AperiodicSpectrumMatched_impl::set_chip_rate(double chip_rate)
{
    this->d_chip_rate = chip_rate;
    this->d_set_sample_per_chip();
}

void AperiodicSpectrumMatched_impl::d_set_sample_per_chip()
{
    double sample_per_chip = d_sampling_freq / d_chip_rate;
    d_sample_per_chip = (int) round(sample_per_chip);
}

} /* namespace jammingSource */
} /* namespace gr */
