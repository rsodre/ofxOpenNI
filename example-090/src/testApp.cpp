#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
	
	//
	// Current working directory must be: bin
	// Or it will not find NiTE.ini !!!
	// Don't know why but when running outside XCode, it is always set to "/"
	// So we change it back here...
	//
	// Try to restore automatically
	ofRestoreWorkingDirectoryToDefault();
	// Get current working directory
	char cwd[1024] = { '\0' };
	std::string pwd( getcwd(cwd, sizeof(cwd)) == NULL ? "" : cwd );
	if ( pwd.compare("/") == 0 )
	{
		ofLogError() << "=== getcwd [" << pwd << "] (need to change!)";
		//ofRestoreWorkingDirectoryToDefault();		// not working
		std::string exeDir( ofFilePath::getCurrentExeDir() );
		std::string newpwd( exeDir + "../../../" );
		//ofLogError() << "=== newpwd [" << newpwd << "]";
		
		// set and read again
		chdir( newpwd.c_str() );
		pwd = std::string( getcwd(cwd, sizeof(cwd)) == NULL ? "" : cwd );
		ofLogError() << "=== newpwd [" << pwd << "]";
	}

    device.setup();
    device.addDepthStream();
    device.addImageStream();
    device.addHandsTracker();
    device.addUserTracker();
    device.start();
    
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){
    device.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    device.draw();
    
	int y = ofGetHeight() - 10;
	int dy = 20;
    ostringstream os;
    os << "FPS: " << ofGetFrameRate();
    ofDrawBitmapString( os.str(), 20, y );
	y -= dy;
	ofDrawBitmapString( std::string("Users: "+std::string(device.isUsersOn()?"ON":"OFF")), 20, y );
	y -= dy;
	ofDrawBitmapString( std::string("Hands: "+std::string(device.isHandsOn()?"ON":"OFF")), 20, y );
	y -= dy;
	ofDrawBitmapString( std::string("Image: "+std::string(device.isImageOn()?"ON":"OFF")), 20, y );
	y -= dy;
	ofDrawBitmapString( std::string("Depth: "+std::string(device.isDepthOn()?"ON":"OFF")), 20, y );

	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}