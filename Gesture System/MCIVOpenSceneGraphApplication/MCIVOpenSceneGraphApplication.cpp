// MCIVOpenSceneGraphApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain( int argc, _TCHAR* argv[] )
{
	return 0;
}

// raaRobotController.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgUtil/Optimizer>
#include <osgViewer/Viewer>
#include <osg/MatrixTransform>
#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/GUIEventHandler>
#include <osgUtil/UpdateVisitor>
#include <osgViewer/ViewerEventHandlers>
#include <osg/MatrixTransform>

osg::Node *g_pModel=0;

// sample of a node visitor class to print out the library name, the node name and the object name
class nodePrinter : public osg::NodeVisitor
{
public:
	nodePrinter() : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN) {};

	virtual void apply(osg::Node &node)
	{
		std::string name("a");
		std::string base = node.className();
		name.assign(base);

		if (name == "MatrixTransform")
		{
			std::cout <<"	   " << " Library -> " << node.libraryName() << " Node -> " << name   << " Object -> " << node.getName().c_str() <<  std::endl;	
		}

		else 
		{
			std::cout << " Library -> " << node.libraryName() << " Node -> " << name   << " Object -> " << node.getName().c_str()  << std::endl;
		}

		traverse(node);
	}

protected:
};
/*
// find a node according to its name
class nodeFinder : public osg::NodeVisitor
{
public:
	nodeFinder(std::string sName) : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN) 
	{

		m_sName=sName;
		m_pMT =0;

	}

	virtual void apply(osg::Node &node)
	{
		traverse(node);

	}

	virtual void apply(osg::MatrixTransform &mt)
	{
		if(mt.getName() == m_sName)
		{
			m_pMT=&mt;
		}
		apply((osg::Node&)mt);


	}

	osg::MatrixTransform *getNode()
	{	
		return m_pMT;
	};


protected:
	std::string m_sName;
	osg::MatrixTransform*m_pMT;
};
*/
// function to run before rendering starts -> use this to identify nodes and update
void init()
{
	if(g_pModel)
	{
		std::cout << "Loaded Model" << std::endl;
		nodePrinter printer;
		printer.traverse(*g_pModel);	
	}
}

int main(int argc, char** argv)
{
	osg::ArgumentParser arguments(&argc,argv);

	// load model
	g_pModel = osgDB::readNodeFiles(arguments);

	if(!g_pModel) {return 0;}
	g_pModel->ref();

	init();

	// setup viewer
	osgViewer::Viewer viewer;

	osg::GraphicsContext::Traits *pTraits = new osg::GraphicsContext::Traits();
	pTraits->x = 20;
	pTraits->y = 20;
	pTraits->width = 600;
	pTraits->height = 480;
	pTraits->windowDecoration = true;
	pTraits->doubleBuffer = true;
	pTraits->sharedContext = 0;

	osg::GraphicsContext *pGC = osg::GraphicsContext::createGraphicsContext(pTraits);
	osgGA::KeySwitchMatrixManipulator* pKeyswitchManipulator = new osgGA::KeySwitchMatrixManipulator();
	pKeyswitchManipulator->addMatrixManipulator( '1', "Trackball", new osgGA::TrackballManipulator() );
	pKeyswitchManipulator->addMatrixManipulator( '2', "Flight", new osgGA::FlightManipulator() );
	pKeyswitchManipulator->addMatrixManipulator( '3', "Drive", new osgGA::DriveManipulator() );
	viewer.setCameraManipulator(pKeyswitchManipulator);
	osg::Camera *pCamera = viewer.getCamera();
	pCamera->setGraphicsContext(pGC);
	pCamera->setViewport(new osg::Viewport(0,0, pTraits->width, pTraits->height));


	// add the state manipulator
	viewer.addEventHandler(new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()));

	// add the thread model handler
	viewer.addEventHandler(new osgViewer::ThreadingHandler);

	// add the window size toggle handler
	viewer.addEventHandler(new osgViewer::WindowSizeHandler);

	// add the stats handler
	viewer.addEventHandler(new osgViewer::StatsHandler);

	// add the record camera path handler
	viewer.addEventHandler(new osgViewer::RecordCameraPathHandler);

	// add the LOD Scale handler
	viewer.addEventHandler(new osgViewer::LODScaleHandler);

	// add the screen capture handler
	viewer.addEventHandler(new osgViewer::ScreenCaptureHandler);

	// set the scene to render
	viewer.setSceneData(g_pModel);

	viewer.realize();

	return viewer.run();

	return 0;
}

