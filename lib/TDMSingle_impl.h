/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_TDMSINGLE_IMPL_H
#define INCLUDED_JAMMINGSOURCE_TDMSINGLE_IMPL_H

#include <jammingSource/TDMSingle.h>

namespace gr {
namespace jammingSource {

class TDMSingle_impl : public TDMSingle
{
private:
    // Nothing to declare in this block.

public:
    TDMSingle_impl(double samp_rate, string frequencies, double period);
    ~TDMSingle_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_TDMSINGLE_IMPL_H */
