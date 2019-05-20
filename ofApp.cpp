#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2.5);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	auto radius = 300;
	for (auto i = 0; i < 10; i++) {

		vector<glm::vec2> vertices;
		for (auto deg = 0; deg < 360; deg += 1) {

			auto base_location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			auto noise_radius = ofMap(ofNoise(base_location.x * 0.005, base_location.y * 0.005, (ofGetFrameNum() - i * 10) * 0.01), 0, 1, radius * 0.5, radius * 1.0);
			auto location = glm::vec2(noise_radius * cos(deg * DEG_TO_RAD), noise_radius * sin(deg * DEG_TO_RAD));

			vertices.push_back(location);
		}

		ofFill();
		ofSetColor(239);
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);

		ofNoFill();
		ofSetColor(39);
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}