/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "TDMSingle_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace jammingSource {

#pragma message("set the following appropriately and remove this warning")
using output_type = float;
TDMSingle::sptr TDMSingle::make(double samp_rate, string frequencies, double period)
{
    return gnuradio::make_block_sptr<TDMSingle_impl>(samp_rate, frequencies, period);
}


/*
 * The private constructor
 */
TDMSingle_impl::TDMSingle_impl(double samp_rate, string frequencies, double period)
    : gr::sync_block("TDMSingle",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
{
}

/*
 * Our virtual destructor.
 */
TDMSingle_impl::~TDMSingle_impl() {}

int TDMSingle_impl::work(int noutput_items,
                         gr_vector_const_void_star& input_items,
                         gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);

#pragma message("Implement the signal processing in your block and remove this warning")
    // Do <+signal processing+>

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace jammingSource */
} /* namespace gr */
