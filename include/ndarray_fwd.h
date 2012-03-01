// -*- c++ -*-
/*
 * Copyright 2012, Jim Bosch and the LSST Corporation
 * 
 * ndarray is available under two licenses, both of which are described
 * more fully in other files that should be distributed along with
 * the code:
 * 
 *  - A simple BSD-style license (ndarray-bsd-license.txt); under this
 *    license ndarray is broadly compatible with essentially any other
 *    code.
 * 
 *  - As a part of the LSST data management software system, ndarray is
 *    licensed with under the GPL v3 (LsstLicenseStatement.txt).
 * 
 * These files can also be found in the source distribution at:
 * 
 * https://github.com/ndarray/ndarray
 */
#ifndef NDARRAY_ndarray_fwd_h_INCLUDED
#define NDARRAY_ndarray_fwd_h_INCLUDED

/**
 * @file ndarray_fwd.h 
 *
 * @brief Forward declarations and default template parameters for ndarray.
 */

/// \defgroup ndarrayMainGroup Main

/// \defgroup ndarrayOpGroup Operators

/// \defgroup ndarrayVectorGroup Vectors

/// @internal \defgroup ndarrayInternalGroup Internals

#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <cassert>

#ifdef __GNUC__
#if __GNUC__ == 4 && __GNUC_MINOR__ == 5
#define GCC_45
#endif
#endif

#define NDARRAY_ASSERT(ARG) assert(ARG)

namespace ndarray {

template <typename T, int N, int C> struct ArrayTraits;
template <typename Expression_> struct ExpressionTraits;
class Manager;

/// @brief An enumeration for stride computation.
enum DataOrderEnum { ROW_MAJOR=1, COLUMN_MAJOR=2 };

namespace detail {

template <int N> class Core;

class CountingExpression;

template <
    typename Operand,
    typename UnaryFunction,
    int N = ExpressionTraits<Operand>::ND::value
    >
class UnaryOpExpression;

template <
    typename Operand1,
    typename Operand2,
    typename BinaryFunction,
    int N = ExpressionTraits<Operand1>::ND::value
    >
class BinaryOpExpression;

template <typename Iterator_> struct IteratorTraits;

template <typename T, int N, int C> class NestedIterator;

template <typename T> class StridedIterator;

#ifndef GCC_45

template <
    typename Operand, 
    typename UnaryFunction
    >
class UnaryOpIterator;

template <
    typename Operand1,
    typename Operand2,
    typename BinaryFunction
    >
class BinaryOpIterator;

#endif

} // namespace detail

template <typename Derived> class ExpressionBase;
template <typename Derived> class ArrayBase;
template <typename T, int N, int C=0> class ArrayRef;
template <typename T, int N, int C=0> class Array;
template <typename T, int N> struct Vector;

} // namespace ndarray

#endif // !NDARRAY_ndarray_fwd_h_INCLUDED