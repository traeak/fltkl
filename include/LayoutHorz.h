// 
//  -$RCSfile: LayoutHorz.h,v $
//  $Revision: 1.5 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#ifndef fltkl_LayoutHorz_INCL_
#define fltkl_LayoutHorz_INCL_

#include "libfltkl/LayoutLinear.h"

namespace fltkl
{

/*! \brief fltk Horz Layout class.
Simple linear layout with a single resizable.
*/

class LayoutHorz : public LayoutLinear
{

	LayoutHorz(LayoutHorz const & orig);
	LayoutHorz & operator=(LayoutHorz const & rhs);

public:

	//! default null constructor
	LayoutHorz
		();

	//! destroys any sub layouts and all their children
	virtual
	~LayoutHorz
		();

public: // virtual

	/*! \brief initial high/wide of children with given spacing.
	 */
	virtual
	std::pair<int, int>
	initialHighWide
		( int const & spacing
		) const;

	/*! \brief recursively relays out the widgets.
	 * Repositions/resizes children.
	 */
	virtual
	void
	layout
		( fltk::Rectangle const & rect
		, int const & spacing
		, int const & layout_damage
		);

};

}

#endif // ! fltkl_LayoutHorz_INCL_
