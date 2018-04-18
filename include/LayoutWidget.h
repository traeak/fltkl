// 
//  -$RCSfile: LayoutWidget.h,v $
//  $Revision: 1.4 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#ifndef fltkl_LayoutWidget_INCL_
#define fltkl_LayoutWidget_INCL_

#include "libfltkl/Layout.h"

namespace fltkl
{

class LayoutWidget : public Layout
{

private: // disable

	LayoutWidget(LayoutWidget const & orig);
	LayoutWidget & operator=(LayoutWidget const & rhs);

public: // methods

	//! value constructor
	LayoutWidget
		( fltk::Widget * const widget
		);

	//! empty virtual destructor -- group is to manage the child memory
	virtual
	~LayoutWidget
		();

public: // virtual

	/*! \brief Inventory of widget in Group.
	 */
	virtual
	void
	widgets
		( std::vector<fltk::Widget*> * const widgets
		) const;

	/*! \brief initial high/wide of widget
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
		( fltk::Rectangle const & rect
		, int const & spacing
		, int const & layout_damage
		);

private: // data

	fltk::Widget * theWidget; //!< wholly contained widget
	std::pair<int, int> theInitHighWide; //!< initial high/wide of widget

};

}

#endif // ! fltkl_LayoutWidget_INCL_
