#include <vector>
#include <string>
#include <iostream>

#include <RAT/DS/Run.hh>

#include <Viewer/Module3d.hh>
#include <Viewer/CameraManager3d.hh>
#include <Viewer/HitManager3d.hh>
#include <Viewer/TrackManager3d.hh>
#include <Viewer/GeoManager3d.hh>
#include <Viewer/FitterManager3d.hh>
#include <Viewer/Axes3d.hh>
#include <Viewer/DataStore.hh>
#include <Viewer/Rect.hh>
#include <Viewer/RIDS/EV.hh>
#include <Viewer/RIDS/MC.hh>
#include <Viewer/ModuleManager3d.hh>

namespace RAT {
    namespace DS {
        class PMTProperties;
    }; // namespace DS
}; // namespace RAT

namespace Viewer {
namespace Frames {

ModuleManager3d::ModuleManager3d()
{
	SetAllModules( NULL, NULL, NULL, NULL, NULL );
}

ModuleManager3d::~ModuleManager3d()
{
	DeleteAllModules();
}

void ModuleManager3d::SetAllModules( 
    CameraManager3d* camera, 
    HitManager3d* hits, 
    TrackManager3d* tracks,
    GeoManager3d* geo,
    FitterManager3d* fitter
)
{
	fCameraManager = camera;
	fHitManager = hits;
	fTrackManager = tracks;
	fGeoManager = geo;
	fFitterManager = fitter;
	if( fCameraManager != NULL )
		fAxes = new Axes3d( fCameraManager->SuggestedAxisLength() );
}

void ModuleManager3d::DeleteAllModules()
{
	delete fCameraManager;		fCameraManager = NULL;
	delete fHitManager;			fHitManager = NULL;
	delete fTrackManager;		fTrackManager = NULL;
	delete fGeoManager;			fGeoManager = NULL;
	delete fFitterManager;		fFitterManager = NULL;
	delete fAxes;				fAxes = NULL;
}

void ModuleManager3d::LateInitialise()
{
	if( fCameraManager == NULL )
		throw NoCameraError();

	GeoManager3d::LoadFileSafe( fGeoManager );
}

void ModuleManager3d::LoadModuleConfigurations( const ConfigurationTable* configTable )
{
	Module3d::LoadConfigurationSafe( fCameraManager, configTable );
	Module3d::LoadConfigurationSafe( fHitManager, configTable );
	Module3d::LoadConfigurationSafe( fTrackManager, configTable );
	Module3d::LoadConfigurationSafe( fGeoManager, configTable );
	Module3d::LoadConfigurationSafe( fFitterManager, configTable );
	Module3d::LoadConfigurationSafe( fAxes, configTable );
}

void ModuleManager3d::SaveModuleConfigurations( ConfigurationTable* configTable )
{
	Module3d::SaveConfigurationSafe( fCameraManager, configTable );
	Module3d::SaveConfigurationSafe( fHitManager, configTable );
	Module3d::SaveConfigurationSafe( fTrackManager, configTable );
	Module3d::SaveConfigurationSafe( fGeoManager, configTable );
	Module3d::SaveConfigurationSafe( fFitterManager, configTable );
	Module3d::SaveConfigurationSafe( fAxes, configTable );
}

void ModuleManager3d::EventLoop()
{
	Module3d::EventLoopSafe( fCameraManager );
	Module3d::EventLoopSafe( fHitManager );
	Module3d::EventLoopSafe( fTrackManager );
	Module3d::EventLoopSafe( fGeoManager );
	Module3d::EventLoopSafe( fFitterManager );
	Module3d::EventLoopSafe( fAxes );
}

void ModuleManager3d::Render2d( RWWrapper& windowApp, const RenderState& renderState )
{

}

void ModuleManager3d::Render3d( RectPtr viewport, const RenderState& renderState )
{
  RIDS::EV& ev = DataStore::GetInstance().GetCurrentEvent().GetEV();
  RIDS::MC& mc = DataStore::GetInstance().GetCurrentEvent().GetMC();
  RAT::DS::PMTProperties* pmtList = DataStore::GetInstance().GetRun().GetPMTProp();
  
  fCameraManager->SetUpCameraSystem( viewport->GetRect( Rect::eGL ) ); 
  HitManager3d::RenderHitsSafe( fHitManager, &ev, pmtList, renderState );
  TrackManager3d::RenderTracksSafe( fTrackManager, mc );
  GeoManager3d::RenderGeometrySafe( fGeoManager );
  FitterManager3d::RenderFitVertexSafe( fFitterManager );
  Axes3d::RenderAxesSafe( fAxes );
}

}; // namespace Frames
}; // namespace Viewer
