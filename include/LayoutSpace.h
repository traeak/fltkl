// 
//  -$RCSfile: LayoutSpace.h,v $
//  $Revision: 1.5 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#ifndef fltkl_LayoutSpace_INCL_
#define fltkl_LayoutSpace_INCL_

#include "libfltkl/Layout.h"

namespace fltkl
{

class LayoutSpace : public Layout
{

private: // disable

	LayoutSpace(LayoutSpace const & orig);
	LayoutSpace & operator=(LayoutSpace const & rhs);

public: // methods

	//! construct with no space
	LayoutSpace
		();

	//! construct with initial space (use fltk wide, high convention)
	explicit
	LayoutSpace
		( int const & wide
		, int const & high
		);

	//! empty virtual destructor -- group is to manage the child memory
	virtual
	~LayoutSpace
		();

	/*! \brief Inventory of widget in Group.
	 */
	virtual
	void
	widgets
		( std::vector<fltk::Widget*> * const widgets
		) const;

	/*! \brief Current bounding box of children.
	 */
	virtual
	std::pair<int, int>
	initialHighWide
		( int const & // spacing
		) const;

	//! lays out given child and adds to list
	virtual
	void
	layout
		( fltk::Rectangle const &
		, int const & // spacing
		, int const & // layout_damage
		);

private: // data

	std::pair<int, int> const theInitHighWide; //!< current high/wide
	std::pair<int, int> theHighWide; //!< current high/wide

};

}

#endif // ! fltkl_LayoutSpace_INCL_
