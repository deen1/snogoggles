////////////////////////////////////////////////////////////////////////
/// \class UIEvent
///
/// \brief   
///
/// \author  Phil Jones <p.jones22@physics.ox.ac.uk>
///
/// REVISION HISTORY:\n
///     29/06/11 : P.Jones - First Revision, new file. \n
///
/// \detail  
///
////////////////////////////////////////////////////////////////////////

#ifndef __Viewer_UIEvent__
#define __Viewer_UIEvent__

#include <SFML/Window/Event.hpp>

#include <Viewer/FrameCoord.hh>

namespace Viewer
{

class UIEvent : public sf::Event
{
public:
  inline UIEvent( sf::Event& event, FrameCoord frameCoord )
    : sf::Event( event ), fFrameCoord( frameCoord )
  { }

  sf::Vector2<double> GetLocalCoord();
private:
  FrameCoord& fFrameCoord;
};

} // ::Viewer

#endif