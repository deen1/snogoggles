////////////////////////////////////////////////////////////////////////
/// \class Viewer::Frames::Geodesic3d
///
/// \brief   
///
/// \author Olivia Wasalski <wasalski@triumf.ca>
///			    <oliviawasalski@triumf.ca>
///
/// REVISION HISTORY:\n
/// 	12/07/11 : Olivia Wasalski - First Revision, New File \n
///
/// \details 	
///
////////////////////////////////////////////////////////////////////////

#ifndef __Viewer_Frames_Geodesic3d__
#define __Viewer_Frames_Geodesic3d__

#include <Viewer/XML3d.hh>
#include <string>

namespace Viewer {
namespace Frames {

class Geodesic3d : public XML3d {

public:

    static std::string Name() { return "Geodesic"; }
    std::string GetName() { return Name(); }

    std::string GetFilename() { return "data/geodesic.xml"; }

    void CreateGUIObjects( GUIManager& g, const sf::Rect<double>& optionsArea ) { }
    void LoadConfiguration( ConfigurationTable* configTable ) { }
    void SaveConfiguration( ConfigurationTable* configTable ) { }
    void EventLoop( const GUIReturn& g ) { }
    void RenderGeometry() { RenderWireframe(); }

}; // class Geodesic3d

}; // namespace Frames 
}; // namespace Viewer

#endif // __Viewer_Frames_Geodesic3d__