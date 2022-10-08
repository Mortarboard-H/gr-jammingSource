/* -*- c++ -*- */
/*
 * Copyright 2022 mortarboard-H.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_JAMMINGSOURCE_TDMSINGLE_H
#define INCLUDED_JAMMINGSOURCE_TDMSINGLE_H

#include <gnuradio/sync_block.h>
#include <jammingSource/api.h>

namespace gr {
namespace jammingSource {

/*!
 * \brief <+description of block+>
 * \ingroup jammingSource
 *
 */
class JAMMINGSOURCE_API TDMSingle : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<TDMSingle> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of jammingSource::TDMSingle.
     *
     * To avoid accidental use of raw pointers, jammingSource::TDMSingle's
     * constructor is in a private implementation
     * class. jammingSource::TDMSingle::make is the public interface for
     * creating new instances.
     */
    static sptr make(double samp_rate, string frequencies, double period);
};

} // namespace jammingSource
} // namespace gr

#endif /* INCLUDED_JAMMINGSOURCE_TDMSINGLE_H */
