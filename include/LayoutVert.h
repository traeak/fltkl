// 
//  -$RCSfile: LayoutVert.h,v $
//  $Revision: 1.5 $
//  Rev-$Name: not supported by cvs2svn $
//  Mod-$Date: 2011-03-12 04:51:38 $
// 
//  Copyright (c) 2009 Stellacore Corporation. All Rights Reserved.
//
// #HEADER_NOTICE#
//

#ifndef fltkl_LayoutVert_INCL_
#define fltkl_LayoutVert_INCL_

#include "libfltkl/LayoutLinear.h"

namespace fltkl
{

/*! \brief fltk Vert Layout class.
Simple linear layout with a single resizable.
*/

class LayoutVert : public LayoutLinear
{

	LayoutVert(LayoutVert const & orig);
	LayoutVert & operator=(LayoutVert const & rhs);

public:

	//! default null constructor
	LayoutVert
		();

	//! destroys any sub layouts and all their children
	virtual
	~LayoutVert
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

#endif // ! fltkl_LayoutVert_INCL_
