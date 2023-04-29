//
//  SmartlookCBridge.h
//  Smartlook iOS SDK 1.2.0
//
//  Copyright © 2019 Smartsupp.com, s.r.o. All rights reserved.
//

#pragma once

typedef void (*DashboardUrlCallback)(const char* url);

#if defined __cplusplus
extern "C" {
#endif
	void SmartlookSetupAndStartRecording(const char* key);
	void SmartlookSetupAndStartRecordingWithFramerate(const char* key, int framerate);
	void SmartlookSetupAndStartRecordingWithOptions(const char* options);
	void SmartlookSetup(const char* key);
	void SmartlookSetupWithFramerate(const char* key, int framerate);
	void SmartlookSetupWithOptions(const char* options);
	void SmartlookStartRecording();
	void SmartlookStopRecording();
	void SmartlookStartFullscreenSensitiveMode();
	void SmartlookStopFullscreenSensitiveMode();
	void SmartlookSetReferrer(const char* referrer, const char* source);
	void SmartlookTrackCustomEvent(const char* eventName);
	void SmartlookTrackCustomEventWithProperties(const char* eventName, const char* properties);
	void SmartlookTrackNavigationEvent(const char* screenName, int direction);
	void SmartlookSetUserIdentifier(const char* userIdentifier);
	void SmartlookSetUserIdentifierWithProperties(const char* userIdentifier, const char* properties);
	bool SmartlookIsRecording();
	const char* SmartlookGetDashboardSessionUrl();
	const char* SmartlookGetDashboardVisitorUrl();
	void SmartlookEnableCrashlytics(bool enable);
	const char* SmartlookStartTimedCustomEvent(const char* eventName);
	const char* SmartlookStartTimedCustomEventWithProperties(const char* eventName, const char* properties);
	void SmartlookStopTimedCustomEvent(const char* eventId);
	void SmartlookStopTimedCustomEventWithProperties(const char* eventId, const char* properties);
	void SmartlookCancelTimedCustomEvent(const char* eventId, const char* reason);
	void SmartlookCancelTimedCustomEventWithProperties(const char* eventId, const char* reason, const char* properties);
	void SmartlookSetGlobalEventProperty(const char* key, const char* value, bool immutable);
	void SmartlookSetGlobalEventProperties(const char* properties, bool immutable);
	void SmartlookRemoveGlobalEventProperty(const char* key);
	void SmartlookRemoveAllGlobalEventProperties();
	void SmartlookResetSession(bool resetUser);
	void SmartlookSetRenderingMode(int renderingMode); // native = 0, no rendering = 1
	void SmartlookSetEventTrackingMode(const char* eventTrackingMode);
	void SmartlookSetEventTrackingModes(const char* eventTrackingModes);

	typedef void (*DashboardUrlCallback)(const char* url);
	void SmartlookSetDashboardSessionUrlListener(DashboardUrlCallback callback);
	void SmartlookSetDashboardVisitorUrlListener(DashboardUrlCallback callback);
	void SmartlookUnregisterDashboardListener();
	
#if defined __cplusplus
};
#endif
