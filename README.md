This library provides a method for widget layout without requiring
explicit pixel geometry to be specified and should be a good
alternative to using fluid for creating nice interfaces without
the clutter of automatically generated code.

This is influenced from years of working with Qt.  Unlike Qt's
layout this is much lighter weight and should work for most
general interfaces.

Using these layouts:

- Create widgets, configure their contents, optionally call
  "fltkl::presize" on each one.
- Create any leading/trailing labels.
- Create main layout, add layout(s) and widget(s) to them (nested also works).
- Create GroupLayout, set the main layout.
- Set border and internal spacing for GroupLayout.

Classes include:

- fltkl::GroupLayout: derives from fltk::Group
- fltkl::LayoutLinear: base class for linear layouts
- fltkl::LayoutVert: vertical layout
- fltkl::LayoutHorz: horizontal layout
- fltkl::LayoutSpace: resizable/fixed space
- fltkl::LayoutAdder: allows for very compact layout code
- fltkl::LayoutWidget: widget wrapper, mostly hidden

Utilities:

- fltkl: defines constant values for typical spacing
- presize: sizes a widget based on content
- widgets: make presized labels and attach to (check)buttons

How this works:

- Calling presize on all the widgets gives them an initial size.
- Adding the Widgets to layouts results in the wrapping LayoutWidget
  recording the widget's initial size.
- Layout classes recursively can compute a minimum size and can
  also recursively direct the widgets for size and placement.

Limitations:

- Only decoupled linear layouts are implemented.  Leading
  labels can be handled by using to "presizeToMaxWide"
  on a vector of labels to line up.  These labels then should
  NOT be set resizable.
- Layouts are designed to be static once created.  They should not be
  changed on the fly (I haven't tested the effects of this yet).
  Consider using fltkl::Stack to swap out various configurations.

Why should I use this?

- Allows you to build Groups without hard coding geometries.
- Allows UI contents to be shuffled around by only changing
  the way the layouts are built (sans gui builder).
- Begin/End calls not required.  GroupLayout::setLayout recursively
  calls add() on each containing widget.
- A single GroupLayout can typically be used for a whole multi widget
  window.

Other features:

- Recursed fltk::Groups are replaced by recursed Layout classes.
