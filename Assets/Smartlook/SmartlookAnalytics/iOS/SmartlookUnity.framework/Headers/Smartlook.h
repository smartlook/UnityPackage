//
//  Smartlook.h
//  Smartlook iOS SDK
//
//  Copyright © 2020 Smartsupp.com, s.r.o. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreVideo/CoreVideo.h>
#import <QuartzCore/QuartzCore.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <WebKit/WebKit.h>

extern NSString * const _Nonnull SMARTLOOK_VERSION;
extern NSString * const _Nonnull SMARTLOOK_BUILD_ID;

#define SL_COMPATIBILITY_NAME(...)

NS_SWIFT_NAME(Smartlook.SensitiveData)
/**
 Convenience protocol to "flag" classes that present sensitive data.
 */
@protocol SLSensitiveData
@end

NS_SWIFT_NAME(Smartlook.NotSensitiveData)
/**
 Convenience protocol to "flag" classes that present nonsensitive data.
 */
@protocol SLNonSensitiveData
@end

// Smartlook SDK. To use, call "setupWithKey:" and "startRecording" methods from "applicationDidFinishLaunching:withOptions:" in your AppDelegate class

/// Smartlook public interface
@interface Smartlook : NSObject

// MARK: Setup

NS_SWIFT_NAME(Smartlook.SetupOptionKey)
typedef NSString * SLSetupOptionKey NS_TYPED_ENUM;
extern SLSetupOptionKey const _Nonnull SLSetupOptionFramerateKey NS_SWIFT_NAME(framerate);
extern SLSetupOptionKey const _Nonnull SLSetupOptionEnableCrashyticsKey NS_SWIFT_NAME(enableCrashytics);
extern SLSetupOptionKey const _Nonnull SLSetupOptionUseAdaptiveFramerateKey NS_SWIFT_NAME(useAdaptiveFramerate);
extern SLSetupOptionKey const _Nonnull SLSetupOptionAnalyticsOnlyKey NS_SWIFT_NAME(analyticsOnly);
extern SLSetupOptionKey const _Nonnull SLSetupOptionEventTrackingModesKey NS_SWIFT_NAME(eventTrackingModes);
//
extern SLSetupOptionKey const _Nonnull SLSetupOptionRenderingModeKey NS_SWIFT_NAME(renderingMode);
extern SLSetupOptionKey const _Nonnull SLSetupOptionRenderingModeOptionsKey NS_SWIFT_NAME(renderingModeOptions);
//
extern SLSetupOptionKey const _Nonnull SLSetupOptionStartNewSessionKey NS_SWIFT_NAME(startNewSession);
extern SLSetupOptionKey const _Nonnull SLSetupOptionStartNewSessionAndResetUserKey NS_SWIFT_NAME(startNewSessionAndResetUser);
//
extern SLSetupOptionKey const _Nonnull SLSetupOptionRequestHeaderFiltersKey NS_SWIFT_NAME(requestHeaderFilters);
extern SLSetupOptionKey const _Nonnull SLSetupOptionURLPatternFiltersKey NS_SWIFT_NAME(urlPatternFilters);
extern SLSetupOptionKey const _Nonnull SLSetupOptionURLQueryParamFiltersKey NS_SWIFT_NAME(urlQueryParamFilters);

NS_SWIFT_NAME(Smartlook.RenderingMode)
typedef NSString * SLRenderingMode NS_TYPED_ENUM;
extern SLRenderingMode const _Nonnull SLRenderingModeNative NS_SWIFT_NAME(native);
extern SLRenderingMode const _Nonnull SLRenderingModeWireframe NS_SWIFT_NAME(wireframe);
extern SLRenderingMode const _Nonnull SLRenderingModeNoRendering NS_SWIFT_NAME(noRendering);

NS_SWIFT_NAME(Smartlook.RenderingModeOption)
typedef NSString * SLRenderingModeOption NS_TYPED_ENUM;
extern SLRenderingModeOption const _Nonnull SLRenderingModeOptionNone NS_SWIFT_NAME(none);
extern SLRenderingModeOption const _Nonnull SLRenderingModeOptionColorWireframe NS_SWIFT_NAME(colorWireframe);
extern SLRenderingModeOption const _Nonnull SLRenderingModeOptionBlueprintWireframe NS_SWIFT_NAME(blueprintWireframe);
extern SLRenderingModeOption const _Nonnull SLRenderingModeOptionIconBlueprintWireframe NS_SWIFT_NAME(iconBlueprintWireframe);

NS_SWIFT_NAME(Smartlook.EventTrackingMode)
typedef NSString * SLEventTrackingMode NS_TYPED_ENUM;
extern SLEventTrackingMode const _Nonnull SLEventTrackingModeFullTracking NS_SWIFT_NAME(fullTracking);
extern SLEventTrackingMode const _Nonnull SLEventTrackingModeIgnoreUserInteractionEvents NS_SWIFT_NAME(ignoreUserInteractionEvents);
extern SLEventTrackingMode const _Nonnull SLEventTrackingModeIgnoreNavigationInteractionEvents NS_SWIFT_NAME(ignoreNavigationInteractionEvents);
extern SLEventTrackingMode const _Nonnull SLEventTrackingModeIgnoreRageClickEvents NS_SWIFT_NAME(ignoreRageClickEvents);
extern SLEventTrackingMode const _Nonnull SLEventTrackingModeNoTracking NS_SWIFT_NAME(noTracking);

// Dashboard URL change notification
extern NSNotificationName const _Nonnull SLDashboardSessionURLChangedNotification NS_SWIFT_NAME(Smartlook.dashboardSessionURLChanged);
extern NSNotificationName const _Nonnull SLDashboardVisitorURLChangedNotification NS_SWIFT_NAME(Smartlook.dashboardVisitorURLChanged);

/**
 Setup Smartlook.
 
 Call this method once in your `applicationDidFinishLaunching:withOptions:`.
 
 - Attention: This method initializes Smartlook SDK, but does not start recording. To start recording, call `startRecording` method.
 
 @param key The application (project) specific SDK key, available in your Smartlook dashboard.
 */
+(void)setupWithKey:(nonnull NSString *)key;
SL_COMPATIBILITY_NAME("name=setup;type=func;params=smartlookAPIKey{string}")

/**
Setup and start Smartlook.

Call this method once in your `applicationDidFinishLaunching:withOptions:`.

This method initializes Smartlook SDK and starts it in one step.

@param key The application (project) specific SDK key, available in your Smartlook dashboard.
*/
+(void)setupAndStartRecordingWithKey:(nonnull NSString *)key NS_SWIFT_NAME(setupAndStartRecording(key:));
SL_COMPATIBILITY_NAME("name=setupAndStartRecording;type=func;params=smartlookAPIKey{string}")


/**
 Setup Smartlook.
 
 Call this method once in your `applicationDidFinishLaunching:withOptions:`.

 - Attention: This method initializes Smartlook SDK, but does not start recording. To start recording, call `startRecording` method.
 
 @param key The application (project) specific SDK key, available in your Smartlook dashboard.
 @param options (optional) Startup options.
 */
+(void)setupWithKey:(nonnull NSString *)key options:(nullable NSDictionary<SLSetupOptionKey,id> *)options NS_SWIFT_NAME(setup(key:options:));
SL_COMPATIBILITY_NAME("name=setup;type=func;params=smartlookAPIKey{string},setupOptions{Dictionary[SetupOption:any]}")

/**
Setup and start Smartlook.

Call this method once in your `applicationDidFinishLaunching:withOptions:`.

This method both initializes Smartlook SDK and starts recording.

@param key The application (project) specific SDK key, available in your Smartlook dashboard.
@param options (optional) Startup options.
*/
+(void)setupAndStartRecordingWithKey:(nonnull NSString *)key options:(nullable NSDictionary<SLSetupOptionKey,id> *)options NS_SWIFT_NAME(setupAndStart(key:options:));
SL_COMPATIBILITY_NAME("name=setupAndStartRecording;type=func;params=smartlookAPIKey{string},setupOptions{Dictionary[SetupOption:any]}")

// MARK: Reset session

/**
Reset Session

This method resets the current session by implicitelly starting a new one. Optionally, it also resets the user.

- Attention: Each session is tied to a particular user, i.e., to reset user, new session must be created as a consequence.

@param resetUser Indicates, whether new session starts with new user, too.
*/
+ (void)resetSessionAndUser:(BOOL)resetUser NS_SWIFT_NAME(resetSession(resetUser:));
SL_COMPATIBILITY_NAME("name=resetSession;type=func;params=resetUser{boolean}")

// MARK: Start/Stop Recording

/** Starts video and events recording.
 */
+ (void)startRecording;
SL_COMPATIBILITY_NAME("name=startRecording;type=func")

/** Stops video and events recording.
 */
+ (void)stopRecording;
SL_COMPATIBILITY_NAME("name=stopRecording;type=func")

/** Current video and events recording state.
 */
+ (BOOL)isRecording;
SL_COMPATIBILITY_NAME("name=isRecording;type=func;returns=boolean")


// MARK: Switch Rendering Mode

/**
 Switches the rendering mode. This can be done any time, no need to stop or start recording for it. Rendering mode can be also set as a setup option. If none is explicitly provided, `native`, the most universal mode, is used.
 */
+ (void)setRenderingModeTo:(nonnull SLRenderingMode)renderingMode NS_SWIFT_NAME(setRenderingMode(to:));
SL_COMPATIBILITY_NAME("name=setRenderingMode;type=func;params=renderingMode{RenderingMode}")

/**
 Switches the rendering mode with optional option. This can be done any time, no need to stop or start recording for it. Rendering mode can be also set as a setup option. If none is explicitly provided, `native`, the most universal mode, is used.
 */
+ (void)setRenderingModeTo:(nonnull SLRenderingMode)renderingMode withOption:(nullable SLRenderingModeOption)renderingModeOption NS_SWIFT_NAME(setRenderingMode(to:option:));
SL_COMPATIBILITY_NAME("name=setRenderingMode;type=func;params=renderingMode{RenderingMode},renderingModeOption{RenderingModeOption}")

/// Returns the current rendering mode.
+ (_Nonnull SLRenderingMode)currentRenderingMode;
SL_COMPATIBILITY_NAME("name=currentRenderingMode;type=func;returns=RenderingMode")

/// Returns current rendering mode option
+ (_Nullable SLRenderingModeOption)currentRenderingModeOption;
SL_COMPATIBILITY_NAME("name=currentRenderingModeOption;type=func;returns=RenderingModeOption")

// MARK: Events Tracking Mode

/**
 Switches the event tracking mode.
 
 This can be done any time, no need to stop or start recording for it. Event tracking mode can be also set as a setup option. If none is explicitly provided, `fullTracking` is used.
 */
+ (void)setEventTrackingModeTo:(SLEventTrackingMode _Nonnull)eventTrackingMode NS_SWIFT_NAME(setEventTrackingMode(to:));
SL_COMPATIBILITY_NAME("name=setEventTrackingMode;type=func;params=eventTrackingMode{EventTrackingMode}")

/**
 Switches the event tracking mode.
 
 This can be done any time, no need to stop or start recording for it. Event tracking mode can be also set as a setup option. If none is explicitly provided, `fullTracking` is used.
 */
+ (void)setEventTrackingModesTo:(NSArray<SLEventTrackingMode> * _Nonnull)eventTrackingModes NS_SWIFT_NAME(setEventTrackingModes(to:));
SL_COMPATIBILITY_NAME("name=setEventTrackingModes;type=func;params=eventTrackingModes{List[EventTrackingMode]}")

// Returns the currently set event tracking mode.
+ (nonnull NSArray<SLEventTrackingMode> *)currentEventTrackingModes;
SL_COMPATIBILITY_NAME("name=currentEventTrackingModes;type=func;returns=List[EventTrackingMode]")

// MARK: Custom Events

/**
 Records timestamped custom event with optional properties.
 
 @param eventName Name that identifies the event.
 @param props Optional dictionary with additional information. Non String values will be stringified.
 */
+ (void)trackCustomEventWithName:(nonnull NSString*)eventName props:(nullable NSDictionary<NSString*, NSString*>*)props NS_SWIFT_NAME(trackCustomEvent(name:props:));
SL_COMPATIBILITY_NAME("name=trackCustomEvent;type=func;params=eventName{string}")
SL_COMPATIBILITY_NAME("name=trackCustomEvent;type=func;params=eventName{string},eventProperties{Dictionary[string:string]}")

/**
 Start timer for custom event.
 
 This method does not record an event. It is the subsequent `stopTimedEvent` or `cancelTimedCustomEvent` call that refers to the `id` returned by this call that does record an event.
 
 In the resulting event, the property dictionaries of `start` and `record` are merged (the `record` values override the `start` ones if the key is the same), and a `duration` property is added to them.
 
 @param eventName Name of the event.
 @param props Optional dictionary with additional information.  Non String values will be stringified.
 @return return opaque event identifier
 */
+ (id _Nonnull)startTimedCustomEventWithName:(nonnull NSString*)eventName props:(nullable NSDictionary<NSString*, NSString*>*)props NS_SWIFT_NAME(startTimedCustomEvent(name:props:));
SL_COMPATIBILITY_NAME("name=startTimedCustomEvent;type=func;params=eventName{string};returns=string")
SL_COMPATIBILITY_NAME("name=startTimedCustomEvent;type=func;params=eventName{string},eventProperties{Dictionary[string:string]};returns=string")


/**
 Tracks custom times event.
 
 This method tracks a custom timed event created by a `startTimedCustomEvent` call. The event is identified by an opaque event reference returned by the respective `startTimedCustomEvent`.

 In the resulting event, the property dictionaries of `start` and `record` are merged (the `record` values override the `start` ones if the key is the same), and a `duration` property is added to them.
 
 @param eventId event identifier as returned by the corresponding `startTimedCustomEvent`
 @param props Optional dictionary with additional information.  Non String values will be stringified.
 */
+ (void)trackTimedCustomEventWithEventId:(id _Nonnull)eventId props:(nullable NSDictionary<NSString*, NSString*>*)props NS_SWIFT_NAME(trackTimedCustomEvent(eventId:props:));
SL_COMPATIBILITY_NAME("name=stopTimedCustomEvent;type=func;params=eventId{string},eventProperties{Dictionary[string:string]}")

/**
 Track canceling of a custom times event.
 
 This method tracks cancellation of a custom timed event created by a `startTimedCustomEvent` call. The event is identified by an opaque event reference returned by the respective `startTimedCustomEvent`.
 
 The cancellation reason can be provided in the `reason` parameter.
 
 In the resulting event, the property dictionaries of `start` and `record` are merged (the `record` values override the `start` ones if the key is the same), and a `duration` property is added to them.
 
 @param eventId event identifier as returned by the corresponding `startTimedCustomEvent`
 @param reason Optional string that describes the reason for the cancelation.
 @param props Optional dictionary with additional information.  Non String values will be stringified.
 */
+ (void)trackTimedCustomEventCancelWithEventId:(id _Nonnull)eventId reason:(NSString *_Nullable)reason props:(nullable NSDictionary<NSString*, NSString*>*)props NS_SWIFT_NAME(trackTimedCustomEventCancel(eventId:reason:props:));
SL_COMPATIBILITY_NAME("name=cancelTimedCustomEvent;type=func;params=eventId{string},reason{string}")
SL_COMPATIBILITY_NAME("name=cancelTimedCustomEvent;type=func;params=eventId{string},reason{string},eventProperties{Dictionary[string:string]}")


// MARK: - Session and Global Event Properties

/** Set the app's user identifier.
 @param userIdentifier The application-specific user identifier.
 */
+ (void)setUserIdentifier:(nullable NSString*)userIdentifier;
SL_COMPATIBILITY_NAME("name=setUserIdentifier;type=func;params=identifier{string}")


NS_SWIFT_NAME(Smartlook.PropertyOption)
/**
 Smartlook property options

 - SLPropertyOptionDefaults: the default value
 - SLPropertyOptionImmutable: the property is immutable. To change it, remove it first.
 */
typedef NS_OPTIONS(NSUInteger, SLPropertyOption) {
    SLPropertyOptionDefaults    = 0,
    SLPropertyOptionImmutable   = 1 << 0
};

/**
 Custom session properties. You will see these properties in the Dashboard at Visitor details.

 @param value the property value
 @param name the property name
 */
+ (void)setSessionPropertyValue:(nonnull NSString *)value forName:(nonnull NSString *)name NS_SWIFT_NAME(setSessionProperty(value:forName:));

/**
 Custom session properties. You will see these properties in the Dashboard at Visitor details.

 @param value the property value
 @param name the property name
 @param options how the property is managed
 */
+ (void)setSessionPropertyValue:(nonnull NSString *)value forName:(nonnull NSString *)name withOptions:(SLPropertyOption)options NS_SWIFT_NAME(setSessionProperty(value:forName:options:));
SL_COMPATIBILITY_NAME("name=setUserProperty;type=func;params=key{string},value{string},immutable{boolean}")

/**
 Removes custom session property.

 @param name the property name
 */
+ (void)removeSessionPropertyForName:(nonnull NSString *)name NS_SWIFT_NAME(removeSessionProperty(forName:));

/**
 Removes all the custom session properties.
 */
+ (void)clearSessionProperties;


/**
 Global event properties are sent with every event.

 @param value the property value
 @param name the property name
 */
+ (void)setGlobalEventPropertyValue:(nonnull NSString *)value forName:(nonnull NSString *)name NS_SWIFT_NAME(setGlobalEventProperty(value:forName:));

/**
 Global event properties are sent with every event.

 @param value  the property value
 @param name  the property name
 @param options  how the property is managed
 */
+ (void)setGlobalEventPropertyValue:(nonnull NSString *)value forName:(nonnull NSString *)name withOptions:(SLPropertyOption)options NS_SWIFT_NAME(setGlobalEventProperty(value:forName:options:));
SL_COMPATIBILITY_NAME("name=setGlobalEventProperty;type=func;params=key{string},value{string},immutable{boolean}")

/**
 Removes global event property so it is no longer sent with every event.

 @param name the property name
 */
+ (void)removeGlobalEventPropertyForName:(nonnull NSString *)name NS_SWIFT_NAME(removeGlobalEventProperty(forName:));
SL_COMPATIBILITY_NAME("name=removeGlobalEventProperty;type=func;params=key{string}")

/**
 Removes all global event properties so they are no longer sent with every event.
 */
+ (void)clearGlobalEventProperties;
SL_COMPATIBILITY_NAME("name=clearGlobalEventProperties;type=func")

// MARK: - Sensitive Views

/**
 Default colour of blacklisted view overlay

 @param color overlay colour
 */
+ (void)setBlacklistedItemsColor:(nonnull UIColor *)color NS_SWIFT_NAME(setBlacklistedItem(color:));
SL_COMPATIBILITY_NAME("name=setBlacklistedItemsColor;type=func;params=color{color}")

/**
 Use to exempt a view from being ovelayed in video recording as containting sensitive data.
 
 By default, all instances of `UITextView`, `UITextField` and `WKWebView` are blacklisted.

 See online documentation for detailed blacklisting/whitelisting documentation.
 
 @param object an instance of UIView, an UIView subclass or a Protocol reference
 */
+ (void)registerWhitelistedObject:(nonnull id)object NS_SWIFT_NAME(registerWhitelisted(object:));
SL_COMPATIBILITY_NAME("name=registerWhitelistedView;type=func;params=whitelistedView{View}")

/**
 Use to stop whitelisting an object. Whitelisted objects are exempted from being ovelayed in video recording as containting sensitive data.
 
 By default, all instances of `UITextView`, `UITextField` and `WKWebView` are blacklisted.
 
 See online documentation for detailed blacklisting/whitelisting documentation.
 
 @param object an instance of UIView, an UIView subclass or a Protocol reference
 */
+ (void)unregisterWhitelistedObject:(nonnull id)object NS_SWIFT_NAME(unregisterWhitelisted(object:));
SL_COMPATIBILITY_NAME("name=unregisterWhitelistedView;type=func;params=whitelistedView{View}")
SL_COMPATIBILITY_NAME("name=unregisterWhitelistedClass;type=func;params=blacklistedClass{Class}")

/**
 Add an object to the blacklist. Blacklisted objects are ovelayed in video recording.
 
 By default, all instances of `UITextView`, `UITextField` and `WKWebView` are blacklisted.
 
 See online documentation for detailed blacklisting/whitelisting documentation.
 
 @param object an instance of UIView, an UIView subclass or a Protocol reference
 */
+ (void)registerBlacklistedObject:(nonnull id)object NS_SWIFT_NAME(registerBlacklisted(object:));
SL_COMPATIBILITY_NAME("name=registerBlacklistedClass;type=func;params=blacklistedClass{Class}")
SL_COMPATIBILITY_NAME("name=registerBlacklistedView;type=func;params=blacklistedView{View}")

/**
 Remove an object from the blacklist. Blacklisted objects are ovelayed in video recording.
 
 By default, all instances of `UITextView`, `UITextField` and `WKWebView` are blacklisted.
 
 See online documentation for detailed blacklisting/whitelisting documentation.
 
 @param object an instance of UIView, an UIView subclass or a Protocol reference
 */
+ (void)unregisterBlacklistedObject:(nonnull id)object NS_SWIFT_NAME(unregisterBlacklisted(object:));
SL_COMPATIBILITY_NAME("name=unregisterBlacklistedView;type=func;params=blacklistedView{View}")
SL_COMPATIBILITY_NAME("name=unregisterBlacklistedClass;type=func;params=blacklistedClass{Class}")

// MARK: - Dashboard session URL
/**
 URL leading to the Dashboard player for the current Smartlook session. This URL can be access by users with the access rights to the dashboard.

 @param withTimestamp decides the URL points to the current moment in the recording
 
 @return current session recording Dashboard URL
 */
+ (nullable NSURL *)getDashboardSessionURLWithCurrentTimestamp:(BOOL)withTimestamp NS_SWIFT_NAME(getDashboardSessionURL(withCurrentTimestamp:));
SL_COMPATIBILITY_NAME("name=getDashboardSessionUrl;type=func;params=withCurrentTimestamp{boolean};returns=url")

/**
 URL leading to the Dashboard landing page of the current visitor. This URL can be access by users with the access rights to the dashboard.

 @return the current visitor Dashboard URL
 */
+ (nullable NSURL *)getDashboardVisitorURL;
SL_COMPATIBILITY_NAME("name=getDashboardVisitorUrl;type=func;returns=url")

// MARK: - Custom navigation events

 NS_SWIFT_NAME(Smartlook.NavigationEventType)
 typedef NSString * SLNavigationType NS_TYPED_ENUM;
 extern SLNavigationType const _Nonnull SLNavigationTypeEnter NS_SWIFT_NAME(enter);
 extern SLNavigationType const _Nonnull SLNavigationTypeExit NS_SWIFT_NAME(exit);
 
 + (void)trackNavigationEventWithControllerId:(nonnull NSString *)controllerId type:(nonnull SLNavigationType)type NS_SWIFT_NAME(trackNavigationEvent(withControllerId:type:));
SL_COMPATIBILITY_NAME("name=trackNavigationEvent;type=func;params=name{string},viewState{ViewState}")

/**
 D E P R E C A T E D
 */

// MARK: - Full Sensitive Mode

/**
 Use this method to enter the **full sensitive mode**. No video is recorded, just events.
 */
+ (void)beginFullscreenSensitiveMode DEPRECATED_MSG_ATTRIBUTE("use a suitable combination of rendering and event tracking mode instead.");
SL_COMPATIBILITY_NAME("name=startFullscreenSensitiveMode;type=func;deprecated=yes")

/**
 Use this method to leave the **full sensitive mode**. Video is recorded again.
 */
+ (void)endFullscreenSensitiveMode DEPRECATED_MSG_ATTRIBUTE("use a suitable combination of rendering and event tracking mode instead.");
SL_COMPATIBILITY_NAME("name=stopFullscreenSensitiveMode;type=func;deprecated=yes")

/**
 To check Smartlook full sensitive mode status. In full sensitive mode, no video is recorded, just events.

 @return fullscreen sensitive mode state
 */
+ (BOOL)isFullscreenSensitiveModeActive DEPRECATED_MSG_ATTRIBUTE("use a suitable combination of rendering and event tracking mode instead.");
SL_COMPATIBILITY_NAME("name=isFullscreenSensitiveModeActive;type=func;returns=boolean;deprecated=yes")


// MARK: - Other stuff

+ (nullable NSURL *)getDashboardSessionURL DEPRECATED_MSG_ATTRIBUTE("use `getDashboardSessionURLWithCurrentTimestamp` instead.");
SL_COMPATIBILITY_NAME("name=getDashboardSessionUrl;type=func;returns=url;deprecated=yes")

@end

/** Defines inspectable properties on UIView
 */
@interface UIView (Smartlook)

/** Flags UIView instance as sensitive. For UIViews that are `UITextView`, `UITextField` and `WKWebView`, the default value is `YES`. Otherwise, the default value is `NO`.
 */
@property (nonatomic, assign) IBInspectable BOOL slSensitive;

/** Setting colour of sensitive view overlay. Views flagged as sensitive are replaced by solid color rectangles of this color. Alpha channel of the color is ignored. The default value is `black`.
 */
@property (nonatomic, strong) IBInspectable UIColor *slOverlay;

@end
