//
//  Smartlook SDK, © 2022 Smartlook.com
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class SLSetupConfiguration;
@class SLIntegration;


// MARK: - Enumerations

typedef NSString * SLNavigationType NS_TYPED_ENUM;
static SLNavigationType const _Nonnull SLNavigationTypeEnter = @"enter";
static SLNavigationType const _Nonnull SLNavigationTypeExit = @"exit";

typedef NSString * SLRenderingMode NS_TYPED_ENUM;
static SLRenderingMode const _Nonnull SLRenderingModeNative = @"rendering-method-native";
static SLRenderingMode const _Nonnull SLRenderingModeWireframe = @"rendering-method-wireframe";
static SLRenderingMode const _Nonnull SLRenderingModeNoRendering = @"no-rendering";

typedef NSString * SLRenderingModeOption NS_TYPED_ENUM;
static SLRenderingModeOption const _Nonnull SLRenderingModeOptionNone = @"rendering-method-option-none";
static SLRenderingModeOption const _Nonnull SLRenderingModeOptionColorWireframe = @"rendering-method-option-color-wireframe";
static SLRenderingModeOption const _Nonnull SLRenderingModeOptionBlueprintWireframe = @"rendering-method-option-blueprint-wireframe";
static SLRenderingModeOption const _Nonnull SLRenderingModeOptionIconBlueprintWireframe = @"rendering-method-option-icon-blueprint-wireframe";

typedef NSString * SLEventTrackingMode NS_TYPED_ENUM;
static SLEventTrackingMode const _Nonnull SLEventTrackingModeFullTracking = @"event-tracking-mode-full";
static SLEventTrackingMode const _Nonnull SLEventTrackingModeIgnoreUserInteractionEvents = @"event-tracking-mode-ignore-user-interaction";
static SLEventTrackingMode const _Nonnull SLEventTrackingModeNoTracking = @"event-tracking-mode-no-tracking";
static SLEventTrackingMode const _Nonnull SLEventTrackingModeIgnoreNavigationInteractionEvents = @"event-tracking-mode-ignore-navigation-interaction-events";
static SLEventTrackingMode const _Nonnull SLEventTrackingModeIgnoreRageClickEvents = @"event-tracking-mode-ignore-rage-click-events";

typedef NSString * SLRegion NS_TYPED_ENUM;
static SLRegion const _Nonnull SLRegionEU = @"eu";
static SLRegion const _Nonnull SLRegionUS = @"us";

// MARK: - Dashboard URL change notification
static NSNotificationName const _Nonnull SLDashboardSessionURLChangedNotification = @"dashboard-session-URL-changed-notification";
static NSNotificationName const _Nonnull SLDashboardVisitorURLChangedNotification = @"dashboard-visitor-URL-changed-notification";

// MARK: - Bridge technologies
typedef NSString * SLBridgeTechnology NS_TYPED_ENUM;
static SLBridgeTechnology const _Nonnull SLBridgeTechnologyReactNative = @"react_native";
static SLBridgeTechnology const _Nonnull SLBridgeTechnologyFlutter = @"flutter";
static SLBridgeTechnology const _Nonnull SLBridgeTechnologyCordova = @"cordova";
static SLBridgeTechnology const _Nonnull SLBridgeTechnologyIonic = @"ionic";
static SLBridgeTechnology const _Nonnull SLBridgeTechnologyUnity = @"unity";
static SLBridgeTechnology const _Nonnull SLBridgeTechnologyUnreal = @"unreal";
static SLBridgeTechnology const _Nonnull SLBridgeTechnologyXamarin = @"xamarin";
static SLBridgeTechnology const _Nonnull SLBridgeTechnologyOther = @"other";


// MARK: - Smartlook

@interface Smartlook : NSObject


// MARK: - Setup

+ (void)setupWithConfiguration:(nonnull SLSetupConfiguration *)configuration;

+ (void)setupAndStartRecordingWithConfiguration:(nonnull SLSetupConfiguration *)configuration;


// MARK: - Reset session

+ (void)resetSessionAndUser:(BOOL)resetUser;


// MARK: - Start/Stop Recording

+ (void)startRecording;

+ (void)stopRecording;

+ (BOOL)isRecording;


// MARK: - Switch Rendering Mode

+ (void)setRenderingModeTo:(nonnull SLRenderingMode)renderingMode;

+ (void)setRenderingModeTo:(nonnull SLRenderingMode)renderingMode withOption:(nullable SLRenderingModeOption)renderingModeOption;

+ (_Nonnull SLRenderingMode)currentRenderingMode;

+ (_Nullable SLRenderingModeOption)currentRenderingModeOption;


// MARK: - Events Tracking Mode


+ (void)setEventTrackingModeTo:(SLEventTrackingMode _Nonnull)eventTrackingMode;

+ (void)setEventTrackingModesTo:(NSArray<SLEventTrackingMode> * _Nonnull)eventTrackingModes;

+ (nonnull NSArray<SLEventTrackingMode> *)currentEventTrackingModes;


// MARK: - Custom Events

+ (void)trackCustomEventWithName:(nonnull NSString*)eventName;

+ (void)trackCustomEventWithName:(nonnull NSString*)eventName props:(nullable NSDictionary<NSString*, NSString*>*)props;

+ (id _Nonnull)startTimedCustomEventWithName:(nonnull NSString*)eventName props:(nullable NSDictionary<NSString*, NSString*>*)props;

+ (void)trackTimedCustomEventWithEventId:(id _Nonnull)eventId props:(nullable NSDictionary<NSString*, NSString*>*)props;

+ (void)trackTimedCustomEventCancelWithEventId:(id _Nonnull)eventId reason:(NSString *_Nullable)reason props:(nullable NSDictionary<NSString*, NSString*>*)props;


// MARK: - Session and Global Event Properties

+ (void)setUserIdentifier:(nullable NSString*)userIdentifier;

typedef NS_OPTIONS(NSUInteger, SLPropertyOption) {
    SLPropertyOptionDefaults    = 0,
    SLPropertyOptionImmutable   = 1 << 0
};

+ (void)setSessionPropertyValue:(nonnull NSString *)value forName:(nonnull NSString *)name;

+ (void)setSessionPropertyValue:(nonnull NSString *)value forName:(nonnull NSString *)name withOptions:(SLPropertyOption)options;

+ (void)removeSessionPropertyForName:(nonnull NSString *)name;

+ (void)clearSessionProperties;

+ (void)setGlobalEventPropertyValue:(nonnull NSString *)value forName:(nonnull NSString *)name;

+ (void)setGlobalEventPropertyValue:(nonnull NSString *)value forName:(nonnull NSString *)name withOptions:(SLPropertyOption)options;

+ (void)removeGlobalEventPropertyForName:(nonnull NSString *)name;

+ (void)clearGlobalEventProperties;


// MARK: - Sensitive Views

+ (void)setBlacklistedItemsColor:(nonnull UIColor *)color;

+ (void)registerWhitelistedObject:(nonnull id)object;


+ (void)unregisterWhitelistedObject:(nonnull id)object;

+ (void)registerBlacklistedObject:(nonnull id)object;

+ (void)unregisterBlacklistedObject:(nonnull id)object;


// MARK: - Dashboard session URL

+ (nullable NSURL *)getDashboardSessionURLWithCurrentTimestamp:(BOOL)withTimestamp;

+ (nullable NSURL *)getDashboardVisitorURL;

+ (void)trackNavigationEventWithControllerId:(nonnull NSString *)controllerId type:(nonnull SLNavigationType)type;


// MARK: - Automated Integrations

+ (void)enableIntegrations:(NSArray<SLIntegration *> * _Nonnull)integrations;

+ (void)disableIntegrations:(NSArray<SLIntegration *> * _Nonnull)integrations;

+ (void)disableAllIntegrations;

+ (NSArray<SLIntegration *> *  _Nonnull)currentlyEnabledIntegrations;

@end


// MARK: - Setup Configuration

@interface SLSetupConfiguration : NSObject

@property (nonatomic, strong) NSString * _Nonnull apiKey;

@property (nonatomic) NSInteger framerate;

@property (nonatomic) BOOL enableAdaptiveFramerate;

@property (nonatomic, copy) NSArray<SLEventTrackingMode> * _Nullable eventTrackingModes;

@property (nonatomic, strong) SLRenderingMode _Nullable renderingMode;

@property (nonatomic, strong) SLRenderingModeOption _Nullable renderingModeOption;

@property (nonatomic) BOOL resetSession;

@property (nonatomic) BOOL resetSessionAndUser;

@property (nonatomic, strong) SLRegion _Nullable regionalStorage;

@property (nonatomic, strong) NSArray * _Nullable requestHeaderFilters;

@property (nonatomic, strong) NSDictionary * _Nullable urlPatternFilters;

@property (nonatomic, strong) NSArray * _Nullable URLQueryParamFilters;

@property (nonatomic, copy) NSArray<SLIntegration *> * _Nullable enableIntegrations;

- (instancetype _Nonnull)initWithKey:(NSString *_Nonnull)apiKey;

- (void)setInternalProps:(id _Nonnull)internalProps;

@end


// MARK: - Sensitivity Protocols

@protocol SLSensitiveData
@end

@protocol SLNonSensitiveData
@end


// MARK: - Bridge Interface

@interface SLWireframeDataItem : NSObject

@property CGFloat left;
@property CGFloat top;
@property CGFloat width;
@property CGFloat height;

@property (nonatomic, copy) UIColor * _Nonnull color;

@end


@interface SLWireframeData : NSObject

@property CGFloat width;
@property CGFloat height;

@property (nonatomic, copy) NSArray<SLWireframeDataItem *> * _Nonnull items;

@end


@protocol SLBridgeInterface <NSObject>

@property (nonatomic, copy) NSString * _Nullable sdkFramework;
@property (nonatomic, copy) NSString * _Nullable sdkFrameworkVersion;
@property (nonatomic, copy) NSString * _Nullable sdkFrameworkPluginVersion;


- (void)obtainWireframeDataWithCompletion:(void (^_Nonnull)(SLWireframeData * _Nullable result))completionHandler;

@end


@interface Smartlook (BridgeInterface)

+ (void)registerBridgeInterface:(NSObject<SLBridgeInterface> * _Nonnull)bridgeInterface;

@end


// MARK: - UIView category

@interface UIView (Smartlook)

@property (nonatomic, assign) IBInspectable BOOL slSensitive;

@end


// MARK: - Integrations

@interface SLIntegration : NSObject;

@property (nonatomic, nonnull, readonly) id integratedObject;
@property (nonatomic, nonnull, readonly) NSString *name;

@property (nonatomic, readonly) BOOL isValid;

@end


// MARK: - Firebase Crashlytics

static NSString * const _Nonnull SLIntegrationFirebaseCrashlyticsName = @"firebase_crashlytics";

@class FIRCrashlytics;

@interface SLFirebaseCrashlyticsIntegration : SLIntegration
- (instancetype _Nonnull)initIntegrationWith:(FIRCrashlytics *_Nonnull)crashlytics;
@end;


// MARK: - Firebase Analytics

static NSString * const _Nonnull SLIntegrationFirebaseAnalyticsName = @"firebase_analytics";

@interface SLFirebaseAnalyticsIntegration : SLIntegration
- (instancetype _Nonnull)initIntegrationWith:(Class _Nonnull)analyticsClass;
@end


// MARK: - Amplitude

extern NSString * const _Nonnull SLIntegrationAmplitudeName;

@class Amplitude;

@interface SLAmplitudeIntegration : SLIntegration
- (instancetype _Nonnull)initIntegrationWith:(Amplitude *_Nonnull)amplitudeInstance;
@end


// MARK: - Mixpanel

extern NSString * const _Nonnull SLIntegrationMixpanelName;

@class Mixpanel;

@interface SLMixpanelIntegration : SLIntegration
- (instancetype _Nonnull)initIntegrationWith:(Mixpanel *_Nonnull)mixpanelInstance;
@end


// MARK: - Heap

extern NSString * const _Nonnull SLIntegrationHeapName;

@interface SLHeapIntegration : SLIntegration
- (instancetype _Nonnull)initIntegrationWith:(Class _Nonnull)heapClass;
@end


// MARK: - Segment

@class SEGBlockMiddleware;


typedef NS_OPTIONS(NSUInteger, SLSegmentMiddlewareOption) {
    SLSegmentMiddlewareOptionTrack = 1 << 0,
    SLSegmentMiddlewareOptionScreen = 1 << 1,
    SLSegmentMiddlewareOptionIdentify = 1 << 2,
    SLSegmentMiddlewareOptionAlias = 1 << 3,
    SLSegmentMiddlewareOptionReset = 1 << 4,
    SLSegmentMiddlewareOptionAll = 0xFF,
    SLSegmentMiddlewareOptionDefault = SLSegmentMiddlewareOptionAll & ~SLSegmentMiddlewareOptionScreen & ~SLSegmentMiddlewareOptionAlias,
};

@interface Smartlook (Segment)

+(SEGBlockMiddleware * _Nullable)segmentSourceMiddlewareWithOptions:(SLSegmentMiddlewareOption)option whereSEGResetEventTypeIs:(NSInteger)resetEventType;

@end
