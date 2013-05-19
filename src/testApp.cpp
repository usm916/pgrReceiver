#include "testApp.h"

#include "ofxPublishScreen.h"

ofxPublishScreen::Subscriber subs;
ofImage image;

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(30);
    bSmooth = false;
	ofSetWindowTitle("PublishScreenReceiver to Syphon");
    
	mainOutputSyphonServer.setName("Screen Output");
    
    loadFile("ini.txt");
	subs.setup(address, portNum);
}

//--------------------------------------------------------------
void testApp::update()
{
	subs.update();
	if (subs.isFrameNew())
	{
		image.setFromPixels(subs.getPixelsRef());
	}
	
	ofSetWindowTitle("PublishScreenReceiver to Syphon | fps: " + ofToString(subs.getFps(), 2));
}

//--------------------------------------------------------------
void testApp::draw()
{
	if (image.isAllocated())
		image.draw(0, 0);
    
    mainOutputSyphonServer.publishScreen();

}

//-----------------------------------------------------------------------------
void testApp::loadFile(string objFileName){
    ifstream fin; //declare a file stream
    fin.open( ofToDataPath(objFileName).c_str() ); //open your text file
    if(!fin.is_open()){
        stringstream ss;
        ss.str("");
        ss << "Faled to import ini file";
        ofDrawBitmapString(ss.str(), 50,50);
        cout << "faled to open the file.\nCheck your ini.txt" << endl;
        cout << "setted address to\nurl: localhost\nport: 20000" << endl;
        address = "localhost";
        portNum = 20000;
    }
    
    while(fin!=NULL) //as long as theres still text to be read
    {
        string str; //declare a string for storage
        stringstream sstr;
        sstr.str("");
        getline(fin, str); //get a line from the file, put it in the string
        sstr << str;
        string typ;
        string adr;
        char c;
        sstr >> typ >> adr;
        if(typ=="url"){
            address = adr;
            cout << "url: " << adr << endl;
        }
        if(typ=="port"){
            portNum = ofToInt(adr);
            cout << "port: " << adr << endl;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}