#include <cstddef> //NULL and other things

#include <Viewer/GUIDefaultPalette.hh>
using namespace Viewer;

GUIColourPalette* GUIColourPalette::gPalette = NULL;

Colour 
GUIDefaultPalette::GetBaseColour( EGUIImageState state )
{
  switch( state )
    {
    case eBase:
      return Colour( 96, 75, 216, 255 );
      break;
    case eHighlight:
      return Colour( 128, 112, 216, 255 );
      break;
    case eActive:
      return Colour( 96, 75, 216, 255 );
      break;
    }
}

Colour 
GUIDefaultPalette::GetBGColour( EGUIImageState state )
{
  return Colour( 255, 255, 255, 255 );
}

Colour 
GUIDefaultPalette::GetItemColour( EGUIImageState state )
{
  switch( state )
    {
    case eBase:
      return Colour( 255, 255, 255, 255 );
      break;
    case eHighlight:
      return Colour( 158, 0, 22, 255 );
      break;
    case eActive:
      return Colour( 255, 227, 115, 255 );
      break;
    }  
}

Colour 
GUIDefaultPalette::GetTextColour( EGUIImageState state )
{
  return Colour( 0, 0, 0, 255 );
}
