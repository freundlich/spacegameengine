/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2007  Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_CONTAINER_TREE_IMPL_HPP_INCLUDED
#define SGE_CONTAINER_TREE_IMPL_HPP_INCLUDED

#include "tree_decl.hpp"
#include "ptr_equal.hpp"
#include <algorithm>

template<
	typename T
>
sge::container::tree<T>::tree()
:
	value_(),
	parent_(0)
{}

template<
	typename T
>
sge::container::tree<T>::tree(
	init_tree<T> const &)
:
	value_(),
	parent_(0)
{}

template<
	typename T
>
sge::container::tree<T>::tree(
	T const &value_)
:
	value_(value_),
	parent_(0)
{}

template<
	typename T
>
sge::container::tree<T>::~tree()
{
	clear();
}

template<
	typename T
>
typename sge::container::tree<T>::child_list &
sge::container::tree<T>::children()
{
	return children_;
}

template<
	typename T
>
typename sge::container::tree<T>::child_list const &
sge::container::tree<T>::children() const
{
	return children_;
}

template<
	typename T
>
sge::container::tree<T> &
sge::container::tree<T>::parent()
{
	return *parent_;
}

template<
	typename T
>
sge::container::tree<T> const &
sge::container::tree<T>::parent() const
{
	return *parent_;
}

template<
	typename T
>
bool
sge::container::tree<T>::has_parent() const
{
	return parent_;
}

template<
	typename T
>
void
sge::container::tree<T>::parent(
	tree &t)
{
	parent_ = &t;
}

template<
	typename T
>
void
sge::container::tree<T>::orphan()
{
	if(!has_parent())
		return;
	parent->release(
		*this);
	parent_ = 0;
}

template<
	typename T
>
typename sge::container::tree<T>::auto_ptr
sge::container::tree<T>::release(
	iterator const it)
{
	return children.release(
		it);
}

template<
	typename T
>
typename sge::container::tree<T>::iterator
sge::container::tree<T>::child_position()
{
	return std::find_if(
		parent().begin(),
		parent().end(),
		make_ptr_equal(
			this));
}

template<
	typename T
>
void
sge::container::tree<T>::value(
	T const &v)
{
	value_ = v;
}

template<
	typename T
>
T &
sge::container::tree<T>::value()
{
	return value_;
}

template<
	typename T
>
T const &
sge::container::tree<T>::value() const
{
	return value_;
}

template<
	typename T
>
void
sge::container::tree<T>::push_back(
	auto_ptr r)
{
	/*
	insert(
		end(),
		r);*/
	children().push_back(
		r);
	
	children().back().parent(
		*this);
}

template<
	typename T
>
void
sge::container::tree<T>::pop_back()
{
	children().pop_back();
}

template<
	typename T
>
void
sge::container::tree<T>::push_front(
	auto_ptr r)
{
	insert(
		begin(),
		r);
}

template<
	typename T
>
void
sge::container::tree<T>::pop_front()
{
	children().pop_front();
}

template<
	typename T
>
void
sge::container::tree<T>::clear()
{
	erase(
		begin(),
		end()
	);
}

template<
	typename T
>
typename sge::container::tree<T>::reference
sge::container::tree<T>::back()
{
	return children().back();
}

template<
	typename T
>
typename sge::container::tree<T>::const_reference
sge::container::tree<T>::back() const
{
	return children().back();
}

template<
	typename T
>
typename sge::container::tree<T>::reference
sge::container::tree<T>::front()
{
	return children().front();
}
template<
	typename T
>
typename sge::container::tree<T>::const_reference
sge::container::tree<T>::front() const
{
	return children.front();
}

template<
	typename T
>
typename sge::container::tree<T>::iterator
sge::container::tree<T>::begin()
{
	return children().begin();
}

template<
	typename T
>
typename sge::container::tree<T>::iterator
sge::container::tree<T>::end()
{
	return children().end();
}

template<
	typename T
>
typename sge::container::tree<T>::const_iterator
sge::container::tree<T>::begin() const
{
	return children().begin();
}

template<
	typename T
>
typename sge::container::tree<T>::const_iterator
sge::container::tree<T>::end() const
{
	return children().end();
}

template<
	typename T
>
typename sge::container::tree<T>::reverse_iterator
sge::container::tree<T>::rbegin()
{
	return children().rbegin();
}

template<
	typename T
>
typename sge::container::tree<T>::reverse_iterator
sge::container::tree<T>::rend()
{
	return children.rend();
}

template<
	typename T
>
typename sge::container::tree<T>::const_reverse_iterator
sge::container::tree<T>::rbegin() const
{
	return children().rbegin();
}

template<
	typename T
>
typename sge::container::tree<T>::const_reverse_iterator
sge::container::tree<T>::rend() const
{
	return children().rend();
}

template<
	typename T
>
void
sge::container::tree<T>::insert(
	iterator const it,
	auto_ptr r)
{
	children().insert(
		it,
		r);
	r->parent(
		*this);
}

template<
	typename T
>
void
sge::container::tree<T>::erase(
	iterator const it)
{
	children().erase(
		it);
}

template<
	typename T
>
void
sge::container::tree<T>::erase(
	iterator const beg,
	iterator const end)
{
	children().erase(
		beg,
		end);
}

template<
	typename T
>
typename sge::container::tree<T>::size_type
sge::container::tree<T>::size() const
{
	return children().size();
}

template<
	typename T
>
typename sge::container::tree<T>::size_type
sge::container::tree<T>::max_size() const
{
	return children().max_size();
}

template<
	typename T
>
bool
sge::container::tree<T>::empty() const
{
	return children().empty();
}

#endif
